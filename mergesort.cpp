#include <iostream>
using namespace std;

void merge(int A[], int lb, int mid, int ub) {
    int i = lb;
    int j = mid + 1;
    int k = lb; // Initialize k with the starting index of the merged array
    int B[ub + 1]; // Temporary array for merging

    while (i <= mid && j <= ub) {
        if (A[i] <= A[j]) {
            B[k] = A[i];
            i++;
        } else {
            B[k] = A[j];
            j++;
        }
        k++;
    }

    if (i > mid) {
        while (j <= ub) { // Copy remaining elements from the second half
            B[k] = A[j];
            j++;
            k++;
        }
    } else {
        while (i <= mid) { // Copy remaining elements from the first half
            B[k] = A[i];
            i++;
            k++;
        }
    }

    // Copy merged elements back to original array A
    for (int p = lb; p <= ub; p++) {
        A[p] = B[p];
    }
}

void mergeSort(int A[], int lb, int ub) {
    if (lb < ub) {
        int mid = (lb + ub) / 2;
        mergeSort(A, lb, mid); // Sort first half
        mergeSort(A, mid + 1, ub); // Sort second half
        merge(A, lb, mid, ub); // Merge the sorted halves
    }
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    cout << "Given array is \n";
    for (int i = 0; i < arr_size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    mergeSort(arr, 0, arr_size - 1);

    cout << "Sorted array is \n";
    for (int i = 0; i < arr_size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}