#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int evaluateExpression(string expression) {
    int n = expression.length();
    vector<int> nums;
    vector<char> ops;

    for (int i = 0; i < n; i++) {
        if (isdigit(expression[i])) {
            int num = 0;
            while (i < n && isdigit(expression[i])) {
                num = num * 10 + (expression[i] - '0');
                i++;
            }
            nums.push_back(num);
            i--;
        } else {
            ops.push_back(expression[i]);
        }
    }

    int m = nums.size();
    vector<vector<int>> dp(m, vector<int>(m, 0));

    for (int i = 0; i < m; i++) {
        dp[i][i] = nums[i]; // Base case: single number
    }

    for (int len = 2; len <= m; len++) {
        for (int i = 0; i <= m - len; i++) {
            int j = i + len - 1;
            for (int k = i; k < j; k++) {
                int val;
                if (ops[k] == '+') {
                    val = dp[i][k] + dp[k + 1][j];
                } else {
                    val = dp[i][k] * dp[k + 1][j];
                }
                dp[i][j] = max(dp[i][j], val);
            }
        }
    }

    // Print the dynamic programming table
    cout << "Dynamic Programming Table:" << endl;
    for (const auto& row : dp) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return dp[0][m - 1];
}

int main() {
    string expression = "2*3+4*5";
    int maxVal = evaluateExpression(expression);
    cout << "Maximum possible value: " << maxVal << endl;
    return 0;
}
