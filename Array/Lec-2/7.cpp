// Rearrange the array in alternating positive and negative items

#include <bits/stdc++.h>
using namespace std;




// Optimal O(2n) and O(n)
void rearrangeArray(vector<int>& nums) { 
    vector<int> positives, negatives;
    for (int num : nums) {
        if (num >= 0) {
            positives.push_back(num); 
        } else {
            negatives.push_back(num); 
        }
    }
    int i = 0, j = 0;
    int index=0;
    while (i < positives.size() && j < negatives.size()) {  
        nums[index] = positives[i];  
        index++; 
        nums[index] = negatives[j]; 
        index++;
        i++;
        j++;
    }

    while (i < positives.size()) { 
        nums[index] = positives[i];
        index++;
        i++;
    }

    while (j < negatives.size()) { 
        nums[index] = negatives[j];
        index++;
        j++;
    }
}




int main() {
    vector<int> nums = {9 ,4, -2, -1, 5, 0, 5, 3, 2}; 
    rearrangeArray(nums);
    cout << "Rearranged array: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
