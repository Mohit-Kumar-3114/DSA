// Lcm and hcf of two numbers

#include<bits/stdc++.h>
using namespace std;




// Optimal O(log(min(a,b))) and O(1)
vector<int>fn(int a, int b){
    int x=max(a,b); 
    int y=min(a,b); 
    while(x%y>0){
    int rem=x%y;
    x=y;
    y=rem; 
    }
    return{y,a*b/y};
}




int main() {
    int a=9;
    int b=9;
    vector<int>ans=fn(a,b);
    cout<<"hcf : "<<ans[0]<<" lcm : "<<ans[1];  
    return 0;
}