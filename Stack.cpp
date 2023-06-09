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
    

  

bool isBalanced(string parentheses) {
    stack<char> s;
    for (char c : parentheses) {
        if (c == '(' || c == '[' || c == '{') {
            s.push(c);
        } else if (c == ')' || c == ']' || c == '}') {
            if (s.empty()) {
                return false;
            } else if ((c == ')' && s.top() == '(') ||
                       (c == ']' && s.top() == '[') ||
                       (c == '}' && s.top() == '{')) {
                s.pop();
            } else {
                return false;
            }
        }
    }
    return s.empty();
}
    
    
    int evaluatePostfix(const string& expression) {
    stack<int> operands;

    for (char ch : expression) {
        if (isdigit(ch)) {
            // Convert the character to integer and push onto the stack
            operands.push(ch - '0');
        } else {
            // Operator encountered, perform operation on operands
            int operand2 = operands.top();
            operands.pop();

            int operand1 = operands.top();
            operands.pop();

            int result;
            if (ch == '+') {
                result = operand1 + operand2;
            } else if (ch == '-') {
                result = operand1 - operand2;
            } else if (ch == '*') {
                result = operand1 * operand2;
            } else if (ch == '/') {
                result = operand1 / operand2;
            }
            // Handle any other operators if necessary

            // Push the result back onto the stack
            operands.push(result);
        }
    }

    // The final result will be at the top of the stack
    return operands.top();
}
    
    int evaluatePrefix(const string& expression) {
    stack<int> operands;

    // Read the expression in reverse order
    for (int i = expression.length() - 1; i >= 0; i--) {
        char ch = expression[i];

        if (isdigit(ch)) {
            // Convert the character to integer and push onto the stack
            operands.push(ch - '0');
        } else {
            // Operator encountered, perform operation on operands
            int operand1 = operands.top();
            operands.pop();

            int operand2 = operands.top();
            operands.pop();

            int result;
            if (ch == '+') {
                result = operand1 + operand2;
            } else if (ch == '-') {
                result = operand1 - operand2;
            } else if (ch == '*') {
                result = operand1 * operand2;
            } else if (ch == '/') {
                result = operand1 / operand2;
            }
            // Handle any other operators if necessary

            // Push the result back onto the stack
            operands.push(result);
        }
    }

        // The final result will be at the top of the stack
        return operands.top();
    }
    
    
vector<int> findNextGreater(const vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n, -1);  // Initialize result vector with -1
    stack<int> st;

    for (int i = 0; i < n; i++) {
        while (!st.empty() && nums[i] > nums[st.top()]) {
            // nums[i] is the next greater element for elements at indices stored in the stack
            result[st.top()] = nums[i];
            st.pop();
        }
        // Push the current index onto the stack
        st.push(i);
    }

    return result;
}
    
    vector<int> findNextSmaller(const vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n, -1);  // Initialize result vector with -1
    stack<int> st;

    for (int i = 0; i < n; i++) {
        while (!st.empty() && nums[i] < nums[st.top()]) {
            // nums[i] is the next smaller element for elements at indices stored in the stack
            result[st.top()] = nums[i];
            st.pop();
        }
        // Push the current index onto the stack
        st.push(i);
    }

    return result;
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
