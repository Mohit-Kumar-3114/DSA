// Next greater element 2

#include <bits/stdc++.h>
using namespace std;




// Brute O(n^2) and O(n)
vector<int> nextGreaterElementBrute(vector<int>& arr) {
    int n = arr.size();
    vector<int> result(n, -1); 
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < i + n; j++) {
            if (arr[j%n] > arr[i]) {
                result[i] = arr[j%n];
                break;
            }
        }
    }
    return result;
}




// Optimal O(4n) and O(3n)
vector<int> nextGreaterElementOptimal(vector<int>& arr) {
    int n = arr.size();
    vector<int> result(n, -1); 
    stack<int> st; 

    for (int i = 2 * n - 1; i >= 0; i--) {
        while (!st.empty() && st.top() <= arr[i%n]) {
            st.pop(); 
        }
        if (!st.empty() and i<n) {
            result[i] = st.top(); 
        }
        st.push(arr[i%n]);
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