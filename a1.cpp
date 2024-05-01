#include <iostream>
using namespace std;

int maxSubArray(int nums[], int size) {
    if (size == 0) return 0;

    int max1 = nums[0];
    int max = nums[0];

    for (int i = 1; i < size; i++) {
        if (nums[i] > max1 + nums[i]) {
            max1 = nums[i];
        } else {
            max1 = max1 + nums[i];
        }
        if (max1 > max) {
            max = max1;
        }
    }
    return max;
}

int main() {
    int nums[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int size = sizeof(nums) / sizeof(nums[0]);

    int maxSum = maxSubArray(nums, size);

    cout << "Maximum contiguous sum is: " << maxSum << endl;
    return 0;
}
