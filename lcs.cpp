#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int lcs(const string& str1, const string& str2) {
    int m = str1.length();
    int n = str2.length();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[m][n];
}

int main() {
    string str1, str2;
    cout << "Enter the first string: ";
    cin >> str1;
    cout << "Enter the second string: ";
    cin >> str2;

    int length = lcs(str1, str2);
    cout << "Length of the Longest Common Subsequence: " << length << endl;

    return 0;
}
