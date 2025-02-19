// Find pairs with given sum in doubly linked list

#include <bits/stdc++.h>
using namespace std;




class Node {
    public:
    int data;
    Node* next;
    Node* prev;
    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};




// Optimal O(n) and O(1)
vector<pair<int, int>> findPairsWithGivenSum(Node* head, int target) {
    if (!head || !head->next) return {};
    Node* t1 = head;
    while (t1->next) {
        t1 = t1->next;
    }
    Node* t2 = head;
    vector<pair<int, int>> ans;
    while (t2->data < t1->data) {
        int sum = t1->data + t2->data;
        if (sum == target) {
            ans.push_back({t2->data, t1->data});
            t2 = t2->next;
            t1 = t1->prev;
        } 
        else if (sum < target) {
            t2 = t2->next;
        } 
        else {
            t1 = t1->prev;
        }
    }
    return ans;
}




int main() {
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);
    Node* fifth = new Node(5);
    Node* sixth = new Node(6);
    Node* seventh = new Node(7);
    Node* eighth = new Node(8);
    Node* ninth = new Node(9);

    head->next = second; second->prev = head;
    second->next = third; third->prev = second;
    third->next = fourth; fourth->prev = third;
    fourth->next = fifth; fifth->prev = fourth;
    fifth->next = sixth; sixth->prev = fifth;
    sixth->next = seventh; seventh->prev = sixth;
    seventh->next = eighth; eighth->prev = seventh;
    eighth->next = ninth; ninth->prev = eighth;

    cout << "Doubly Linked List: ";
    Node* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    int target = 7;
    vector<pair<int, int>> result = findPairsWithGivenSum(head, target);
    cout << "Pairs with sum " << target << ": ";
    for (auto& p : result) {
        cout << "(" << p.first << ", " << p.second << ") ";
    }
    cout << endl;
    return 0;
}
