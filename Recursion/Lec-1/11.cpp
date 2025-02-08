// Tower of hanoi

#include <bits/stdc++.h>
using namespace std;




// Optimal O(2^n) and O(n)
void towerOfHanoi(int source, int target, int helper, int n , int &steps){

// Base case
if(n==0) return;

// Move n-1 disk from source to helper tower using destination tower
towerOfHanoi(source,helper,target,n-1,steps);

// Move base disk from source tower to destination tower
steps++;
cout<<"step "<< steps<< ": " << "Move disk " << n << " from tower " <<source<<" to tower "<<target<<endl;

// Move n-1 disks from helper tower to target tower using source
towerOfHanoi(helper,target,source,n-1,steps);
}




int main (){
    int n=3;
    int steps=0;
    towerOfHanoi(1,2,3,n,steps);
    cout << "Number of steps : " << steps<<endl;
    return 0;
}