// M graph coloring 

#include <bits/stdc++.h>
using namespace std;




// Optimal O(n^m * n) and O(n + e) where e=no. of edges 
bool isSafe(int node, vector<int>& color, vector<vector<int>>& adj, int col) {
    for (int neighbor : adj[node]) {
        if (color[neighbor] == col) return false;
    }
    return true;
}

bool solve(int node, int n, int m, vector<int>& color, vector<vector<int>>& adj) {
    if (node == n) return true;
    
    for (int col = 1; col <= m; col++) {
        if (isSafe(node, color, adj, col)) {
            color[node] = col;
            if (solve(node + 1, n, m, color, adj)) return true;
            color[node] = 0;
        }
    }
    return false;
}

bool graphColoring(int n, vector<pair<int, int>>& edges, int m) {
    vector<vector<int>> adj(n); // Create adjacency list
    for (auto& edge : edges) {
        adj[edge.first].push_back(edge.second);
        adj[edge.second].push_back(edge.first);
    }
    // Created adjancy list
    // adj[0] = {1, 3};
    // adj[1] = {0, 2};
    // adj[2] = {1, 3};
    // adj[3] = {2, 0};


    vector<int> color(n, 0);
    return solve(0, n, m, color, adj);
}




int main() {
    int n = 4;
    vector<pair<int, int>> edges = {{0, 1}, {1, 2}, {2, 3}, {3, 0}};
    int m = 4;

    if (graphColoring(n, edges, m))
        cout << "Graph can be colored with " << m << " colors." << endl;
    else
        cout << "Graph cannot be colored with " << m << " colors." << endl;

    return 0;
}
