#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<string, string> pss;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef vector<ll> vl;
typedef vector<vl> vvl;

#define pb push_back
#define N 10000005
#define div 1000003
#define mod 1000000007
#define MOD 998244353
#define fr(i,a,b) for(int i = a;i<b;i++)
#define fri(i,a,b) for(int i = a;i>=b;i--)
#define pyn(flag) cout<<(flag?"YES":"NO")<<endl;
#define vrev reverse(v.begin(), v.end())
#define vin cin>>v[i]
#define vsort sort(v.begin(), v.end())
#define yout cout<<"YES"<<endl
#define nout cout<<"NO"<<endl;

class Node {
public:
    int data;
    Node *next;
    Node *prev;
};

class DoublyLinkedList {
private:
    Node *head;

public:
    DoublyLinkedList() {
        head = nullptr;
    }
    
    void insertAtHead(int value) {
        Node *newNode = new Node();
        newNode->data = value;
        newNode->next = head;
        newNode->prev = nullptr;

        if (head != nullptr) {
            head->prev = newNode;
        }

        head = newNode;
    }

    void insertAtLast(int value) {
    Node *newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;
    newNode->prev = nullptr;

    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node *temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}

void insertAtPosition(int value, int pos) {
    Node *newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    
    if (head == nullptr) {
        head = newNode;
        return;
    }
    
    if (pos == 0) {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        return;
    }
    
    Node *current = head;
    int i = 0;
    while (current->next != nullptr && i < pos - 1) {
        current = current->next;
        i++;
    }
    
    if (current->next == nullptr) {
        current->next = newNode;
        newNode->prev = current;
    } 
    else {
        newNode->next = current->next;
        newNode->prev = current;
        current->next->prev = newNode;
        current->next = newNode;
    }
}

void deleteHead() {
    if (head == nullptr) {  // if list is empty, return
        return;
    }
    if (head->next == nullptr) {  // if list has only one node
        delete head;
        head = nullptr;
        return;
    }
    Node *newHead = head->next;
    newHead->prev = nullptr;
    delete head;
    head = newHead;
}

void deleteLast() {
    if (head == nullptr) {  // if list is empty, return
        return;
    }
    if (head->next == nullptr) {  // if list has only one node
        delete head;
        head = nullptr;
        return;
    }
    Node *current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->prev->next = nullptr;
    delete current;
}

void deleteAtIndex(int index) {
    if (head == nullptr) {  // if list is empty, return
        return;
    }
    Node *current = head;
    int i = 0;
    while (i < index && current != nullptr) {
        current = current->next;
        i++;
    }
    if (current == nullptr) {  // if index is out of bounds, return
        return;
    }
    if (current == head) {  // if index is 0
        head = current->next;
    }
    if (current->prev != nullptr) {
        current->prev->next = current->next;
    }
    if (current->next != nullptr) {
        current->next->prev = current->prev;
    }
    delete current;
}



bool isPalindrome(Node *head) {
    if (!head) return true;
    
    Node *slow = head, *fast = head;
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node *secondHalf = slow->next;
    slow->next = nullptr;

    Node *prev = nullptr, *current = secondHalf;
    while (current) {
        Node *next = current->next;
        current->next = prev;
        current->prev = next;
        prev = current;
        current = next;
    }

    while (prev && head) {
        if (prev->data != head->data) return false;
        prev = prev->prev;
        head = head->next;
    }

    return true;
}

void reverseList() {
        Node *curr = head;
        Node *temp = nullptr;
        while (curr != nullptr) {
            temp = curr->prev;
            curr->prev = curr->next;
            curr->next = temp;
            curr = curr->prev;
        }
        if (temp != nullptr) {
            head = temp->prev;
        }
    }


    void traverse() {
    Node *temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
};
