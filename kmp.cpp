#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> computeLPSTable(const string &pattern)
{
    vector<int> lps(pattern.length(), 0);

    int i = 0;
    int j = 1;
    lps[0] = 0;

    while (j < pattern.length())
    {
        if (pattern[i] == pattern[j])
        {
            lps[j] = i + 1;
            i++;
            j++;
        }
        else
        {
            if (i != 0)
            {
                i = lps[i - 1];
            }
            else
            {
                lps[j] = 0;
                j++;
            }
        }
    }
    for (int i = 0; i < lps.size(); i++) {
        // Printing the element at
        // index 'i' of vector
        cout <<" lps("<<i <<")="<< lps[i]   ;
    }
    return lps;
}

vector<int> KMP(const string &text, const string &pattern)
{
    vector<int> lps = computeLPSTable(pattern);
    vector<int> matches;

    int textLength = text.length();
    int patternLength = pattern.length();

    int i = 0; // Index for text[]
    int j = 0; // Index for pattern[]

    while (i < textLength)
    {
        if (pattern[j] == text[i])
        {
            i++;
            j++;
        }

        if (j == patternLength)
        {
            matches.push_back(i - j);
            j = lps[j - 1];
        }
        else if (i < textLength && pattern[j] != text[i])
        {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }

    return matches;
}

int main()
{
    string text = "abcdabcdabeabbabcee";
    string pattern = "abcdabeabb";

    vector<int> matches = KMP(text, pattern);

    if (matches.empty())
    {
        cout << "Pattern not found in text." << endl;
    }
    else
    {
        cout<<endl;
        cout << "Pattern found at positions: ";
        for (int match : matches)
        {
            cout << match << " ";
        }
        cout << endl;
    }

    return 0;
}
