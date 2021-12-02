#include <iostream>
#include <cassert>
#include <iosfwd>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <limits>
#include <math.h>

using std::cout;
using std::cin;
using std::endl;
using std::setw;
using std::left;
using std::right;
using std::string;
using std::fstream;
using std::ifstream;

//Global Constants
const int NUMLABS = 8;
const int LABSIZES[NUMLABS] = {10, 15, 20, 25, 20, 15, 10, 5};

//Names of university of each lab
const string UNIVERSITYNAMES[NUMLABS] = {"The University of Michigan", "The University of Pittsburgh", "Stanford University",
                                        "Arizona State University", "North Texas State University", "The University of Alabama, Huntsville",
                                         "Princeton University", "Duquesne University"};

void initialDisplay(); //for initial University display
void mainMenu(); //for the main menu
bool validateInput(int, int, int); //used to validate inputs for login and logoff
void logIn(int **, string **, int **); //logs userID, name, and time into respective arrays and hold them in the array
void logOff(int **labPtr, string **namePtr, int **timePtr); //removes userID, name, and time from whatever station chosen
void look(int **labPtr); //searches for users location by ID
void display(int **labPtr);//displays an entire lab
void negativeOne(int **labPtr);



int main()
{
    initialDisplay(); //used to display the universities
    int userChoice = 0; //used to control menu


    //below is code initializing the parallel arrays and pointers
     int* labPtr[NUMLABS];  // 8 ptrs, one for each lab
     for(auto i=0; i<NUMLABS; ++i)
        {
        labPtr[i] = new int[LABSIZES[NUMLABS]]; // create each lab, matching each size
        }

    for(auto i = 0; i < NUMLABS; ++i)
        {
        for(auto j=0; j<LABSIZES[NUMLABS]; ++j)
            {
                labPtr[i][j] = 0;
            }
       }

    string* namePtr[NUMLABS];
    for(auto i=0; i<NUMLABS; ++i)
        {
        namePtr[i] = new string[LABSIZES[NUMLABS]];
        }

    int* timePtr[NUMLABS];  // 8 ptrs, one for each lab
        for(auto i=0; i<NUMLABS; ++i)
        {
        timePtr[i] = new int[LABSIZES[NUMLABS]]; // create each lab, matching each size
        }

    //negativeOne(labPtr);

        do{
            mainMenu(); //displays menu

            cout << "Your Choice: ";
            cin >> userChoice; //recives choice for the menu

            switch (userChoice)
            {
                case(1):
                    logIn(labPtr, namePtr, timePtr); //runs login function if chosen
                    break;
                case(2):
                    logOff(labPtr, namePtr, timePtr); //runs log off function if chosen
                    break;
                case(3):
                    look(labPtr); //runs the search function if chosen
                    break;
                case(4):
                    display(labPtr); //displays a chosen lab if chosen
                    break;
                case(5): //closes menu and ends program
                    break;
            }
        }while(userChoice != 5);

    for(auto i=0; i < NUMLABS; ++i){
        delete[]labPtr[i];
    }
        delete[]labPtr;

    for(auto i=0; i < NUMLABS; ++i){
        delete[]namePtr[i];
    }
        delete[]namePtr;

    for(auto i=0; i < NUMLABS; ++i){
        delete[]timePtr[i];
    }
        delete[]timePtr;

}

void initialDisplay(){

    cout << "Welcome! Here is a list of availble labs" << endl;
    cout << "Lab #1: The University of Michigan" << endl;
    cout << "Lab #2: The University of Pittsburgh" << endl;
    cout << "Lab #3: Stanford University" << endl;
    cout << "Lab #4: Arizona State University" << endl;
    cout << "Lab #5: North Texas State University" << endl;
    cout << "Lab #6: The University of Alabama, Huntsville" << endl;
    cout << "Lab #7: Princeton University" << endl;
    cout << "Lab #7: Duquesne University" << endl;
    cin.get();

}

void mainMenu(){

  cout << endl;
  cout << setw(68) << "__________________________________________________________________ " << endl;
  cout << setw(68) << "|------------------------------------------------------------------|" << endl;
  cout << setw(68) << "|                   Jake Darida Incorporated                       |" << endl;
  cout << setw(68) << "|                      Computer Lab System                         |" << endl;
  cout << setw(68) << "|__________________________________________________________________|" << endl;
  cout << left << setw(2) << "|" << setw(21) << " " << setw(43) << "   MAIN MENU"
       << right << setw(2) << "|" << endl;
  cout << left << setw(2) << "|" << setw(21) << " " << setw(43) << "1) Simulate Login"
       << right << setw(2) << "|" << endl;
  cout << left << setw(2) << "|" << setw(21) << " " << setw(43) << "2) Simulate Logoff"
       << right << setw(2) << "|" << endl;
  cout << left << setw(2) << "|" << setw(21) << " " << setw(43) << "3) Search"
       << right << setw(2) << "|" << endl;
  cout << left << setw(2) << "|" << setw(21) << " " << setw(43) << "4) Display a lab"
       << right << setw(2) << "|" << endl;
  cout << left << setw(2) << "|" << setw(21) << " " << setw(43) << "5) Quit"
       << right << setw(2) << "|" << endl;
  cout << setw(68) << "|__________________________________________________________________|" << endl;
  cout << endl;


}

