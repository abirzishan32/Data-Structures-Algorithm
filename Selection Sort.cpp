#include<bits/stdc++.h>
using namespace std;


void Swap(int &a , int &b){
    a = a+b;
    b = a-b;
    a = a-b;
}
void bubbleSort(int *ara , int n){
    for(int i = 0 ; i < n-1 ; i++){
        bool flag=false;
        for(int j = 0 ; j < n - i - 1 ; j++){
            if(ara[j] > ara[j+1]) {
                Swap(ara[j] , ara[j+1]);
                flag=true;
            }
        }
        if(!flag){
            break;
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
  bubbleSort(a , n) ;
  for(int i = 0 ; i < n ; i++) cout << a[i] << " " ;
  return 0;
}
