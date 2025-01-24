// Power set 

#include <bits/stdc++.h>
using namespace std;  




// Optimal O(2^n * n) and O(2^n * n)
vector<vector<int>> PowerSet(int a[], int n){
    vector<vector<int>> ans;
    int subsets = 1 << n; // 2^n 
    for(int num=0;num<subsets;num++){
    vector<int>list;
    for(int i=0;i<n;i++){
    if((num & (1<<i)) != 0) list.push_back(a[i]); // check the ith bit is set or not
    }
    ans.push_back(list); 
    }
    return ans;
}




int main(){
    int a[]{13,82,39};
    int n=3;
    vector<vector<int>>ans=PowerSet(a,n);
    for (const auto& subset : ans) {
        cout << "{ ";
        for (int x : subset) {
            cout << x << " ";
        }
        cout << "}" << endl;
    }
    return 0;
}

