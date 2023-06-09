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
        Node *temp = new Node();
        temp->data = data;
        temp->next = head;
        head = temp;
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
        while(temp->data != target){
            temp = temp->next;
            cnt++;
            if (temp->next == NULL) {
                cout<<"Target value not found"<<endl;
                return;
            }
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
        while(temp->data != target){
            temp = temp->next;
            cnt++;
            if(temp->next == NULL){
                cout<<"Target data not found"<<endl;
                return;
            }
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
            while (temp->next->next != NULL) { //By writing temp->next->next != NULL, we want to point the node previous of the last node. So after
                temp = temp->next;              //the end of the loop, temp will point to the second last node of the linked list
            }
            delete temp->next;                 //temp is pointing to the second last element of the ll. So by deleting temp->next, we are trying to delete 
            temp->next = NULL;                 //the last element of the ll. Then we will make the next of temp (the current last element after deletion) as nullptr.
        }
    
    
   void deleteAtIndex(int index) {
        if (head == NULL) {
            cout << "Linked list is empty" << endl;
            return;
        }
        if (index == 1) {
            Node *temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node *cur = head;
        for(int i=0; i<index-2 && cur!= NULL; i++){
            cur = cur->next;
        }
        if (cur == NULL) {
            cout<<"Out of bounds"<<endl;
            return;
        }
        
        Node *temp = cur->next;
        cur->next = cur->next->next;
        delete temp;
    }
    
    void deleteValue (int target){
        Node *temp = head;
        if (temp->data == target) {
            head = head->next;
            delete temp;
            return;
        }
        while (temp->next != NULL && temp->next->data != target) {
            temp = temp->next;
        }
        if(temp->next == nullptr){
            cout<<"Target not found"<<endl;
            return;
        }
        Node *toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
    }
    
    void deleteValue2 (int target){
        Node *cur = head;
        int index = 1;
        while (cur->data != target && cur->next != NULL) {
            cur = cur->next;
            index++;
        }
        if (cur->next == NULL) {
            cout<<"Not found"<<endl;
            return;
        }
        deleteAtIndex(index);
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
    
    LinkedList splitingLinkedList(int index){
        Node *cur = head;
        int count=1;
        while (cur!=NULL && count<index) {
            cur = cur->next;
            count++;
        }
        
        Node *split;
        split = cur->next;
        cur-> next = nullptr;
        LinkedList list;
        while (split != NULL) {
            list.insertLast(split->data);
            split = split->next;
        }
       return list;
        
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
            Node *next = NULL;
            
            while (head != NULL) {
                next = head->next;
                head->next = prev;
                prev = head;
                head = next;
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
    
    
    Node* mergeSortedLists2(Node* h1, Node* h2){
        if (h1 == nullptr) {
            return h2;
        }
        if (h2 == nullptr) {
            return h1;
        }
        
        if (h1-> data < h2->data) {
            h1->next = mergeSortedLists2(h1->next, h2);
            return h1;
        }
        else{
            h2->next = mergeSortedLists2(h1, h2->next);
            return h2;
        }
        
    }
    
    Node* mergeSortedLists3(Node* listA, Node* listB) {
        Node* temp = new Node();
        Node* tail = temp;

        while (true) {
            if (listA == nullptr) {
                tail->next = listB;
                break;
            }
            if (listB == nullptr) {
                tail->next = listA;
                break;
            }

            if (listA->data <= listB->data) {
                tail->next = listA;
                listA = listA->next;
            }
            else {
                tail->next = listB;
                listB = listB->next;
            }

            tail = tail->next;
        }
        return temp->next;
    }
    
    
    //Given two linked list, Print the two linked lists into shuffle   
    void mergeLinkedListsInShuffle(LinkedList l1, LinkedList l2)
    {
        Node *p = l1.head;
        Node *q = l2.head;
        Node *p_curr = p, *q_curr = q;
        Node *p_next, *q_next;
      
        // While there are available positions in p
        while (p_curr != NULL && q_curr != NULL)
        {
            // Save next pointers
            p_next = p_curr->next;
            q_next = q_curr->next;
      
            // Make q_curr as next of p_curr
            q_curr->next = p_next; // Change next pointer of q_curr
            p_curr->next = q_curr; // Change next pointer of p_curr
      
            // Update current pointers for next iteration
            p_curr = p_next;
            q_curr = q_next;
        }
      
        q = q_curr; // Update head pointer of second list
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
        LinkedList mergedList;
        Node* result = mergedList.mergeLinkedList(l1.head, l2.head);
        Node* current = result;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        l1.mergeLinkedListsInShuffle(l1, l2);
        l1.traverse();
        LinkedList second;
        second = l1.splitingLinkedList(3);
        l1.traverse();
        second.traverse();
    return 0;
}
