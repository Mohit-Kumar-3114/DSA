// Print prime factor of a number

#include<bits/stdc++.h>
using namespace std;




// Brute O(sqrt(n) * 2 * (sqrt(n)/2)) and O(no. of prime factors)
bool prime(int num){
    if(num<2) return false;
    if(num==2) return true; 
    if(num%2==0) return false;
    int last=sqrt(num);
    for(int i=3;i<=last;i=i+2){
        if(num%i==0) return false;
    }
    return true;
}

vector<int>fn(int num){
    vector<int>ans;
    for(int i=2;i<=sqrt(num);i++){
        if(num%i==0){
        if(prime(i)) ans.push_back(i);
        if(prime(num/i)){
        if(i!=num/i) ans.push_back(num/i);
        } 
        }
    }
    return ans;
}




// Better O(log n * sqrt(n)) and O(no. of prime factors)
vector<int>fn2(int num){
  vector<int>ans;
  for(int i=2;i<=sqrt(num);i++){
  if(num%i==0){
  ans.push_back(i);
  while(num%i==0)num=num/i;
  }
  }
  return ans;
}




int main(){
    int num=31;
    vector<int>ans=fn(num);
    for(int x:ans)cout<<x<<" ";
    cout<<endl;
    vector<int>ans2=fn2(num);
    for(int x:ans2)cout<<x<<" ";
    return 0;
}