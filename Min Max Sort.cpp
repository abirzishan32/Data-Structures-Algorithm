#include<bits/stdc++.h>
using namespace std;
void swp(int &a , int &b){
    a ^= b ^= a ^= b ;
}
void selectMinMax(int arr[], int n, int &minIndex, int &maxIndex) {
    minIndex = maxIndex = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[minIndex]) {
            minIndex = i;
        }
        if (arr[i] > arr[maxIndex]) {
            maxIndex = i;
        }
    }
}

void minMaxSelectionSort(int arr[], int n) {
    for (int i = 0; i < n/2; i++) {
        int minIndex, maxIndex;
        selectMinMax(arr + i, n - 2*i, minIndex, maxIndex);
        minIndex += i;
        maxIndex += i;
        swap(arr[i], arr[minIndex]);
        if (maxIndex == i) {
            maxIndex = minIndex;
        }
        swap(arr[n - 1 - i], arr[maxIndex]);
    }
}
int main(){
    int n ;
    cin >> n ;
    int a[n] ;
    for(int i = 0 ; i < n ; i++) cin >> a[i] ;
    minMaxSelectionSort(a , n) ;
    for(int i = 0 ; i < n ; i++) cout << a[i] << " " ;
}
