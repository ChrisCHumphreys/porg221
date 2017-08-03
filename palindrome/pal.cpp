//Chris Humphreys - Denver Crittenden
//7/28/17
//Palindrome checker program

#include <iostream>
#include <string>
using namespace std;

string Reverse(string toBereversed){
    string reversed = "";
    for (int i = toBereversed.length() - 1; i >= 0; i--){
        reversed += toBereversed[i];  
    }
    return reversed;
}

//string filter to make all the letters uppercase in a string and return that string.
// from slides and https://www.youtube.com/watch?v=XUmZcK44lsc
string Up(string toBeup){
    string Upped = "";
    unsigned int i = 0;
        while (i < toBeup.length()){
            toBeup[i] = toupper(toBeup[i]);
            Upped += toBeup[i];
            i++;
        }    
    return Upped;
}    
// string filter to remove spaces and symbols in a string and return that string. taken from slides
string Filter(string toBefiltered){
    string r = ""; 
    unsigned int i =0;
        while (i < toBefiltered.length()){
            char c = toBefiltered[i];
            if (isalnum(c))
            r += c;
            i++;
        }    
    return r;
}
// takes the other filters, and checks if string is palindrome. if so returns 1, if not returns 0
bool palindromeTest(string userString){
    string filteredReverse = "";
    filteredReverse = Filter(userString);
    filteredReverse = Up(filteredReverse);
    filteredReverse = Reverse(filteredReverse);
    userString = Filter(userString);
    userString = Up(userString);
        if (filteredReverse == userString)
            return true;
        else
            return false;
}


// main loops the user input and counts sentences/palindromes. Also ends loop and outputs counters.
int main(){
    int sentences = 0;
    int palindromes = 0;
    string userString;
    cout << "Enter a string: ";
    getline(cin, userString);
        while(userString != "END"){
            if (userString == "END"){
                break;
            }
            sentences++;
            int i = palindromeTest(userString);
                if( i == 1){
                    palindromes++;
                    cout << userString << " is a palindrome." << endl;
                }
                else{
                    cout << userString << " is not a palindrome." << endl;
                }
        cout << "Enter a string: ";
        getline(cin, userString);        
        }
    cout << "Sentences: " << sentences << endl;
    cout << "Palindromes: " << palindromes << endl;
}
