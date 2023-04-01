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
};

class LinkedList {
private:
    Node *head;

public:
    LinkedList() {
        head = nullptr;
    }

    void insertAtHead(int data) {
        Node *newNode = new Node();
        newNode->data = data;
        newNode->next = head;
        head = newNode;
    }
    
    void insertLast(int data) {
            Node *temp = new Node();
            temp->data = data;
            temp->next = NULL;
            if (head == NULL) {
                head = temp;
            } else {
                Node *temp2 = head;
                while (temp2->next != NULL) {
                    temp2 = temp2->next;
                }
                temp2->next = temp;
            }
        }
    
    
    void insertAt(int data, int position) {
            Node *temp = new Node();
            temp->data = data;
            if (position == 1) {
                temp->next = head;
                head = temp;
                return;
            }
            Node *temp2 = head;
            for (int i = 0; i < position - 2; i++) {
                temp2 = temp2->next;
            }
            temp->next = temp2->next;
            temp2->next = temp;
        }
    
    void insertBefore(int data, int targetData) {
            Node *temp = new Node();
            temp->data = data;
            if (head->data == targetData) {
                temp->next = head;
                head = temp;
                return;
            }
            Node *temp2 = head;
            while (temp2->next != NULL && temp2->next->data != targetData) {
                temp2 = temp2->next;
            }
            if (temp2->next == NULL) {
                cout << "Data not found" << endl;
                return;
            }
            temp->next = temp2->next;
            temp2->next = temp;
        }
    
    void insertBefore2 (int value, int target){
        if(head->data == target){
            insertAtHead(value);
            return;
        }
        int cnt=0;
        Node *temp = head;
        while(temp->data != target && temp->next != NULL){
            temp = temp->next;
            cnt++;
        }
        cnt++;
        insertAt(value, cnt);
    }
    
    
    void insertAfter(int data, int targetData) {
            Node *temp = head;
            while (temp != NULL && temp->data != targetData) {
                temp = temp->next;
            }
            if (temp == NULL) {
                cout << "Data not found" << endl;
                return;
            }
            Node *temp2 = new Node();
            temp2->data = data;
            temp2->next = temp->next;
            temp->next = temp2;
        }
    
    
    void insertAfter2 (int value, int target){
        int cnt=0;
        Node *temp = head;
        while(temp->data != target && temp->next != NULL){
            temp = temp->next;
            cnt++;
        }
        if(temp->next == NULL){
            cout<<"Data not found"<<endl;
            return;
        }
        cnt+=2;
        insertAt(value, cnt);

    }
    
    
    
    int countElements() {
            int count = 0;
            Node *temp = head;
            while (temp != NULL) {
                count++;
                temp = temp->next;
            }
            return count;
        }

    void traverse() {
        Node *temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout<<endl;
    }

    
    void printDataAtIndex(int index) {
            Node *temp = head;
            for (int i = 0; i < index && temp != NULL; i++) {
                temp = temp->next;
            }
            if (temp == NULL) {
                cout << "Index out of bounds" << endl;
            } else {
                cout << temp->data << endl;
            }
        }
    
    void swapDataAtIndex(int index1, int index2) {
            Node *temp1 = head, *temp2 = head;
            for (int i = 0; i < index1 && temp1 != NULL; i++) {
                temp1 = temp1->next;
            }
            for (int i = 0; i < index2 && temp2 != NULL; i++) {
                temp2 = temp2->next;
            }
            if (temp1 == NULL || temp2 == NULL) {
                cout << "Index out of bounds" << endl;
            }
            else {
                int t = temp1->data;
                temp1->data = temp2->data;
                temp2->data = t;
            }
        }


    void modeFirstToLast(){
        if (head == nullptr || head->next == nullptr) {
        return;
    }
    Node* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->next = head;
    head = head->next;
    current->next->next = nullptr;
    }



