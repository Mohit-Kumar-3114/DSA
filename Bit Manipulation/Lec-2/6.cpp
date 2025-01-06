// Find the number that appears once and other thrice

#include <bits/stdc++.h>
using namespace std;  




// Brute O(n) and O(n/3 + 1)
int FindNum(vector<int>&arr){
    int n=arr.size();
    unordered_map<int,int>mpp;
    for(int i=0;i<n;i++) mpp[arr[i]]++;
    for(auto el:mpp){
        if(el.second==1) return el.first;
    }
    return -1;
}




// Better O(n * 32) and O(1)
int FindNum2(vector<int>arr){
    // Optimal for it number are repeating k times instead of 3
    int n=arr.size();
    int ans=0;
    for(int i=0;i<32;i++){
        int count=0;
        for(int num=0;num<n;num++){
            if((arr[num] & (1 << i) ) != 0) count++;
        }
        if (count % 3 != 0) ans = (ans | (1 << i)); // (count % k != 0) if k is other than 3
    }
    return ans;
}




// Better O(n log n + n/3) and O(log n)
int FindNum3(vector<int>arr){
    // Better than previous approach as n has to be 2^32 so that TC = O(n * 32) which is not always possible 
    sort(arr.begin(),arr.end());
    int n=arr.size();
    for(int i=1;i<n;i+=3){
        if(arr[i]!=arr[i-1]) return arr[i-1];  
    }
    return arr[n-1];
}




// Optimal O(n) and O(1)
int FindNum4(vector<int>arr){
    int ones=0;
    int twos=0;
    for(int i=0;i<arr.size();i++){
        ones=(ones^arr[i]) & (~twos);  
        twos=(twos^arr[i]) & (~ones);
    }
    return ones;
}




int main(){
    vector<int>arr={4,5,4,5,2,5,4};
    int ans=FindNum(arr);
    int ans2=FindNum2(arr);
    int ans3=FindNum3(arr);
    int ans4=FindNum4(arr);
    cout<<ans<<endl;
    cout<<ans2<<endl;
    cout<<ans3<<endl;
    cout<<ans4<<endl;
    return 0;
}