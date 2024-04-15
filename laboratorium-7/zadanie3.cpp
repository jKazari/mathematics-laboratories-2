#include <iostream>
#include <string>

#define ALPHABET_SIZE 26

using namespace std;

bool areAnagrams(string s1, string s2) {
    for (int i=0; i < s1.length(); i++) {
        if (isalpha(s1[i])) {
            s1[i] = tolower(s1[i]);
        }
    }

    for (int i=0; i < s2.length(); i++) {
        if (isalpha(s2[i])) {
            s2[i] = tolower(s2[i]);
        }
    }

    int letter_counts_s1[ALPHABET_SIZE] = {0};
	int letter_counts_s2[ALPHABET_SIZE] = {0};

    for (int i=0; i < s1.length(); i++) {
		char c = s1[i];

        if (isalpha(c)) {
            letter_counts_s1[c-'a']++;
        }
    }

    for (int i=0; i < s2.length(); i++) {
		char c = s2[i];

        if (isalpha(c)) {
            letter_counts_s2[c-'a']++;
        }
    }

    for (int i=0; i < ALPHABET_SIZE; i++) {
		if (letter_counts_s1[i] != letter_counts_s2[i]) {
			return false;
		}
	}

    return true;
}

int main() {
    string s1, s2;

    cout << "Input first string: ";
    getline(cin, s1);

    cout << "Input second string: ";
    getline(cin, s2);

    if (areAnagrams(s1, s2)) {
        cout << "Given strings are anagrams" << endl;
    }
	else {
        cout << "Given strings are not anagrams" << endl;
    }

    return 0;
}