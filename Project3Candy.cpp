// Denver Crittendon - Partner Chris Humphreys
// 8/1/17
// Crazier Candy Club Project 3

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;


// part 1 of the assignment is this function. It determines which menu to display
// by user choice and then loops through displaying the appropriate file's menu text
// alerts the user if the file could not be opened properly.
// written by Denver
void menuChoice(){

string name;
double price;
string menuChoice;
ifstream myfile;
    cout << "Welcome to the Crazy Candy Club!" << endl;
    cout << "Would you like the normal or holiday menu? ";
    cin >> menuChoice;
    if (menuChoice == "normal"){
        myfile.open("normal_menu.txt");
        cout << '\n' << "NORMAL MENU:" << endl;
    }
    else if (menuChoice == "holiday"){
        myfile.open("holiday_menu.txt");
        cout << '\n' << "HOLIDAY MENU:" << endl;
    }
    else{
        cout << "File could not be opened.";
    }
    while(myfile){
        getline(myfile,name);
        myfile >> price;
        myfile.ignore(10,'\n');

        if (myfile){
            cout << left << setw(30) << name << right << setw(3) << "$" << right << setw(6) << price << endl;
        }
    }
    myfile.close();
}
int main(){
    menuChoice();
}
