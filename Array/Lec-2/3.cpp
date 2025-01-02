// Majority elements (>n/2) times

#include <bits/stdc++.h>
using namespace std;




// Brute O(n^2) and O(1)
int majorityElement(vector<int> v){ 
    int n = v.size(); 
    for (int i = 0; i < n; i++) {
        int cnt = 1;
        for (int j = i+1; j < n; j++) {
            if (v[j] == v[i]) {
                cnt++;
            }
        }
        if (cnt > (n / 2))
            return v[i];
    }
    return -1;
}




// Better O(n) and O(n)
int majorityElement2(vector<int> v) {
    int n = v.size();
    unordered_map<int, int> mpp;
    for (int i = 0; i < n; i++) {
        mpp[v[i]]++; 
    }
    for (auto it : mpp) {
        if (it.second > (n / 2)) {
            return it.first;
        }
    }
    return -1;
}




// Optimal O(n) and O(1)
int majorityElement3(vector<int> v) { 
    int n = v.size(); 
    int cnt = 0; 
    int el; 
    for (int i = 0; i < n; i++) { 
        if (cnt == 0) {
            cnt = 1;  
            el = v[i]; 
        }
        else if (el == v[i]) cnt++;
        else cnt--;
    }
    int cnt1 = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] == el) cnt1++;
    }
    if (cnt1 > (n / 2)) return el;
    return -1;
}




int main(){
    vector<int> arr = {2, 1, 1, 1, 1, 2, 2,2,2,3,3,3,3,3,3,3,3,3,3,3,3,3};
    int ans = majorityElement(arr);
    cout << "The majority element is: " << ans << endl;
    int ans2 = majorityElement2(arr);
    cout << "The majority element is: " << ans2 << endl;
    int ans3 = majorityElement3(arr);
    cout << "The majority element is: " << ans3 << endl;
    return 0;
}


