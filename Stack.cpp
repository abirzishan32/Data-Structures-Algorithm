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


#define MAX_SIZE 100 // maximum size of stack

class Stack {
private:
    int top; // index of the top element
    int arr[MAX_SIZE]; // array to store stack elements
public:
    Stack() { // constructor to initialize stack
        top = -1; // empty stack
    }


    bool is_empty() { // check if stack is empty
        return top == -1;
    }


    bool is_full() { // check if stack is full
        return top == MAX_SIZE - 1;
    }


    void push(int x) { // push element to top of stack
        if (is_full()) {
            std::cout << "Error: Stack overflow\n";
            return;
        }
        top++; // move top to next index
        arr[top] = x; // add element to top of stack
    }


    void pop() { // remove top element from stack
        if (is_empty()) {
            std::cout << "Error: Stack underflow\n";
            return;
        }
        top--; // move top to previous index
    }


    int peek() { // get top element of stack without removing it
        if (is_empty()) {
            std::cout << "Error: Stack underflow\n";
            return -1;
        }
        return arr[top]; // return top element
    }



    void print() { // print all elements in stack
        std::cout << "Stack: ";
        for (int i = 0; i <= top; i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << endl;
    }
};



int main(int argc, const char** argv) {
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.print();
    s.pop();
    s.print();
    s.push(4);
    cout<<s.peek();
    return 0;
}
