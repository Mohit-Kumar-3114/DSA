// Write a program to print n natural number

#include <bits/stdc++.h>
using namespace std;  




// Optimal O(n) and O(n)
void print(int n){ 
if(n==0) return;
print(n-1);
cout<<n<<" ";
}




int main(){
    int n=5;
    print(n);
    return 0;
}