// Find two numbers which are appearing once and other twice

#include <bits/stdc++.h>
using namespace std;  




// Brute O(n) and O(n/2 + 1)
vector<int> FindNum(vector<int>&arr){
    vector<int>ans;
    int n=arr.size();
    unordered_map<int,int>mpp;
    for(int i=0;i<n;i++) mpp[arr[i]]++;
    for(auto el:mpp){
        if(el.second==1) ans.push_back(el.first);
    }
    return ans;
}




// Optimal O(2n) and O(1)
vector<int> FindNum2(vector<int>arr){
    vector<int> ans;
    int xorResult = 0;
    int n = arr.size();

    // Step 1: XOR all elements to get xorResult = a ^ b (where a and b are the two unique numbers)
    for (int i = 0; i < n; i++) {
        xorResult ^= arr[i];
    }

    // Step 2: Find the rightmost set bit in xorResult
    int rightmostSetBit = 0;
    for (int i = 0; i < 32; i++) {
        if ((xorResult >> i) & 1) {
            rightmostSetBit = 1 << i; // Set the bit at position i
            break;
        }
    }

    // Step 3: Divide numbers into two groups and XOR each group
    int num1 = 0, num2 = 0;
    for (int i = 0; i < n; i++) {
        if ((arr[i] & rightmostSetBit) != 0) {
            num1 ^= arr[i];
        } else {
            num2 ^= arr[i];
        }
    }

    ans.push_back(num1);
    ans.push_back(num2);
    return ans;
}




int main(){
    vector<int>arr={4,5,4,5,2,6};
    vector<int>ans=FindNum(arr);
    vector<int>ans2=FindNum2(arr);
    cout<<ans[0]<<" "<<ans[1]<<endl;
    cout<<ans2[0]<<" "<<ans2[1]<<endl;
    return 0;
}