#include <iostream>
#include <string>

using namespace std;

string changeCapitalization(string s) {
	string newText = "";

    for (int i=0; i < s.length(); i++) {
        char c = s[i];

        if (islower(c)) {
            newText += toupper(c);
        } 
		else if (isupper(c)) {
            newText += tolower(c);
        } 
		else {
			newText += c;
		}
    }

    return newText;
}

int main() {
    string text;

    cout << "Input text: ";
    getline(cin, text);

    cout << changeCapitalization(text);

    return 0;
}
