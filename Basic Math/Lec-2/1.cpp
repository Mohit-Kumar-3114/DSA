// Count digits

#include<bits/stdc++.h>
using namespace std;




// Optimal O(log n) and O(1)
int countDigit(int a){
    int count=0;
    while(a>0){
        count++;
        a=a/10;
    }
    return count;
}




int main() {
    int a=67879809;
    cout<<"No. of digits : "<<countDigit(a);  
    return 0;
}