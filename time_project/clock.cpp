//Name: Chris Humphreys and Denver Crittenden
//Date: 07/25/16
//Description: Clock Project

//Big Menu Clock Program Project 2

#include <iostream>
#include <iomanip>
#include <sstream>
#include <ctime>
#define CDT (-5)  // Time Zone
// define is another way to make a constant

using namespace std;

string line1, line2, line3, line4, line5, line6;
// We will copy the big numbers/characters into these global lines

const string BLACK_SQUARE = "&#x25FE";  // web + unicode
const string WHITE_SQUARE = "&#x25FD";  // web + unicode
const string SMILEY = "&#x1F603";       // web + unicode

// make a function for each number / char you need...
void c0(){
    line1 += " XXX  ";
    line2 += "X   X ";
    line3 += "X   X ";
    line4 += "X   X ";
    line5 += "X   X ";
    line6 += " XXX  ";
}

void c1(){
	line1 += " X ";
	line2 += "XX ";
	line3 += " X ";
	line4 += " X ";
	line5 += " X ";
	line6 += "XXX";
}

void copyBigChar(char n){
    if (n == '0')
        c0();
	    //...
}

void showLines(){  // put the big chars on the screen
    cout << line1 << endl << line2 << endl << line3 << endl;
    cout << line4 << endl << line5 << endl << line6 << endl; 
}

void showBigString(string s, string mode){
	// loop through the string and show each char 
    // in the requested mode
    // ...
}

string getTime(){  // gets the time of day as a string - formatted hh:mm:ss
    // Function by Bob Bradley...
    // Info at: https://stackoverflow.com/questions/997946/how-to-get-current-time-and-date-in-c
    // There is a better way to do this in c++ 11, but this way should work on more versions...
            
    time_t rawtime;
    struct tm * ptm;

    time ( &rawtime );
    ptm = gmtime ( &rawtime );
                  
    int h = (24 + ptm->tm_hour+CDT)%24;  // add in the time zone offset
    int m = ptm->tm_min;
    int s = ptm->tm_sec;
                                     
    stringstream ss;      // prints into a string
    ss << setfill('0');   // pads the numbers with leading zeros (0)
    ss << setw(2) << h << ":" << setw(2) << m << ":" << setw(2) << s;
    return ss.str();
}

void showMenu(){
	cout << "MENU" << endl;
	cout << "T - Time" << endl;
	cout << "N - 0-9" << endl;
	cout << "B - Big Mode On" << endl;
	cout << "E - Emoji Mode On" << endl;
	cout << "S - Normal Text Mode" << endl;
	cout << "Q - Quit" << endl;
}

int main(){
    string mode = "normal";
	char menuSelection = 'F';
		    
    c0(); c1(); 
    showLines();
//    clearLines();
	while ( menuSelection != 'Q' && menuSelection != 'q'){
		showMenu();
		cout << endl;
		cin >> menuSelection;
		if ( menuSelection == 'T' || menuSelection == 't'){
			cout << "In the future this will print the time." << endl << endl;
		}
		else if ( menuSelection == 'N' || menuSelection == 'n'){
			cout << "In the future this will change to 0-9 mode." << endl << endl;	
		}
		else if ( menuSelection == 'B' || menuSelection == 'b'){
			cout << "In the future this will change to Big mode." << endl << endl;	
		}
		else if ( menuSelection == 'E' || menuSelection == 'e'){
			cout << "In the future this will change to Emoji mode." << endl << endl;	
		}
		else if ( menuSelection == 'S' || menuSelection == 's'){
			cout << "In the future this will change to Normal mode." << endl << endl;	
		}
		else if ( menuSelection == 'Q' || menuSelection == 'q'){
			cout << "Thank you for using the clock app." << endl << endl;
		}
		else {
			cout << "Invalid Selection: Please try again." << endl << endl;
		}
	}
	return 0;
}				

// used http://www.pcs.cnu.edu/~dgame/cs230/resources/wk5/senLoop.html for help making sentinel loop
