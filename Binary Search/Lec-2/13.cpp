// Median of two sorted arrays

#include <bits/stdc++.h>
using namespace std;




// Brute O(n1 + n2) and O(n1 + n2)
double median(vector<int>& a, vector<int>& b) {
    int n1 = a.size(), n2 = b.size();
    vector<int> arr3;
    int i = 0, j = 0;
    while (i < n1 && j < n2) {
        if (a[i] < b[j]) arr3.push_back(a[i++]);
        else arr3.push_back(b[j++]);
    }
    while (i < n1) arr3.push_back(a[i++]);
    while (j < n2) arr3.push_back(b[j++]);
    int n = n1 + n2;
    if (n % 2 == 1) {
        return (double)arr3[n / 2];
    }

    double median = ((double)arr3[n / 2] + (double)arr3[(n / 2) - 1]) / 2.0;
    return median;
}




// Better O(n1 + n2) and O(1)
double median2(vector<int>& a, vector<int>& b) { 
    int n1 = a.size(), n2 = b.size();
    int n = n1 + n2; 
    int ind2 = n / 2;  
    int ind1 = ind2 - 1; 
    int cnt = 0;
    int ind1el = -1, ind2el = -1;
    int i = 0, j = 0;
    while (i < n1 && j < n2) {  
        if (a[i] < b[j]) {
            if (cnt == ind1) ind1el = a[i];
            if (cnt == ind2) ind2el = a[i]; 
            cnt++; 
            i++; 
        }
        else {
            if (cnt == ind1) ind1el = b[j]; 
            if (cnt == ind2) ind2el = b[j];
            cnt++;
            j++;
        }
    }
    while (i < n1) {
        if (cnt == ind1) ind1el = a[i];
        if (cnt == ind2) ind2el = a[i];
        cnt++;
        i++;
    }
    while (j < n2) {
        if (cnt == ind1) ind1el = b[j];
        if (cnt == ind2) ind2el = b[j];
        cnt++;
        j++;
    }
    if (n % 2 == 1) {
        return (double)ind2el;
    }
    return (double)((double)(ind1el + ind2el)) / 2.0;
}




// Optimal O(log(min(n1,n2))) and O(1)
double median3(vector<int>& a, vector<int>& b) {
    int n1 = a.size(), n2 = b.size();
    //if n1 is bigger swap the arrays:
    if (n1 > n2) return median3(b, a);

    int n = n1 + n2; 
    int left = (n1 + n2 + 1) / 2; 
    int low = 0, high = n1;
    while (low <= high) {
        int c1 = (low + high)/2;
        int c2 = left - c1;
        int l1 =(c1-1<0) ? INT_MIN:a[c1-1]; 
        int l2 =(c2-1<0) ? INT_MIN:b[c2-1];
        int r1 =(c1==n1) ? INT_MAX:a[c1];
        int r2 =(c2==n2) ? INT_MAX:b[c2];

        if (l1 <= r2 && l2 <= r1) {
            if (n % 2 == 1) return max(l1, l2);
            else return ((double)(max(l1, l2) + min(r1, r2))) / 2.0;
        }

        //eliminate the halves:
        else if (l1 > r2) high = c1 - 1;
        else low = c1 + 1;
    }
    return 0; //dummy statement
}




int main(){
    vector<int> a = {1, 4, 9, 10, 12};
    vector<int> b = {2, 3, 6, 15,17};
    cout << "The median of two sorted array is " << fixed << setprecision(2)
         << median(a, b) << '\n';\
    cout << "The median of two sorted array is " << fixed << setprecision(2)
         << median2(a, b) << '\n';
    cout << "The median of two sorted array is " << fixed << setprecision(2)
         << median3(a, b) << '\n';
}

