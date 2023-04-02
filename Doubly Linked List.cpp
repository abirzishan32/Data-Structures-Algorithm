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

void insertAt(int data, int position) {
    Node *temp = new Node();
    temp->data = data;
    if (position == 1) {
        temp->next = head;
        temp->prev = nullptr;
        if (head != nullptr) {
            head->prev = temp;
        }
        head = temp;
        return;
    }
    Node *temp2 = head;
    for (int i = 0; i < position - 2; i++) {
        temp2 = temp2->next;
    }
    temp->next = temp2->next;
    temp->prev = temp2;
    if (temp2->next != nullptr) {
        temp2->next->prev = temp;
    }
    temp2->next = temp;
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
        if (head == NULL) {
            cout << "Linked list is empty" << endl;
            return;
        }
        if (index == 1) {
            Node *temp = head;
            head = head->next;
            if (head != NULL) {
                head->prev = NULL;
            }
            delete temp;
            return;
        }
        Node *cur = head;
        for(int i=0; i<index-2 && cur->next!= NULL; i++){
            cur = cur->next;
        }
        if (cur->next == NULL) {
            cout<<"Out of bounds"<<endl;
            return;
        }
        
        Node *temp = cur->next;
        cur->next = cur->next->next;
        if (cur->next != NULL) {
            cur->next->prev = cur;
        }
        delete temp;
    }




bool isPalindrome(){
        if (head == NULL){
            cout << "Linked list is empty." << std::endl;
            return false;
        }
        Node *temp = head;
        while (temp->next != NULL){
            temp = temp->next;
        }

        Node *temp2 = head;
        while (temp2 != temp && temp2->next != temp){
            if (temp2->data != temp->data){
                return false;
            }
            temp2 = temp2->next;
            temp = temp->prev;
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
