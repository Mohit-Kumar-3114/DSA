// Koko eating bananas

#include <bits/stdc++.h>
using namespace std;




int findMax(vector<int> &v) {
    int maxi = INT_MIN;
    int n = v.size();
    for (int i = 0; i < n; i++) {
        maxi = max(maxi, v[i]);
    }
    return maxi;
}

int calculateTotalHours(vector<int> &v, int hourly) {
    int totalH = 0;
    int n = v.size();
    for (int i = 0; i < n; i++) {
        // totalH += ceil((double)(v[i]) / (double)(hourly));
         totalH += v[i] / hourly; // without ceil
         if(v[i]%hourly!=0) totalH++;
    }
    return totalH;
}




// Brute O(maxi * n) and O(1)
int minimumRateToEatBananas(vector<int> v, int h) {
    int maxi = findMax(v);
    for (int i = 1; i <= maxi; i++) {
        int reqTime = calculateTotalHours(v, i);
        if (reqTime <= h) {
            return i;
        }
    }
    return maxi;
}




// Optimal O(log maxi * n) and O(1)
int minimumRateToEatBananas2(vector<int> v, int h) {
    int low = 1, high = findMax(v);
    int ans=high;
    while (low <= high) {
        int mid = (low + high) / 2;
        int totalH = calculateTotalHours(v, mid);
        if (totalH <= h) {
            ans=mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return ans;
}




int main(){
    vector<int> v = {30,11,23,4,20};
    int h = 6;
    int ans = minimumRateToEatBananas(v, h);
    int ans2 = minimumRateToEatBananas2(v, h);
    cout << "Koko should eat atleast " << ans << " bananas/hr.\n";
    cout << "Koko should eat atleast " << ans2 << " bananas/hr.\n";
    return 0;
}

