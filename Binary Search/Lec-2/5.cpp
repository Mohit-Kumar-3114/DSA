// Find the smallest divisor

#include <bits/stdc++.h>
using namespace std;




int sumByD(vector<int>& arr, int div) {
    int sum = 0;
    for (int i = 0; i < arr.size(); i++) {
        sum += ceil((double)(arr[i]) / (double)(div));
    }
    return sum;
}

int findMaxElement(vector<int>& arr) {
    int maxElem = arr[0]; 
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] > maxElem) {
            maxElem = arr[i];
        }
    }
    return maxElem;
}




// Brute O(n * maxi) and O(1)
int smallestDivisor(vector<int>& arr, int limit) {
    int maxi = findMaxElement(arr);

    for (int d = 1; d <= maxi; d++) {
        if (sumByD(arr, d) <= limit) {  
            return d;
        }
    }
    return -1;
}




// Optimal O(n * log maxi) and O(1)
int smallestDivisor2(vector<int>& arr, int limit) {
    if (arr.size() > limit) return -1;
    int low = 1, high = findMaxElement(arr);

    while (low <= high) {
        int mid = (low + high) / 2;
        if (sumByD(arr, mid) <= limit) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return low;
}




int main() {
    vector<int> arr = {10,15,20};
    int limit = 8;
    int ansLinear = smallestDivisor(arr, limit);
    int ansBinary = smallestDivisor2(arr, limit);
    cout << "The minimum divisor using binary search is: " << ansBinary << "\n";
    cout << "The minimum divisor using linear search is: " << ansLinear << "\n";
    return 0;
}
