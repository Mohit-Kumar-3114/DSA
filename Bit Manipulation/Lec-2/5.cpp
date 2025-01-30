// Divide two integers without using multiplication, division and mod operator

#include <bits/stdc++.h>
using namespace std;  




// Brute O(dividend) and O(1)
int Divide(int dividend,int divisor){ 
    if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
    }
    bool flag=true;
    if(dividend<0 and divisor>0) flag=false;
    if(dividend>=0 and divisor<0) flag=false;
    long long  n=abs(dividend); // if dividend is 2^-31 then abs = 2^31 which is overflow for int, so use long
    long long  d=abs(divisor); // if divisor is 2^-31 then abs = 2^31 which is overflow for int, so use long
    long long ans=0;
    long long sum=0;
    while(sum+d<=n){
        ans++;
        sum+=d;
    }
    return flag ? ans : -ans; 
}




// Optimal O(log dividend) and O(1)
int Divide2(int dividend,int divisor){
    if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
    }
    if(dividend==divisor) return 1;
    bool flag=true;
    if(dividend<0 and divisor>0) flag=false;
    if(dividend>=0 and divisor<0) flag=false;
    long long  n=abs(dividend); // if dividend is 2^-31 then abs = 2^31 which is overflow for int, so use long
    long long  d=abs(divisor); // if divisor is 2^-31 then abs = 2^31 which is overflow for int, so use long
    long long ans=0;
    while(n>=d){
        int count=0;
        while(n>=(d << (count+1))){ // n >= d*2^(count+1)
        count++;
        }
        ans+= (1 << count); // ans+=2^count
        n=n-(d << count);
    }
    return flag ? ans : -ans; 
}




int main(){
    int dividend=-22;
    int divisor=3;
    int ans=Divide(dividend,divisor);
    int ans2=Divide2(dividend,divisor);
    cout<<ans<<endl;
    cout<<ans2<<endl;
    return 0;
}