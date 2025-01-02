// Rotate matrix by 90 degree

#include<bits/stdc++.h>
using namespace std;




// Brute O(n^2) and O(n^2)
vector < vector < int >> rotate(vector < vector < int >> & matrix) {
    int n = matrix.size();
    vector < vector < int >> rotated(n, vector < int > (n, 0));
    for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {  
        rotated[j][n - i - 1] = matrix[i][j];
    }
    }
    return rotated;
}




// Optimal O(n^2) and O(1)
void rotate2(vector < vector < int >> & matrix) {
    int n = matrix.size();
    for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) { 
        swap(matrix[i][j], matrix[j][i]);
    }
    }
    for (int i = 0; i < n; i++) {
    reverse(matrix[i].begin(), matrix[i].end());
    }
}




int main() {
    vector < vector < int >> arr;
    arr =  {{1, 2, 3},  
            {4, 5, 6},     
            {7, 8, 9}}; 
    vector < vector < int >> rotated = rotate(arr);
    vector < vector < int >> arr2;
    arr2 =  {{1, 2, 3}, 
            {4, 5, 6},  
            {7, 8, 9}}; 
    rotate2(arr2);
    cout << "Rotated Image" << endl;
    for (int i = 0; i < rotated.size(); i++) {
    for (int j = 0; j < rotated[0].size(); j++) {
        cout << rotated[i][j] << " ";
    }
    cout << endl;
    }
    cout << "Rotated Image" << endl;
    for (int i = 0; i < arr2.size(); i++) {
    for (int j = 0; j < arr2[0].size(); j++) {
        cout << arr2[i][j] << " ";
    }
    cout << endl;
    }
    return 0;
}

