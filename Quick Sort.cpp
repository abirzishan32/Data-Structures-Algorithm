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


void Swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void partition(int *arr, int low, int high, int& pivot_index) {
    int pivot = arr[low];
    int start = low, end = high;
    while(start < end){
        while(arr[start] <= pivot){
            start++;
        }
        while (arr[end] > pivot){
            end--;
        }
        if(start < end){
            Swap(arr[start], arr[end]);
        }
    }
    Swap(arr[low], arr[end]);
    pivot_index = end;
}

void quicksort(int *arr, int low, int high) {
    if (low < high) {
        int pivot_index;
        partition(arr, low, high, pivot_index);
        quicksort(arr, low, pivot_index - 1);
        quicksort(arr, pivot_index + 1, high);
    }
}

int main() {
    int arr[] = {10, 7, 8, 0, 6, -1};
    int n = sizeof(arr) / sizeof(arr[0]);

    quicksort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
