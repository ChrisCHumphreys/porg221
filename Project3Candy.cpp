// Denver Crittendon - Chris Humphreys
// 8/1/17
// Crazier Candy Club Project 3

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

void changeMaker(double cost, double received){
//chris wrote this while I was next to him. we both discussed how it works and why
//does the math portion taking our change amount and converting it into
//monetary denominations.

    double change = received - cost;
    cout << "The amount of change due is: $" << change << endl;
    int totalCents = (change + .005) * 100;
    cout << "That is " << totalCents << " cents." << endl << endl;
    cout << "Please give the customer the following:" << endl;

//divides total cents into integer values equaling dollar and coin amounts until only pennies remain.

    int rCents = totalCents;
    int nTwenties = rCents / 2000;
    rCents = rCents % 2000;
    int nTens = rCents / 1000;
    rCents = rCents % 1000;
    int nFives = rCents / 500;
    rCents = rCents % 500;
    int nOnes = rCents / 100;
    rCents = rCents % 100;
    int nQuarters = rCents / 25;
    rCents = rCents % 25;
    int nDimes = rCents / 10;
    rCents = rCents % 10;
    int nNickels = rCents / 5;
    rCents = rCents % 5;
    int nPennies = rCents;
// formats and prints the monetary denominations the customer is due, equaling total change value.
    cout << left << setw(4) << nTwenties << right << setw(3) << " - " << "$20s" << endl;
    cout << left << setw(4) << nTens << right << setw(3) << " - " << "$10s" << endl;
    cout << left << setw(4) << nFives << right << setw(3) << " - " << "$5s" << endl;
    cout << left << setw(4) << nOnes << right << setw(3) << " - " << "$1s" << endl;
    cout << left << setw(4) << nQuarters << right << setw(3) << " - " << "quarters" << endl;
    cout << left << setw(4) << nDimes << right << setw(3) << " - " << "dimes" << endl;
    cout << left << setw(4) << nNickels << right << setw(3) << " - " << "nickels" << endl;
    cout << left << setw(4) << nPennies << right << setw(3) << " - " << "pennies" << endl;
}


// part 1 of the assignment is this function. It determines which menu to display
// by user choice and then loops through displaying the appropriate file's menu text
// alerts the user if the file could not be opened properly.
// written by Denver
void menuChoice(){

string name;
double price;
string menuChoice;
string nameArray[9];
double priceArray[9];
int buyArray[9];
int counter = 0;
int total = 0;
int totalItems = 0;
const double TAX = .09;

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
// Following two lines add the price and names to the parallel arrays.
			priceArray[counter] = price;
			nameArray[counter] = name;
			counter++;
        }
    }
    myfile.close();

	cout << endl << "Place order:" << endl << endl;

	for (int i = 0; i < counter; i++){
		cout << "How many of the " << nameArray[i] << " ($";
		cout << priceArray[i] << " each): ";
		cin >> buyArray[i];
	}

    cout << endl << "Items Ordered : " << endl;

	for (int i = 0; i < counter; i++){
		cout << right << setw(30) << nameArray[i] << " : x " <<
		left << setw(2) << buyArray[i] << right << setw(10) << " items = $ " << right << setw(6) << buyArray[i]*priceArray[i] << endl;
		total += (priceArray[i] * buyArray[i]);
		totalItems += buyArray[i];
	}

    cout << fixed << setprecision(2) << "TOTAL:" << right << setw(42) << "$ " << right << setw(6) << total << endl;
    cout << "TAX (" << TAX*100 << "%):" << right << setw(36) << "$ " << right << setw(6) << total*TAX+.005 << endl;
    cout << "======================================================" << endl;
    double grandTotal = total*TAX + total;
	cout << "GRAND TOTAL:" << right << setw(24) << totalItems << "  items" << right << setw(4) << "$" << right << setw(7) << grandTotal;

	double payment = 0;
    cout << endl << "How much did you receive: $";
    cin >> payment;
    changeMaker(grandTotal,payment);
}

int main(){
    menuChoice();
}
