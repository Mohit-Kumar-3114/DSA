// Print the matrix in spiral pattern

#include<bits/stdc++.h>
using namespace std;




// Optimal O(n * m) and O(n * m)
vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> ans;
    int sr = 0, sc = 0;
    int er = matrix.size() - 1;
    int ec = matrix[0].size() - 1;

    while (sr <= er && sc <= ec) {
        // Traverse from left to right
        for (int j = sc; j <= ec; j++) {
            ans.push_back(matrix[sr][j]);
        }
        sr++;

        // Traverse from top to bottom
        for (int i = sr; i <= er; i++) {
            ans.push_back(matrix[i][ec]);
        }
        ec--;

        // Traverse from right to left, if still within bounds
        if (sr <= er) {
            for (int j = ec; j >= sc; j--) {
                ans.push_back(matrix[er][j]);
            }
            er--;
        }

        // Traverse from bottom to top, if still within bounds
        if (sc <= ec) {
            for (int i = er; i >= sr; i--) {
                ans.push_back(matrix[i][sc]);
            }
            sc++;
        }
    }
    return ans;
}




int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    vector<int> result = spiralOrder(matrix);
    cout << "Spiral Order: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
