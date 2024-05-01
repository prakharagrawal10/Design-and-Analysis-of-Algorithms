#include <iostream> 
#include <vector> 
using namespace std; 
 
int matrixchainmul(vector<int>& dimension, vector<vector<int>>& splitpoints){ 
    int n = dimension.size(); 
    vector<vector<int>> dc(n,vector<int>(n,0)); 
     
    for (int len = 2; len<n; ++len){ 
        for (int i = 1 ; i<n-len+1; ++i){ 
            int j = i +len -1; 
            dc[i][j] = INT_MAX;
            for(int k = i; k<j; ++k){ 
                int cost = dc[i][k] + dc[k+1][j] + dimension[i-1]*dimension[j]*dimension[k]; 
                if(cost<dc[i][j]){ 
                    dc[i][j] = cost; 
                    splitpoints[i][j]=k; 
                } 
            } 
             
        } 
    } 
     
    return dc[1][n-1]; 
} 
 
void printOpmalOrder(const vector<vector<int>>& splitpoints, int i, int j){ 
     
    if (i == j) { 
        cout << "A" << i; 
    } else { 
        cout << "("; 
        printOpmalOrder(splitpoints, i, splitpoints[i][j]); 
        printOpmalOrder(splitpoints, splitpoints[i][j] + 1, j); 
        cout << ")"; 
    } 
     
} 
 
int main() { 
    vector<int> dimension = {10,20,30,40}; 
    int n = dimension.size(); 
    vector<vector<int>> splitpoints(n,vector<int>(n,0)); 
    int max =  matrixchainmul(dimension,splitpoints); 

    cout << "Minimum number of scalar mul plica ons needed: " << max << endl; 
     
    cout << "Order of mul plica on: "; 
    printOpmalOrder(splitpoints, 1, n - 1); 
    cout << endl; 
     
     
     
 
    return 0; 
}