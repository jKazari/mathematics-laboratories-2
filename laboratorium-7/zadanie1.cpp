#include <iostream>
#include <string>

using namespace std;

int countVowels(string s) {
    int vowel_count = 0;
    string vowels = "aiueoAIUEO";
    
    for (int i=0; i < s.length(); i++) {
        char c = s[i];
        
        if (vowels.find(c) != string::npos) {
            vowel_count++;
        }
    }
    
    return vowel_count;
}

int main() {
    string text;

	cout << "Input text: ";
    getline(cin, text);

    cout << "There are " << countVowels(text) << " vowels in given text" << endl;

    return 0;
}
