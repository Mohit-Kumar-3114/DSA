// Print all divisor of a number

#include<bits/stdc++.h>
using namespace std;




// Brute O(n) and O(no. of divisor)
vector<int>fn(int num){
    vector<int>ans;
    for(int i=1;i<=num;i++){
        if(num%i==0)ans.push_back(i);
    }
    return ans;
}




// Optimal O(sqrt(n)) and O(no. of divisor)
vector<int>fn2(int num){
    vector<int>ans;
    int last=sqrt(num);
    for(int i=1;i<=last;i++){
        if(num%i==0){
            ans.push_back(i);
           if(i!=num/i) ans.push_back(num/i);
    }}
    return ans;
}




int main() {
    int a=36;
    vector<int>ans=fn(a);
    for(auto x:ans) cout<<x<<" ";
    cout<<endl;
    vector<int>ans2=fn2(a);
    for(auto x:ans2) cout<<x<<" ";
    return 0;
}