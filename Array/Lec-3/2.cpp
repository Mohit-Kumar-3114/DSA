// Majority elements (>n/3 times)

#include <bits/stdc++.h>
using namespace std;




// Brute O(n^2) and O(1)
vector<int> majorityElement(vector<int> v) {
    int n = v.size(); 
    vector<int> ls; 
    for (int i = 0; i < n; i++) {

        // Checking if v[i] is not already
        // a part of the answer:
        if (ls.size() == 0 || ls[0] != v[i]) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if (v[j] == v[i]) {
                    cnt++;
                }
            }

            // check if frquency is greater than n/3:
            if (cnt > (n / 3))
                ls.push_back(v[i]);
        }
        if (ls.size() == 2) break;
    }
    return ls;
}




// Better O(n) and O(n)
vector<int> majorityElement2(vector<int> v) {
    int n = v.size();
    vector<int> ls; 
    unordered_map<int, int> mpp;
    int mini = int(n / 3) + 1;
    for (int i = 0; i < n; i++) {
        mpp[v[i]]++;
        // Once an element exceeds n/3, it becomes a candidate, and further occurrences won't add it again 
        // since only equality (`==`) is checked.
        if (mpp[v[i]] == mini) { 
            ls.push_back(v[i]);
        }
        if (ls.size() == 2) break;
    }

    return ls;
}




// Optimal O(2n) and O(1)
vector<int> majorityElement3(vector<int> v) {
    int n = v.size(); 
    int cnt1 = 0, cnt2 = 0; // counts
    int el1 = INT_MIN; // element 1
    int el2 = INT_MIN; // element 2

    // applying the Extended Boyer Moore's Voting Algorithm:
    for (int i = 0; i < n; i++) {
        if (cnt1 == 0 && el2 != v[i]) {
            cnt1 = 1;
            el1 = v[i];
        }
        else if (cnt2 == 0 && el1 != v[i]) {
            cnt2 = 1;
            el2 = v[i];
        }
        else if (v[i] == el1) cnt1++;
        else if (v[i] == el2) cnt2++;
        else {
            cnt1--, cnt2--;
        }
    }

    vector<int> ls;
    cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] == el1) cnt1++;
        if (v[i] == el2) cnt2++;
    }

    int mini = int(n / 3) + 1;
    if (cnt1 >= mini) ls.push_back(el1);
    if (cnt2 >= mini) ls.push_back(el2);
    return ls;
}




int main(){
    vector<int> arr = {33, 33, 33, 33, 33, 11,11,11,11};
    vector<int> ans = majorityElement(arr);
    vector<int> ans2 = majorityElement2(arr);
    vector<int> ans3 = majorityElement3(arr);
    cout << "The majority elements are: ";
    for (auto it : ans)
        cout << it << " ";
    cout << "\n";
    cout << "The majority elements are: ";
    for (auto it : ans2)
        cout << it << " ";
    cout << "\n";
     cout << "The majority elements are: ";
    for (auto it : ans3)
        cout << it << " ";
    cout << "\n";
    return 0;
}



