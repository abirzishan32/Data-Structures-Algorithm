#include<bits/stdc++.h>
using namespace std;
void swp(int *a , int *b){
    *a ^= *b ^= *a ^= *b ;
}
void insertionSort(int *arr , int n){
    int i, key, j;
    for (i = 1; i < n; i++){
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] < key){
            swp(&arr[j + 1],&arr[j]);
            j = j - 1;
        } 
    }
}
int main(){
    int n ;
    cin >> n ;
    int a[n] ;
    for(int i = 0 ; i < n ; i++) cin >> a[i] ;
    insertionSort(a , n) ;
    for(int i = 0 ; i < n ; i++) cout << a[i] << " " ;
}
