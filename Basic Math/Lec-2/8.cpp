// Check for primes

#include<bits/stdc++.h>
using namespace std;




// Brute O(n) and O(1)
bool prime(int num){
    if(num<2) return false;
    for(int i=2;i<num;i++){
        if(num%i==0) return false;
    }
    return true;
}




// Better O(n/2) and O(1)
bool prime2(int num){
    if(num<2) return false;
    if(num==2) return true; 
    if(num%2==0) return false;
    for(int i=3;i<num;i=i+2){
        if(num%i==0) return false;
    }
    return true;
}




// Optimal O(sqrt(n)/2) and O(1)
bool prime3(int num){
    if(num<2) return false;
    if(num==2) return true; 
    if(num%2==0) return false;
    int last=sqrt(num);
    for(int i=3;i<=last;i=i+2){
        if(num%i==0) return false;
    }
    return true;
}




int main(){
    int num=49;
    cout<<prime(num);
    cout<<endl;
    cout<<prime2(num);
    cout<<endl;
    cout<<prime3(num);
    return 0;
}