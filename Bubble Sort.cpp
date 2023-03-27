#include<bits/stdc++.h>
using namespace std;
void swp(int *a , int *b){
    *a ^= *b ^= *a ^= *b ;
}
void bubbleSort(int *a , int n){
    for(int i = 0 ; i < n-1 ; i++){
        for(int j = 0 ; j < n - i - 1 ; j++){
            if(a[j] > a[j+1]) swp(&a[j] , &a[j+1]) ;
        }
    }
}
int main(){
    int n ;
    cin >> n ;
    int a[n] ;
    for(int i = 0 ; i < n ; i++) cin >> a[i] ;
    bubbleSort(a , n) ;
    for(int i = 0 ; i < n ; i++) cout << a[i] << " " ;
}
