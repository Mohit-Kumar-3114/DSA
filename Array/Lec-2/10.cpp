// Longest consecutive sequence in an array

#include <bits/stdc++.h>
using namespace std;




// Brute O(n^2) and O(1)
int longestSuccessiveElements(vector<int>&a) { 
    int n = a.size(); 
    int longest = 1;
    for (int i = 0; i < n; i++) {
        int x = a[i]; 
        int cnt = 1;
        for(int j=0;j<n;j++) {
            if(a[j]==x+1){
            x += 1; 
            cnt += 1; 
            j=-1; 
            }
        }
        longest = max(longest, cnt);
    }
    return longest;
}




// Better O(n log n) and O(log n)
int longestSuccessiveElements2(vector<int>&a) {
    int n = a.size();
    if (n == 0) return 0;
    sort(a.begin(), a.end());
    int cnt = 1;
    int longest = 1;
    for (int i = 0; i < n-1; i++) {
        if (a[i]+1== a[i+1]) {
            cnt += 1; 
        }
        else {
            cnt = 1;
        }
        longest = max(longest, cnt);
    }
    return longest;

}




// Optimal O(3n) and O(n)
int longestSuccessiveElements3(vector<int>&a) { 
    int n = a.size();
    if (n == 0) return 0;
    int longest = 1;
    unordered_set<int> st;
    for (int i = 0; i < n; i++) {
        st.insert(a[i]);
    }
    for (auto it : st) {
        if (st.find(it - 1) == st.end()) {
            int cnt = 1;
            int x = it; 
            while (st.find(x + 1) != st.end()) {
                x = x + 1; 
                cnt = cnt + 1;
            }
            longest = max(longest, cnt);  
        }
    }
    return longest;
}




int main(){
    vector<int> a = {102,101,99,98,100, 200, 1, 2, 3, 4}; 
    int ans = longestSuccessiveElements(a);
    int ans2 = longestSuccessiveElements2(a);
    int ans3 = longestSuccessiveElements3(a);
    cout << "The longest consecutive sequence is " << ans << "\n";
    cout << "The longest consecutive sequence is " << ans2 << "\n";
    cout << "The longest consecutive sequence is " << ans3 << "\n";
    return 0;
}

