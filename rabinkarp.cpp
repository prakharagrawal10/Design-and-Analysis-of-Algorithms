#include <iostream>
#include <string>
#include <math.h>
using namespace std;

const int prime = 101; // prime number for hashing

void rabinKarp(string text, string pattern) {
    int n = text.length();
    int m = pattern.length();
    int patternHash = 0; // hash value for the pattern
    int textHash = 0; // hash value for the current window in the text

    // Calculate the hash value of the pattern and the first window in the text
    for (int i = 0; i < m; i++) {
        patternHash += pattern[i] * pow(prime, i);
        textHash += text[i] * pow(prime, i);
    }

    // Slide the pattern over the text one by one
    for (int i = 0; i <= n - m; i++) {
        // Check if the hash values of the current window in the text and the pattern match
        if (patternHash == textHash) {
            // Check if the characters in the current window and the pattern match
            bool match = true;
            for (int j = 0; j < m; j++) {
                if (text[i + j] != pattern[j]) {
                    match = false;
                    break;
                }
            }
            // If all characters match, print the starting index of the match
            if (match) {
                cout << "Pattern found at index " << i << endl;
            }
        }

        // Calculate the hash value for the next window in the text
        if (i < n - m) {
            textHash = (prime * (textHash - text[i] * pow(prime, 0))) + text[i + m];
        }
    }
}

int main() {
    // string text, pattern;
    // cout << "Enter the text: ";
    // cin >> text;
    // cout << "Enter the pattern: ";
    // cin >> pattern;
    string text = "abcdabdabceabcdab";
    string pattern = "abcdab";
    rabinKarp(text, pattern);

    return 0;
}