void negativeOne(int **labPtr){

      for(auto i = 0; i < NUMLABS; ++i)
        {
        for(auto j=0; j<26; ++j)
            {
                labPtr[i][j] = -1;
            }
        }
}

void logIn(int **labPtr, string **namePtr, int **timePtr){

   srand (time(NULL));

   bool loopFlag = true;
   int labChoice = 0;
   int stationChoice = 0;
   int number = rand() % 10000;
   string name = " ";
   int time = 0;

    do{
		cout << "Enter the lab number the user is logging in from (1-8): ";
		cin >> labChoice;
		loopFlag = validateInput(labChoice, 1, 8);
	} while (loopFlag);

    do{
		cout << "Enter the computer station number the user is logging in to (1-" << LABSIZES[labChoice-1] << "): ";
		cin >> stationChoice;
		loopFlag = validateInput(stationChoice, 1, LABSIZES[labChoice-1]);
	} while (loopFlag);


    cout << "\n" << "User ID: " << std::setfill('0') << std::setw(5) << number << endl;
    labPtr[labChoice-1][stationChoice-1] = number;


    cout << "Please enter your name: " << endl;
    getline(cin, name);
    namePtr[labChoice-1][stationChoice-1] = name;


    cout << "Please enter the time worked at the station (15/30/45/60)" << endl;
    cin >> time;
    if(time != 15 && time != 30 && time != 45 && time != 60) {
            std::cerr << "ERROR: Allowed time periods are 15/30/45/60 minutes.\n";
            return;
        }


    cout << "User " << std::setfill(' ') << name << " has been logged in" << endl;

}

bool validateInput(int userChoice, int range1, int range2){

  bool goodOrNot = false;
  if ((cin.fail()) || ((userChoice < range1) || (userChoice > range2)))
  {
    goodOrNot = true;
  }
  cin.clear();
  cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  return goodOrNot;
}

void logOff(int **labPtr, string **namePtr, int **timePtr){

    bool loopFlag = true;
    int labChoice = 0;
    int stationChoice = 0;


    do{
		cout << "Enter the lab number the user is logging out of (1-8): ";
		cin >> labChoice;
		loopFlag = validateInput(labChoice, 1, 8);
	} while (loopFlag);

    do{
		cout << "Enter the computer station number the user is logging out of (1-" << LABSIZES[labChoice-1] << "): ";
		cin >> stationChoice;
		loopFlag = validateInput(stationChoice, 1, LABSIZES[labChoice-1]);
	} while (loopFlag);

	labPtr[labChoice-1][stationChoice-1] = 0;
	namePtr[labChoice-1][stationChoice-1] = " ";
	timePtr[labChoice-1][stationChoice-1] = 0;


    cout << "User has been logged out" << endl;
}

void look(int **labPtr){

    int ID = 0;

    cout << "Please enter the 5 digit User ID you would like to search for: ";
    cin >> ID;

    for(auto i = 0; i < 8; ++i)
        {
        for(auto j=0; j<26; ++j)
            {
            if(labPtr[i][j] == ID)
            {
                cout << "User found in lab " << (i+1) << " at computer " << (j+1);
                return;
            }
        }
    }
      cout << "User id: " << ID << " is not logged on." << endl;
}

void display(int **labPtr){

    int labNumber;

    cout << "Enter the lab number you wish to view: ";
    cin >> labNumber;


    if(labNumber<1 || labNumber>NUMLABS)
    {
       cout << "Invalid lab number."
           << " Try to enter the lab number between 1 and 8\n";
       return;
    }

   cout << "LAB STATUS" << endl;
   cout << "Lab # " << labNumber << " for " << UNIVERSITYNAMES[labNumber] << endl;


            for(auto j=0; j<LABSIZES[labNumber-1]; ++j)
            {
                 if(labPtr[labNumber-1][j] == 0 || labPtr[labNumber-1][j] > 99999 || labPtr[labNumber-1][j] < -99999)
                 {
                     cout << "#" << j+1 << ": empty" << endl;
                 }
                    else{
                        cout << "#" << j+1 << ": "<<std::setfill('0') << std::setw(5) << (labPtr)[labNumber-1][j] << "\n" << std::setfill(' ');
                        }
            }


   cout << endl;
   cout << "--------------------------------------------------------------------------------" << endl;
}






