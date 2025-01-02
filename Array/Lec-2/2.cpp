// Sort an array of 0's , 1's and 2's

#include <bits/stdc++.h>
using namespace std;




// Brute O(n log n) and O(log n)
void sortArray(vector<int>& arr,int n){
   sort(arr.begin(),arr.end());
}




// Better O(2n) and O(1)
void sortArray2(vector<int>& arr, int n) {
    int cnt0 = 0, cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == 0) cnt0++;
        else if (arr[i] == 1) cnt1++;
        else cnt2++;
    }
    for (int i = 0; i < cnt0; i++) arr[i] = 0; 
    for (int i = cnt0; i < cnt0 + cnt1; i++) arr[i] = 1; 
    for (int i = cnt0 + cnt1; i < n; i++) arr[i] = 2; 
}




// Optimal O(n) and O(1)
void sortArray3(vector<int>& arr, int n) {
    int low = 0, mid = 0, high = n - 1; 
    while (mid <= high) {
        if (arr[mid] == 0) {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1) {
            mid++;
        }
        else {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}




int main(){
    int n = 9;
    vector<int> arr = {2,1,2,0, 2, 1, 2, 0, 1};
    sortArray2(arr, n);
    cout << "After sorting:" << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    vector<int> arr2 = {2,1,2,0, 2, 1, 2, 0, 1};
    sortArray2(arr2, n);
    cout << endl<< "After sorting:" << endl;
    for (int i = 0; i < n; i++) {
        cout << arr2[i] << " ";
    }
    vector<int> arr3 = {2,1,2,0, 2, 1, 2, 0, 1};
    sortArray2(arr3, n);
    cout << endl<<"After sorting:" << endl;
    for (int i = 0; i < n; i++) {
        cout << arr3[i] << " ";
    }
    cout << endl;
    return 0;
}

