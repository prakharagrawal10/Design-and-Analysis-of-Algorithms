#include <iostream>
#include <vector>
using namespace std;

bool isSubsetSum(int arr[], int size, int targetSum, vector<int>& subset)
{
    // Base Cases
    if (targetSum == 0)
        return true;
    if (size == 0)
        return false;

    // If the last element is greater than the targetSum, ignore it
    if (arr[size - 1] > targetSum)
        return isSubsetSum(arr, size - 1, targetSum, subset);

    // Check if the targetSum can be obtained by either including or excluding the last element
    if (isSubsetSum(arr, size - 1, targetSum, subset)) {
        return true;
    } else {
        if (isSubsetSum(arr, size - 1, targetSum - arr[size - 1], subset)) {
            subset.push_back(arr[size - 1]);
            return true;
        }
    }
    return false;
}

int main()
{
    int arr[] = {3, 34, 4, 12, 5, 2};
    int targetSum = 9;
    int size = sizeof(arr) / sizeof(arr[0]);
    vector<int> subset;
    if (isSubsetSum(arr, size, targetSum, subset)) {
        cout << "Found a subset with the given sum " << targetSum << endl;
        cout << "The elements which form the max sum are: ";
        for (int i = 0; i < subset.size(); ++i) {
            cout << subset[i] << " ";
        }
    } else {
        cout << "No subset with the given sum";
    }
    return 0;
}
