// Count inversions in an array

#include <bits/stdc++.h>
using namespace std;




// Brute O(n * n) and O(1)
int numberOfInversions(vector<int>&a, int n) {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j]) cnt++;
        }
    }
    return cnt;
}




// Optimal O(n log n) and O(n + log n)
int merge(vector<int> &arr, int low, int mid, int high) {
    vector<int> temp; 
    int left = low;      
    int right = mid + 1;   
    int cnt = 0;
    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else {
            temp.push_back(arr[right]);
            cnt += (mid - left + 1); 
            right++;
        }
    }
    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
    return cnt; 
}

int mergeSort(vector<int> &arr, int low, int high) {
    int cnt = 0;
    if (low >= high) return cnt;
    int mid = (low + high) / 2 ;
    cnt += mergeSort(arr, low, mid); 
    cnt += mergeSort(arr, mid + 1, high); 
    cnt += merge(arr, low, mid, high);
    return cnt;
}

int numberOfInversions2(vector<int>&a, int n) {
    return mergeSort(a, 0, n - 1);
}




int main(){
    vector<int> a = {5,3,2,4,1};
    int n = 5;
    int cnt = numberOfInversions(a, n);
    cout << "The number of inversions is: "
         << cnt << endl;
    int cnt2 = numberOfInversions2(a, n);
    cout << "The number of inversions is: "
         << cnt2 << endl;
    return 0;
}

