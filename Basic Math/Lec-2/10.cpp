// Sieve of eratosthenes

#include<bits/stdc++.h>
using namespace std;




// Brute O((sqrt(n))/2 * n/2) and O(no. of prime)
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
    if(num>2) ans.push_back(2);
    for(int i=3;i<=num;i+=2){
        if(prime(i)) ans.push_back(i);
    }
    return ans;
}




// Optimal O(n log log n) and O(n)
vector<int>fn2(int num){
    vector<int>ans;
    int arr[num+1]={0};
    arr[2]=1;
    for(int i=3;i<=num;i+=2){
        arr[i]=1;
    } 
    for(int i=3;i*i<=num;i+=2){ 
    if(arr[i]==0)continue;
    for(int j=i*i;j<=num;j+=i*2){ 
        arr[j]=0;
    }
    }
    for(int i=0;i<=num;i++){
        if(arr[i]==1) ans.push_back(i);
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