// Next greater element 

#include <bits/stdc++.h>
using namespace std;




// Brute O(n^2) and O(n)
vector<int> nextGreaterElementBrute(vector<int>& arr) {
    int n = arr.size();
    vector<int> result(n, -1); 
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[i]) {
                result[i] = arr[j];
                break;
            }
        }
    }
    return result;
}




// Optimal O(2n) and O(2n)
vector<int> nextGreaterElementOptimal(vector<int>& arr) {
    int n = arr.size();
    vector<int> result(n, -1); 
    stack<int> st; 

    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && st.top() <= arr[i]) {
            st.pop(); 
        }
        if (!st.empty()) {
            result[i] = st.top(); 
        }
        st.push(arr[i]);
    }
    return result;
}




int main(){
    vector<int> arr = {4, 5, 2, 10, 8};
    vector<int> result = nextGreaterElementBrute(arr);
    cout << "Brute Force: ";
    for (int i : result) {
        cout << i << " ";
    }
    cout << endl;
    result = nextGreaterElementOptimal(arr);
    cout << "Optimal: ";
    for (int i : result) {
        cout << i << " ";
    }
    return 0;
}