    void deleteAtHead() {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
    
    void deleteLast() {
            if (head == NULL) {
                cout << "Linked list is empty" << endl;
                return;
            }
            if (head->next == NULL) {
                delete head;
                head = NULL;
                return;
            }
            Node *temp = head;
            while (temp->next->next != NULL) {
                temp = temp->next;
            }
            delete temp->next;
            temp->next = NULL;
        }
    
    
    void deleteAtIndex(int index) {
        if (head == NULL) {
            cout << "Linked list is empty" << endl;
            return;
        }
        if (index == 0) {
            Node *temp = head;
            head = head->next;
            delete temp;
            return;
        }
        int count = 0;
        Node *temp = head;
        while (temp != NULL && count < index - 1) {
            temp = temp->next;
            count++;
        }
        if (temp == NULL || temp->next == NULL) {
            cout << "Index out of range" << endl;
            return;
        }
        Node *toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
    }
    
    
    
    int countFrequency(int value) {
            int count = 0;
            Node *temp = head;
            while (temp != NULL) {
                if (temp->data == value) {
                    count++;
                }
                temp = temp->next;
            }
            return count;
        }
    
    
    void sort() {
            Node *i, *j;
            int temp;
            for (i = head; i->next != NULL; i = i->next) {
                for (j = i->next; j != NULL; j = j->next) {
                    if (i->data > j->data) {
                        temp = i->data;
                        i->data = j->data;
                        j->data = temp;
                    }
                }
            }
        }
    
    
    
    void reverseList() {
            Node *prev = NULL;
            Node *curr = head;
            Node *next = NULL;
            
            while (curr != NULL) {
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            head = prev;
        }
    
    
        void removeDuplicates() {
            Node *ptr1 = head;
            Node *ptr2;
            Node *dup;
            while (ptr1 != nullptr && ptr1->next != nullptr) {
                ptr2 = ptr1;
                while (ptr2->next != nullptr) {
                    if (ptr1->data == ptr2->next->data) {
                        dup = ptr2->next;
                        ptr2->next = ptr2->next->next;
                        delete dup;
                    } else {
                        ptr2 = ptr2->next;
                    }
                }
                ptr1 = ptr1->next;
            }
        }
    
    
    //Grouping all odd nodes together followed by the even nodes
    void groupOddEvenNodes() {
        if (head == nullptr || head->next == nullptr) {
            return;
        }

        Node *oddTail = head;
        Node *evenHead = head->next;
        Node *evenTail = evenHead;

        while (evenTail != nullptr && evenTail->next != nullptr) {
            oddTail->next = evenTail->next;
            oddTail = oddTail->next;
            evenTail->next = oddTail->next;
            evenTail = evenTail->next;
        }

        oddTail->next = evenHead;
    }
    
    
    
    //Merging two Linked Lists
    void mergeLists(LinkedList &list1, LinkedList &list2) {
            Node *temp1 = list1.head;
            Node *temp2 = list2.head;
            while (temp1->next != nullptr) {
                temp1 = temp1->next;
            }
            temp1->next = temp2;
        }
    
    
    //Function that will merge two Linked Lists of int, assuming that they are
    //sorted in ascending order. The merged list should be sorted in ascending order
    void mergeSortedLists(LinkedList& list1, LinkedList& list2) {
        Node* curr1 = list1.head;
        Node* curr2 = list2.head;
        Node* prev = nullptr;

        while (curr1 != nullptr && curr2 != nullptr) {
            if (curr1->data < curr2->data) {
                prev = curr1;
                curr1 = curr1->next;
            } else {
                if (prev != nullptr) {
                    prev->next = curr2;
                } else {
                    list1.head = curr2;
                }
                Node* temp = curr2->next;
                curr2->next = curr1;
                prev = curr2;
                curr2 = temp;
            }
        }

        if (curr2 != nullptr) {
            if (prev != nullptr) {
                prev->next = curr2;
            } else {
                list1.head = curr2;
            }
        }
    }
    
    
    
    //Given two linked list, Print the two linked lists into shuffle
    void mergeLinkedListsInShuffle(LinkedList& list1, LinkedList& list2) {
        Node* node1 = list1.head;
        Node* node2 = list2.head;
        Node* prev = nullptr;
        Node* mergedHead = nullptr;

        while (node1 != nullptr && node2 != nullptr) {
            if (mergedHead == nullptr) {
                mergedHead = node1;
                prev = node1;
                node1 = node1->next;
            } else {
                prev->next = node2;
                prev = node2;
                node2 = node2->next;
                prev->next = node1;
                prev = node1;
                node1 = node1->next;
            }
        }

        if (node1 == nullptr) {
            prev->next = node2;
        } else {
            prev->next = node1;
        }

        list1.head = mergedHead;
        list2.head = nullptr;
    }
    
    
    
    //Insert a node into a sorted linked list so that the linked list remain sorted after insertion
    void insertAtSortedArray(int value){
        Node *temp = new Node();
        temp->data = value;
        temp->next = nullptr;
        if (head == nullptr) {
            head = temp;
            return;
        }
        if (value < head->data) {
            temp->next = head;
            head = temp;
            return;
        }
        Node *cur = head;
        while (cur->next != nullptr && cur->next->data < value) {
            cur = cur->next;
        }
        temp->next = cur->next;
        cur->next = temp;
    }
    
    
    
    
    
};

int main(int argc, const char** argv) {
        LinkedList l1;
        l1.insertAtHead(3);
        l1.insertAtHead(1);
        l1.insertAt(2, 3);
        l1.insertLast(5);
        l1.insertBefore(3, 2);
        l1.traverse();
        l1.moveFirstToLast();
        l1.traverse();
        LinkedList l2;
        l2.insertAtHead(4);
        l2.insertLast(6);
        l2.insertAtHead(9);
        l2.insertAt(1, 2);
        l2.insertAfter(2, 6);
        l2.traverse();
        l1.removeDuplicates();
        l1.traverse();
        l2.reverseList();
        l2.traverse();
        l1.mergeLinkedListsInShuffle(l1, l2);
        l1.traverse();
    return 0;
}
