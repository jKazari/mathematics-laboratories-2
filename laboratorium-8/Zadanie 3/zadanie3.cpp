#include <fstream>
#include <iostream>
#include <string>

using namespace std;

const char chars[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m',
                      'n','o','p','q','r','s','t','u','v','w','x','y','z',
                      '1','2','3','4','5','6','7','8','9','0','.','?',',',
                      '+','-','=',';',':'};

const string morse[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.",
                              "....", "..", ".---", "-.-", ".-..", "--", "-.",
                              "---", ".--.", "--.-", ".-.", "...", "-", "..-",
                              "...-", ".--", "-..-", "-.--", "--..", ".----",
                              "..---", "...--", "....-", ".....", "-....",
                              "--...", "---..", "----.", "-----", ".-.-.-",
                              "..--..", "--..--", ".-.-.", "-....-", "-...-",
                              "-.-.-.", "---...", "---..", " "};

string encode(char c) {
    for (int i = 0; i < sizeof(chars); i++) {
        if (chars[i] == c) {
            return morse[i];
        }
    }
    return "";
}

char decode(const string& code) {
    for (int i = 0; i < sizeof(morse) / sizeof(morse[0]); i++) {
        if (morse[i] == code) {
            return chars[i];
        }
    }
    return '?';
}

int main() {
    fstream inputFile, outputFile;
    char choice;
    string inputFileName, outputFileName;
	string mode;

    cout << "Enter 'c' for coding or 'd' for decoding: ";
    cin >> choice;

    if (choice == 'c') {
        mode = "code";
    }
	else if (choice == 'd') {
        mode = "decode";
    }
	else {
        cout << "Invalid input." << endl;
        return 1;
    }

    // cout << "Enter input file name: ";
    // cin >> inputFileName;
    // cout << "Enter output file name: ";
    // cin >> outputFileName;

    inputFile.open("input.txt", ios::in);
    cout << "Hello";
    if (!inputFile.is_open()) {
        cout << "Error opening input file" << endl;
        return 1;
    }

    outputFile.open("output.txt", ios::in);
    if (!outputFile.good()) {
        cout << "Error opening output file." << endl;
        return 1;
    }

    string line;
    while (getline(inputFile, line)) {
        string result;
        if (mode == "code") {
            for (char c : line) {
                if (isalnum(c) || c == '.' || c == '?' || c == ',' ||
                    c   == '+' || c == '-' || c == '=' || c == ';' || c == ':') {
                    result += encode(tolower(c)) + " ";
                }
				else if (c == ' ') {
                    result += " ";
                }
            }
        }
		else {
            string code;
            for (char c : line) {
                if (c != ' ') {
                    code += c;
                }
				else {
                    result += decode(code);
                    code.clear();
                }
            }
            result += decode(code);
        }
        outputFile << result << endl;
    }

    cout << "File " << mode << "d successfully." << endl;

    inputFile.close();
    outputFile.close();

    return 0;
}