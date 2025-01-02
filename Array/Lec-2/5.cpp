// Print subarray with maximum sum

#include <bits/stdc++.h>
using namespace std;




// Brute O(n^3) and O(1)
int maxSubarraySum(int arr[], int n) { 
    int maxi = INT_MIN; 
    int start = -1;
    int end = -1;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int sum = 0;
            for (int k = i; k <= j; k++) {
                sum += arr[k];
            }
            if (sum > maxi) {
                start = i;
                end = j;
                maxi = sum;
            }
        }
    }
    cout << "Brute Force - Maximum subarray sum is: " << maxi 
         << " from index " << start << " to " << end << endl;
    cout << "Subarray: ";
    for (int i = start; i <= end; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return maxi;
}




// Better O(n^2) and O(1)
int maxSubarraySum2(int arr[], int n) { 
    int maxi = INT_MIN;
    int start = -1;
    int end = -1; 
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += arr[j]; 
            if (sum > maxi) {
                start = i;
                end = j;
                maxi = sum;
            }
        }
    }
    cout << "Better - Maximum subarray sum is: " << maxi 
         << " from index " << start << " to " << end << endl;
    cout << "Subarray: ";
    for (int i = start; i <= end; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return maxi;
}




// Optimal O(n) and O(1)
int maxSubarraySum3(int arr[], int n) { 
    int maxi = INT_MIN;
    int start = -1;
    int end = -1; 
    int temp = 0;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i]; 
        if (sum > maxi) {
            maxi = sum; 
            start = temp; 
            end = i; 
        }
        if (sum < 0) {
            sum = 0; 
            temp = i + 1; 
        }
    }
    cout << "Optimal - Maximum subarray sum is: " << maxi 
         << " from index " << start << " to " << end << endl;
    cout << "Subarray: ";
    for (int i = start; i <= end; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return maxi;
}




int main() {
    int arr[] = {-2, -1,3,4};
    int n = sizeof(arr) / sizeof(arr[0]);
    maxSubarraySum(arr, n);
    maxSubarraySum2(arr, n);
    maxSubarraySum3(arr, n);
    return 0;
}

