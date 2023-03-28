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
    Node* next;
};

class CircularLinkedList {
private:
    Node* head;

public:
    CircularLinkedList() {
        head = nullptr;
    }

    void insertAtBeginning(int val) {
        Node* newNode = new Node();
        newNode->data = val;
        newNode->next = nullptr;
        if (head == nullptr) {
            head = newNode;
            head->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
            head = newNode;
        }
    }

    void insertAtEnd(int val) {
        Node* newNode = new Node();
        newNode->data = val;
        newNode->next = nullptr;
        if (head == nullptr) {
            head = newNode;
            head->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
    }

    void deleteAtBeginning() {
        if (head == nullptr) {
            cout << "List is empty" << endl;
        } else if (head->next == head) {
            delete head;
            head = nullptr;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = head->next;
            Node* toDelete = head;
            head = head->next;
            delete toDelete;
        }
    }

    void deleteAtEnd() {
        if (head == nullptr) {
            cout << "List is empty" << endl;
        } else if (head->next == head) {
            delete head;
            head = nullptr;
        } else {
            Node* temp = head;
            while (temp->next->next != head) {
                temp = temp->next;
            }
            Node* toDelete = temp->next;
            temp->next = head;
            delete toDelete;
        }
    }

    void printList() {
        if (head == nullptr) {
            cout << "List is empty" << endl;
        } else {
            Node* temp = head;
            do {
                cout << temp->data << " ";
                temp = temp->next;
            } while (temp != head);
            cout << endl;
        }
    }
};


int main() {
    CircularLinkedList list;

    // Inserting nodes at the beginning of the list
    list.insertAtBeginning(1);
    list.insertAtBeginning(2);
    list.insertAtBeginning(3);

    // Inserting nodes at the end of the list
    list.insertAtEnd(4);
    list.insertAtEnd(5);
    list.insertAtEnd(6);

    // Printing the list
    cout << "Original List: ";
    list.printList();

    // Deleting nodes from the beginning of the list
    list.deleteAtBeginning();
    list.deleteAtBeginning();

    // Deleting nodes from the end of the list
    list.deleteAtEnd();
    list.deleteAtEnd();

    // Printing the list after deletion
    cout << "Modified List: ";
    list.printList();

    return 0;
}
