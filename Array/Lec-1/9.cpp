// Find the union of two sorted arrays

#include <bits/stdc++.h>
using namespace std;




// Brute O(n log n + m log m + n + m) and O(n + m)
vector < int > FindUnion(int arr1[], int arr2[], int n, int m) {
  set < int > s;
  vector < int > Union;
  for (int i = 0; i < n; i++) 
    s.insert(arr1[i]);
  for (int i = 0; i < m; i++) 
    s.insert(arr2[i]);
  for (auto & it: s) 
    Union.push_back(it);
  return Union;
}




// Optimal O(m + n) and O(m + n)
vector < int > FindUnion2(int arr1[], int arr2[], int n, int m) { 
  int i = 0, j = 0; 
  vector < int > Union; 
  while (i < n && j < m) {  
    if (arr1[i] <= arr2[j]){ 
      if (Union.size() == 0 || Union.back() != arr1[i])
        Union.push_back(arr1[i]); 
      i++;
    } else {
      if (Union.size() == 0 || Union.back() != arr2[j])
        Union.push_back(arr2[j]);
      j++;
    }
  }

  while (i < n) { 
    if (Union.back() != arr1[i])
      Union.push_back(arr1[i]);
    i++;
  }

  while (j < m){ 
    if (Union.back() != arr2[j])
      Union.push_back(arr2[j]);
    j++;
  }

  return Union;
}




int main(){
  int n = 10, m = 7;
  int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int arr2[] = {2, 3, 4, 4, 5, 11, 12};
  vector < int > Union = FindUnion(arr1, arr2, n, m);
  vector < int > Union2 = FindUnion2(arr1, arr2, n, m);
  cout << "Union of arr1 and arr2 is  " << endl;
  for (auto & val: Union)
    cout << val << " ";
    cout << endl<< "Union of arr1 and arr2 is  " << endl;
  for (auto & val: Union2)
    cout << val << " ";
  return 0;
}


