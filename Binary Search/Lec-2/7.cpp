// Kth missing posistive number

#include <bits/stdc++.h>
using namespace std;




// Brute O(n) and O(1)
int missingK(vector < int > vec, int n, int k) {
    for (int i = 0; i < n; i++) {
        if (vec[i] <= k) k++; //shifting k
        else break;
    }
    return k;
}




// Optimal O(log n) and O(1)
int missingK2(vector < int > vec, int n, int k) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        int missing = vec[mid] - (mid + 1);
        if (missing < k) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return k + high + 1; // low+k
}




int main(){
    vector<int> vec = {4, 7, 9, 10};
    int n = 4, k = 4;
    int ans = missingK(vec, n, k);
    cout << "The missing number is: " << ans << "\n";
    int ans2 = missingK2(vec, n, k);
    cout << "The missing number is: " << ans2 << "\n";
    return 0;
}

