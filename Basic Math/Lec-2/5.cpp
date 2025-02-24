// Armstrong number

#include<bits/stdc++.h>
using namespace std;




// Optimal O(1) and O(1)
bool isArmStrong(int num){
int temp=0;
int n=num;
while(num>0){
    int rem=num%10;
    temp=temp+rem*rem*rem;
    num=num/10;
}
return n==temp;
}




int main() {
    int num=154;
    cout<<isArmStrong(num);
    return 0;
}