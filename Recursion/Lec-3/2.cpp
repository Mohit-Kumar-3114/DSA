// Word search

#include <bits/stdc++.h>
using namespace std;




// Optimal O(m * n * 4^k) and O(m * n) where k=length of word
bool findWordHelper(int i, int j, vector<vector<char>> &board, string &word, int index, vector<vector<int>> &vis) {
    if (index == word.size()) {
        return true;
    }
    
    int n = board.size();
    int m = board[0].size();
    
    if (i < 0 || j < 0 || i >= n || j >= m || vis[i][j]==1 || board[i][j] != word[index]) {
        return false;
    }
    
    vis[i][j] = 1;
    
    // Move in all 4 directions
    bool found = findWordHelper(i + 1, j, board, word, index + 1, vis) ||
                 findWordHelper(i - 1, j, board, word, index + 1, vis) ||
                 findWordHelper(i, j + 1, board, word, index + 1, vis) ||
                 findWordHelper(i, j - 1, board, word, index + 1, vis);
    
    vis[i][j] = 0; // Backtrack
    return found;
}

bool exist(vector<vector<char>> &board, string word) {
    int n = board.size();
    int m = board[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == word[0] && findWordHelper(i, j, board, word, 0, vis)) {
                return true;
            }
        }
    }
    return false;
}




int main() {
    vector<vector<char>> board = {{'A', 'B', 'C', 'E'},
                                  {'S', 'F', 'C', 'S'},
                                  {'A', 'D', 'E', 'E'}};
    string word = "ABCCED";
    
    cout << (exist(board, word) ? "True" : "False") << endl;
    
    return 0;
}
