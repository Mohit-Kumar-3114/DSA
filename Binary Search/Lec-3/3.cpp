// Search in a row and column wise sorted matrix

#include <bits/stdc++.h>
using namespace std;




// Brute O(n * m) and O(1)
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int n = matrix.size(), m = matrix[0].size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == target)
                return true;
        }
    }
    return false;
}




// Better O(n * log m) and O(1)
bool binarySearch(vector<int>& nums, int target) {
    int n = nums.size(); 
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (nums[mid] == target) return true;
        else if (target > nums[mid]) low = mid + 1;
        else high = mid - 1;
    }
    return false;
}

bool searchMatrix2(vector<vector<int>>& matrix, int target) {
    int n = matrix.size();
    int m = matrix[0].size();
    for (int i = 0; i < n; i++) {
        bool flag =  binarySearch(matrix[i], target);
        if (flag) return true;
    }
    return false;
}




// Optimal O(n + m) and O(1)
bool searchMatrix3(vector<vector<int>>& matrix, int target) {
    int n = matrix.size();
    int m = matrix[0].size();
    int row=0;
    int col=m-1;
    while (row<n and col>=0) {
        if (matrix[row][col] == target) return true;
        else if (matrix[row][col] < target) row++;
        else col--;
    }
    return false;
}




int main(){
    vector<vector<int>> matrix = {{1, 4, 7, 11, 15}, {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };
    searchMatrix(matrix, 8) == true ? cout << "true\n" : cout << "false\n";
    searchMatrix2(matrix, 8) == true ? cout << "true\n" : cout << "false\n";
    searchMatrix3(matrix, 8) == true ? cout << "true\n" : cout << "false\n";
}