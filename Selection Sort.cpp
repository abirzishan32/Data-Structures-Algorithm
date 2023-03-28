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

#define div 1000003
#define mod 1000000007
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

void Swap(int &a, int &b){
    a = a+b;
    b = a-b;
    a = a-b;
}


void findMinIndex(int *ara, int start, int n, int &minIndex){
    minIndex = start;
    for(int i=start+1; i<n; i++){
        if (ara[i] < ara[minIndex]) {
            minIndex = i;
        }
    }
}


void selectionSort(int *ara, int n){
    for(int i=0; i<n; i++){
        int minIndex;
        findMinIndex(ara, i, n, minIndex);
        if (minIndex != i) {
            Swap(ara[i], ara[minIndex]);
        }
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n ;
    cin >> n ;
    int a[n] ;
    for(int i = 0 ; i < n ; i++) cin >> a[i] ;
    selectionSort(a, n);
    for(int i = 0 ; i < n ; i++) cout << a[i] << " " ;
    return 0;
}
