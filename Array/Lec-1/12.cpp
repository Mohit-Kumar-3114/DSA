// Find the number that appear once and other numbers twice 

#include <bits/stdc++.h>
using namespace std;




// Brute O(n^2) and O(1)
int getSingleElement(vector<int> &arr) {
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        bool found = false;
        for (int j = 0; j < n; j++) {
            if (i != j && arr[i] == arr[j]) {
                found = true; 
                break;
            }
        }
        if (!found) {
            return arr[i]; 
        }
    }
    return -1;
}




// Better O(n) and O(n/2 + 1)
int getSingleElement2(vector<int> &arr) { 
    unordered_map<int, int> countMap;
    for (int num : arr) {
        countMap[num]++; 
    }
    for (auto entry : countMap) {
        if (entry.second == 1) {
            return entry.first; 
        }
    }
    return -1; 
}




// Optimal O(n) and O(1)
int getSingleElement3(vector<int> &arr) { 
    int xorr = 0;
    for (int num:arr) {
        xorr ^= num;  
    }
    return xorr;
}




int main() {
    vector<int> arr = {5, 1, 2, 1, 2};
    int ans = getSingleElement(arr);
    cout << "The single element is: " << ans << endl;
    int ans2 = getSingleElement2(arr);
    cout << "The single element is: " << ans2 << endl;
    int ans3 = getSingleElement3(arr);
    cout << "The single element is: " << ans3 << endl;
    return 0;
}

