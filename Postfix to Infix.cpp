#include <cassert>
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cwchar>
#include <cwctype>
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <array>
#include <vector>
#include <atomic>
#include <chrono>
#include <codecvt>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
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
#define pi 3.1415926536
#define div 1000003
#define mod 1000000009
#define MOD 998244353
#define N 10000005
#define fr(i,a,b) for(int i = a;i<b;i++)
#define fri(i,a,b) for(int i = a;i>=b;i--)
#define pb push_back
#define pyn(flag) cout<<(flag?"YES":"NO")<<endl;
#define vin cin>>v[i]
#define vsort sort(v.begin(), v.end())
#define vrev reverse(v.begin(), v.end())
#define yout cout<<"YES"<<endl
#define nout cout<<"NO"<<endl

#define MAX_SIZE 100

class Stack{
private:
    int top;
    char arr[MAX_SIZE];
public:
    Stack(){
        top = -1;
    }
    
    bool empty() { // check if stack is empty
        return top == -1;
    }
    
    
    bool full() { // check if stack is full
        return top == MAX_SIZE - 1;
    }
    
    
    void push(char x) { // push element to top of stack
        if (full()) {
            std::cout << "Error: Stack overflow\n";
            return;
        }
        top++; // move top to next index
        arr[top] = x; // add element to top of stack
    }
    
    
    void pop() { // remove top element from stack
        if (empty()) {
            std::cout << "Error: Stack underflow\n";
            return;
        }
        top--; // move top to previous index
    }
    
    
    char Top() { // get top element of stack without removing it
        if (empty()) {
            std::cout << "Error: Stack underflow\n";
            return -1;
        }
        return arr[top]; // return top element
    }
};

string postfixtoinfix(string &s)
{
    Stack st;
    int n = s.size();
    string ans;
    for (int i = 0; i < n; i++)
    {
        char c = s[i];
        if (c >= 'a' && c <= 'z')
        {
            string ss;
            ss += c;
            int sz = ss.size();
            for(int i=0; i<sz; i++){
                st.push(ss[i]);
            }
        }
        else
        {
            char str1 = st.Top();
            st.pop();
            char str2 = st.Top();
            st.pop();
            string sign;
            sign+=c;
            string ans = "(" + str2 + sign + str1 + ")";
            int sz = ans.size();
            for(int i=0; i<sz; i++){
                st.push(ans[i]);
            }
        }
    }
    ans = st.Top();
    return ans;
}

int main()
{
    string s;
    cin >> s;
    string ans = postfixtoinfix(s);
    cout << ans << endl;

    return 0;
}
