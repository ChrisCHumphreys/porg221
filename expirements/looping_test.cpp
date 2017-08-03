#include <iostream>
#include <string>
using namespace std;

void compare();

int main(){
	string s = "Bob Bradley";
	string r = "";
	int i = (s.length() - 1);
	while (i >= 0){
		r += s[i];
		i--;
	}
	cout << r << endl;

	compare();
	return 0;
}

void compare(){
	cout << "Enter two words: ";
	string w1;
	string w2;
	cin >> w1 >> w2;
	if (w1 > w2)
			cout << w1 << " is greater than " << w2;
	else if (w2 == w1)
			cout << w1 << " is equal to " << w2;
	else if (w1 < w2)
			cout << w1 << " is less than " << w2;
	cout << endl;
}
