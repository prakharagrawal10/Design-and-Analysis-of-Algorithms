#include <climits>
#include <iostream>
using namespace std;

// Function to find the maximum sum subarray crossing the midpoint
int css(int arr[], int low, int mid, int high)
{
    int left = 0; // Initialize the running sum of the left subarray to 0
    int left_sum = INT_MIN; // Initialize the maximum sum of the left subarray to negative infinity

    // Traverse the left subarray to find the maximum sum
    for (int i = mid; i >= low; i--)
    {
        left += arr[i]; // Add the current element to the running sum
        left_sum = max(left_sum, left); // Update left_sum if the running sum is greater
    }

    int right = 0; // Initialize right sum to 0
    int right_sum = INT_MIN; // Initialize right_sum to negative infinity
    // Traverse the right subarray to find the maximum sum
    for (int i = mid + 1; i <= high; i++)
    {
        right += arr[i]; // Add the current element to the running sum
        right_sum = max(right_sum, right); // Update right_sum if the running sum is greater
    }

    // Return the sum of maximum left and right subarray sums
    return left_sum + right_sum;
}

// Function to find the maximum sum subarray
int mss(int arr[], int low, int high)
{
    // Base case: If there is only one element in the array, return that element
    if (low == high)
    {
        return arr[low];
    }
    // Calculate the midpoint
    int mid = (low + high) / 2;
    // Recursively find the maximum sum subarray in the left subarray
    int left_sum = mss(arr, low, mid);
    // Recursively find the maximum sum subarray in the right subarray
    int right_sum = mss(arr, mid + 1, high);
    // Find the maximum sum subarray crossing the midpoint
    int cross_sum = css(arr, low, mid, high);
    // Return the maximum of left subarray sum, right subarray sum, and cross subarray sum
    return max(left_sum, max(right_sum, cross_sum));
}

int main()
{
    // Input array
    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    // Calculate the size of the array
    int n = sizeof(arr) / sizeof(arr[0]);
    // Find and print the maximum sum subarray
    cout << mss(arr, 0, n - 1);
    return 0;
}
