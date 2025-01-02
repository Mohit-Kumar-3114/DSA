// Find how many times a sorted array is rotated

#include <bits/stdc++.h>
using namespace std;




// Optimal O(log n) and O(1)
int countRotations(vector<int>& arr) {
    int low = 0, high = arr.size() - 1;
    int index=-1;
    int ans=INT_MAX;
    while (low <= high) {
        int mid = (low + high) / 2;

        // Edge case: If duplicates are present
        if (arr[low] == arr[mid] && arr[mid] == arr[high]) {
            if(arr[low]<ans){
            ans=arr[low];
            index=low;
            }
            low++;
            high--;
            continue;
        } 

        else if (arr[low] <= arr[mid]) {
            if(arr[low]<ans){
            ans=arr[low];
            index=low;
            }
            low = mid + 1;
        } 
    
        else {
           if(arr[mid]<ans){
            ans=arr[mid];
            index=mid;
            }
            high = mid - 1;
        }
    }
    return index; 
}




int main() {
    vector<int> arr = {4, 5, 6, 7, 8, 2, 3}; 
    int rotations = countRotations(arr); 
    cout << "The array is rotated " << rotations << " times.\n"; 
    return 0;
}
