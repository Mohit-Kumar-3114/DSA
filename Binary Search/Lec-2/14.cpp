// Kth element of two sorted arrays

#include <bits/stdc++.h>
using namespace std;




// Brute O(n1 + n2) and O(n1 + n2)
int kthElement(vector<int>& a, vector<int>& b,int k) {
    int n1 = a.size(), n2 = b.size();
    vector<int> arr3;
    int i = 0, j = 0;
    while (i < n1 && j < n2) {
        if (a[i] < b[j]) arr3.push_back(a[i++]);
        else arr3.push_back(b[j++]);
    }
    while (i < n1) arr3.push_back(a[i++]);
    while (j < n2) arr3.push_back(b[j++]);
    return arr3[k-1];
}




// Better O(n1 + n2) and O(1)
int kthElement2(vector<int>& a, vector<int>& b, int k) {
    int n1 = a.size(), n2 = b.size();
    int cnt = 0;
    int el=-1;
    int i = 0, j = 0;
    while (i < n1 && j < n2) {
        if (a[i] < b[j]) {
            if (cnt == k-1) el = a[i];
            cnt++;
            i++;
        }
        else {
            if (cnt == k-1) el = b[i];
            cnt++;
            j++;
        }
    }
    while (i < n1) {
         if (cnt == k-1) el = a[i];
        cnt++;
        i++;
    }
    while (j < n2) {
         if (cnt == k-1) el = b[i];
        cnt++;
        j++;
    }
    return el;
}




// Optimal O(log(min(n1,n2))) and O(1)
int kthElement3(vector<int>& a, vector<int>& b, int k) {
    int n1 = a.size(), n2 = b.size();
        // Ensure the first array is smaller
        if (n1 > n2) return kthElement3(b, a, k);
        
        int low = max(0, k - n2), high = min(k, n1);
        
        while (low <= high) {
            int c1 = (low + high) / 2;
            int c2 = k - c1;

            int l1 = (c1 == 0) ? INT_MIN : a[c1 - 1];
            int l2 = (c2 == 0) ? INT_MIN : b[c2 - 1];
            int r1 = (c1 == n1) ? INT_MAX : a[c1];
            int r2 = (c2 == n2) ? INT_MAX : b[c2];

            if (l1 <= r2 && l2 <= r1) {
                return max(l1, l2);
            } else if (l1 > r2) {
                high = c1 - 1;
            } else {
                low = c1 + 1;
            }
        }
        return -1; // if k is out of range
    }




int main(){
    vector<int> a = {1, 4, 9};
    vector<int> b = {2, 3, 6, 15,17};
    cout << "The kth element of two sorted array is " 
         << kthElement(a, b, 5) << '\n';\
    cout << "The kth element of two sorted array is " 
         << kthElement2(a, b, 5) << '\n';
    cout << "The kth element of two sorted array is " 
         << kthElement3(a, b, 5) << '\n';
}

  