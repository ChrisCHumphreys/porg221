#include <iostream>
#include <string>
using namespace std;

void tenTwenty(int num1);
void upperNumber(char s);

int main(){
	cout << "Enter a number and a character: ";
	int word;
	char word2;
	cin >> word >> word2;
	tenTwenty(word);
	upperNumber(word2);
	return 0;
}

void tenTwenty(int num1){
	if (num1 > 9 && num1 < 21)
		cout << num1 << " is BETWEEN 10 and 20.";
	else 
		cout << num1 << " is NOT BETWEEN 10 and 20.";
	cout << endl;
}

void upperNumber(char s){
	if (isupper(s) || isdigit(s)){
		cout << "YES";
	}
	cout << endl;
}
