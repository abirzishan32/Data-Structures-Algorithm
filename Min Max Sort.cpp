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

void swp(int &a , int &b){
    a ^= b ^= a ^= b ;
}


void findMinMax (int *ara, int n, int start, int end, int &minIndex, int &maxIndex){
    minIndex = start;
    maxIndex = start; 
    for(int i=start; i<=end; i++){
        if(ara[i] < ara[minIndex]){
            minIndex = i;
        }
        else if(ara[i] > ara[maxIndex]){
            maxIndex = i;
        }
    }
}

void minMaxSort(int *ara, int n)
{
    for(int i=0, j=n-1; i<j; i++, j--){
        int minIndex, maxIndex;
        findMinMax(ara, n, i, j, minIndex, maxIndex);
        if(minIndex != i){
            swp(ara[i], ara[minIndex]);
        }
        if(maxIndex == i){
            maxIndex = minIndex;
        }
        if(maxIndex != j){
            swp(ara[j], ara[maxIndex]);
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
    minMaxSort(a, n);
    for(int i = 0 ; i < n ; i++) cout << a[i] << " " ;
  return 0;
}
