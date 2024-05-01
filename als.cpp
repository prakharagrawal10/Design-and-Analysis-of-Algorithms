#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int assemblyLineScheduling(vector<vector<int>>& a, vector<vector<int>>& t, vector<int>& e, vector<int>& x) {
    int n = a[0].size(); // Number of stations

    // Time taken to reach each station on line 1 and line 2
    vector<int> f1(n), f2(n);
    f1[0] = e[0] + a[0][0]; // Entry time for line 1 + time taken at first station
    f2[0] = e[1] + a[1][0]; // Entry time for line 2 + time taken at first station

    // Calculate the fastest time to reach each station on line 1 and line 2
    for (int i = 1; i < n; i++) {
        f1[i] = min(f1[i - 1] + a[0][i], f2[i - 1] + t[1][i] + a[0][i]);
        f2[i] = min(f2[i - 1] + a[1][i], f1[i - 1] + t[0][i] + a[1][i]);
    }

    // Calculate the total time taken to exit the assembly line
    return min(f1[n - 1] + x[0], f2[n - 1] + x[1]);
}

int main() {
    // Example input
    vector<vector<int>> a = {{4,5,3,2}, {2,10,1,4}}; // Time taken at each station
    vector<vector<int>> t = {{0,7,4,5}, {0,9,2,4}}; // Time taken to switch lines
    vector<int> e = {10, 12}; // Entry time for each line
    vector<int> x = {18, 7}; // Exit time for each line

    int totalTime = assemblyLineScheduling(a, t, e, x);
    cout << "Total time taken: " << totalTime << endl;

    return 0;
}