// Denver Crittendon - Chris Humphreys
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

    cout << "TOTAL:" << right << setw(42) << "$ " << right << setw(6) << total << endl;
    // sets decimal point to 2, ensuring $ format is followed correctly in the calculations.
    cout << "TAX (" << TAX*100 << "%):" << right << setw(36) << "$ " << right << setw(6) << total*TAX << endl;
    cout << "======================================================" << endl;
    double grandTotal = total*TAX + total;
	cout << grandTotal;
    // cout << "GRAND TOTAL:" << right << setw(24) << candy1Bought + candy2Bought + candy3Bought + candy4Bought + candy5Bought 
    // << "  items" << right <<setw(5) << "$ " << right << setw(6) << grandTotal << endl;
	
	
}

int main(){
    menuChoice();
}

/* The following is the code from the first candy club for us to use as needed.  It is all commented out here to avoid compiling errors.


void storeFront(){
     I wrote a good portion of this personally working ahead by myself. Chris and I went over it and made it better
       and cleaned it up into the easily readible format it is in now.
       Chris put this into the void function and added constants for candy price
       I added constants for candy names
    
    // constants
    const double CANDY1_PRICE = 5.49;
    const double CANDY2_PRICE = 7.99;
    const double CANDY3_PRICE = 4.99;
    const double CANDY4_PRICE = 11.49;
    const double CANDY5_PRICE = 19.19;
    const double TAX = .09;
    const string CANDY1 = "Cary's Candy Corns";
    const string CANDY2 = "Chris's Chocolate Cashews";
    const string CANDY3 = "Julie's Jelly Jumperz";
    const string CANDY4 = "Pete's Peanut Pecans";
    const string CANDY5 = "Sam's Sweet Samplers";
    // variables
    int candy1Bought = 0;
    int candy2Bought = 0;
    int candy3Bought = 0;
    int candy4Bought = 0;
    int candy5Bought = 0;
    double total = 0;
    // asks user how much of each candy they want 
    cout << fixed << setprecision(2);
    cout << "WELCOME TO THE CRAZY CANDY CLUB!" << endl;
    cout << "How many of the " << CANDY1 << "? ($" << CANDY1_PRICE << " each) : ";
    cin >> candy1Bought;
    cout << "How many of the " << CANDY2 << "? ($" << CANDY2_PRICE << " each) : ";
    cin >> candy2Bought;
    cout << "How many of the " << CANDY3 << "? ($" << CANDY3_PRICE << " each) : ";
    cin >> candy3Bought;
    cout << "How many of the " << CANDY4 << "? ($" << CANDY4_PRICE << " each) : ";
    cin >> candy4Bought;
    cout << "How many of the " << CANDY5 << "? ($" << CANDY5_PRICE << " each) : ";
    cin >> candy5Bought; cout << endl;
    cout << endl;
    // itemizes the customers purchases, formatted to line up, and gives them a total bill showing tax rate.
    cout << "Items Ordered : " << endl;
    cout << right << setw(30) << CANDY1 << " : x " <<
    left << setw(2) << candy1Bought << right << setw(10) << " items = $ " << right << setw(6) << candy1Bought*CANDY1_PRICE << endl;
    cout << right << setw(30) << CANDY2 << " : x " << 
    left << setw(2) << candy2Bought << right << setw(10) << " items = $ " << right << setw(6) << candy2Bought*CANDY2_PRICE << endl;
    cout << right << setw(30) << CANDY3 << " : x " <<
    left << setw(2) << candy3Bought << right << setw(10) << " items = $ " << right << setw(6) << candy3Bought*CANDY3_PRICE << endl;
    cout << right << setw(30) << CANDY4 << " : x " <<
    left << setw(2) << candy4Bought << right << setw(10) << " items = $ " << right << setw(6) << candy4Bought*CANDY4_PRICE << endl;
    cout << right << setw(30) << CANDY5 << " : x " <<
    left << setw(2)<< candy5Bought << right << setw(10) << " items = $ " << right << setw(6) << candy5Bought*CANDY5_PRICE << endl;
    total = (candy1Bought*CANDY1_PRICE + candy2Bought*CANDY2_PRICE + candy3Bought*CANDY3_PRICE + candy4Bought*CANDY4_PRICE + candy5Bought*CANDY5_PRICE);
    cout << "TOTAL:" << right << setw(42) << "$ " << right << setw(6) << total << endl;
    // sets decimal point to 2, ensuring $ format is followed correctly in the calculations.
    cout << "TAX (" << TAX*100 << "%):" << right << setw(36) << "$ " << right << setw(6) << total*TAX << endl;
    cout << "======================================================" << endl;
    double grandTotal = total*TAX + total;
    cout << "GRAND TOTAL:" << right << setw(24) << candy1Bought + candy2Bought + candy3Bought + candy4Bought + candy5Bought 
    << "  items" << right <<setw(5) << "$ " << right << setw(6) << grandTotal << endl;
    // records customer payment for change making purposes.
    double payment = 0;
    cout << "How much did you receive: $";
    cin >> payment;
    // calls the void function to calculate and print results here after customer payment.
    changeMaker(grandTotal, payment);
}

void changeMaker(double cost, double received){ 
     chris wrote this while I was next to him and we both discussed how it works and why
       does the math portion taking our change amount and converting it into 
       monetary denominations.
    
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
*/
