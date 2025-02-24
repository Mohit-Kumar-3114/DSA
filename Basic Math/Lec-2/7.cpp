// Power exponential

#include<bits/stdc++.h>
using namespace std;




// Brute O(p) and O(1)
double exp(int n, int p){
    if(p==0) return 1;
    int temp=abs(p);
    double ans=1;
    for(int i=1;i<=temp;i++){
    ans=ans*n;
    }
    return p>0? ans: 1.0/ans;
}




// Optimal O(log p) and O(1)
double exp2(int n, int p){
    if(p==0) return 1;
    int temp=abs(p);
    double ans=1;
    while(temp>0){
        if(temp%2==1){
            ans=ans*n; 
            temp=temp-1; 
        }
        else {
            temp=temp/2;
            n=n*n;
        }
    }
    return p>0? ans: 1.0/ans;
}




int main(){
    int n=3;
    int p=-9;
    cout<<"n^p = "<<exp(n,p);
    cout<<endl;
    cout<<"n^p = "<<exp2(n,p);
    return 0;
}