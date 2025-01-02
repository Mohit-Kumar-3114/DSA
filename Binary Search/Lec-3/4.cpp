// Find peak element (2d matrix)

#include <bits/stdc++.h>
using namespace std;




// Brute (n * m) and O(1)
bool isPeak(const vector<vector<int>>& matrix, int i, int j) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    int up = (i > 0) ? matrix[i - 1][j] : INT_MIN;
    int down = (i < rows - 1) ? matrix[i + 1][j] : INT_MIN;
    int left = (j > 0) ? matrix[i][j - 1] : INT_MIN;
    int right = (j < cols - 1) ? matrix[i][j + 1] : INT_MIN;

    return matrix[i][j] >= up && matrix[i][j] >= down &&
           matrix[i][j] >= left && matrix[i][j] >= right;
}

pair<int, int> findPeakBruteForce(const vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (isPeak(matrix, i, j)) {
                return {i, j}; 
            }
        }
    }
    return {-1, -1}; 
}




// Optimal O(n log m) and O(1)
int findMaxIndex(const vector<vector<int>>& matrix, int n, int col) {
    int maxValue = INT_MIN;
    int index = -1;
    for (int i = 0; i < n; i++) {
        if (matrix[i][col] > maxValue) {
            maxValue = matrix[i][col];
            index = i;
        }
    }
    return index;
}

vector<int> peakOptimal(const vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    int low = 0;
    int high = m - 1;
    
    while (low <= high) {
        int mid = (low + high) / 2;
        int row = findMaxIndex(matrix, n, mid);

        int left = (mid - 1 >= 0) ? matrix[row][mid - 1] : INT_MIN;
        int right = (mid + 1 < m) ? matrix[row][mid + 1] : INT_MIN;

        if (matrix[row][mid] > left && matrix[row][mid] > right) {
            return {row, mid};
        }
        else if (matrix[row][mid] < left) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return {-1, -1};
}




int main() {
    vector<vector<int>> matrix = {
        {10, 8, 10, 10},
        {14, 13, 12, 11},
        {15, 9, 11, 21},
        {16, 17, 19, 20}
    };

    pair<int, int> peakBruteForce = findPeakBruteForce(matrix);
    cout << "Brute Force Peak: (" << peakBruteForce.first << ", " << peakBruteForce.second << ")\n";

    vector<int> peakOptimalAns = peakOptimal(matrix);
    cout << "Optimal Peak: (" << peakOptimalAns[0] << ", " << peakOptimalAns[1] << ")\n";

    return 0;
}
