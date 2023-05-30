#include <bits/stdc++.h>
using namespace std;

void heapify(vector<int>& arr, int n, int root) {
    int largest = root;    // Initialize the largest element as the root
    int left = 2 * root + 1;    // Left child index
    int right = 2 * root + 2;   // Right child index

    // Check if the left child is larger than the root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // Check if the right child is larger than the current largest
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If the largest element is not the root, swap them and heapify the affected sub-tree
    if (largest != root) {
        swap(arr[root], arr[largest]);
        heapify(arr, n, largest);
    }
}

void insert(int *arr,int &n, int val){
    n = n+1;
    arr[n] = val;
    heapify(arr, n+1, 0);
}

void insert2(int *arr, int &n, int val){
    n = n+1;
    arr[n] = val;
    int i=n;
    while(i>1){
        int parent = i/2;
        if(arr[parent] < arr[i]){
            swap(arr[parent], arr[i]);
            i = parent;
        }
        else return;
    }
}


void inserto(int data,int i)
{
    a[i]=data;
    int child=i;
    int par=(child-1)/2;
    while(child>0)
    {
        if(a[par]<a[child])
        {
            swap(a[par],a[child]);
            child=par;
            par=(child-1)/2;
        }
        else return;
    }
}






void Delete1(int *arr, int &n){
    int last = arr[n];
    arr[1] = last;
    n = n-1;
    heapify(arr, n, 1);
}



void Delete2(int *arr, int &n){
    arr[1] = arr[n];
    n--;
    int i = 1;
    while (i<n)
    {
        int left = arr[2*i], right = arr[2*i+1];
        int larger = (arr[left]>arr[right]) ? 2*i : 2*i+1;
        if(arr[i] < arr[larger]){
            swap(arr[i], arr[larger]);
            i=larger;
        }
        else return;
    }
}

void printArray(int *arr, int &n)
{
    for (int i = 1; i <= n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

int main(){
    int arr[10000];
    for(int i=1; i<=5; i++) cin>>arr[i];
    int n=5;
 

    insert(arr,n,15);
 
    printArray(arr, n);
  
 return 0;
}
