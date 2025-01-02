// Next permutation

#include <bits/stdc++.h>
using namespace std;




// Optimal O(3n) and O(1)
vector<int> nextGreaterPermutation(vector<int> &A) {
    int n = A.size(); 

    // Step 1: Find the break point:
    int ind = -1; // break point
    for (int i = n - 2; i >= 0; i--) {  
        if (A[i] < A[i + 1]) {
            ind = i; // 1
            break;
        }
    }

    // If break point does not exist:
    if (ind == -1) {
        // reverse the whole array:
        reverse(A.begin(), A.end());
        return A;
    }

    // Step 2: Find the next greater element and swap it with arr[ind]:
    else{
    for (int i = n - 1; i > ind; i--) {
        if (A[i] > A[ind]) {
            swap(A[i], A[ind]);  
            break;
        }
    }

    // Step 3: Reverse the right half:
    reverse(A.begin() + ind + 1, A.end()); 
    }

    return A;
}




int main(){
    vector<int> A = {2, 1, 5, 4, 3, 1,0};  // 5 4 3 2 1 1 0
    vector<int> ans = nextGreaterPermutation(A);  
    cout << "The next permutation is: ";
    for (auto it : ans) {
        cout << it << " ";
    }
    return 0;
}

