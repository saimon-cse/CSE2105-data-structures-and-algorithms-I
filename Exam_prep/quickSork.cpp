#include<bits/stdc++.h>
using namespace std;

int partition(int a[], int low, int high){
    int pivot = a[low];
    int i = low, j = high;

    while(i<j){
        while(i < high && a[i] <= pivot) i++; //  // Move `i` forward if a[i] <= pivot
        while(pivot < a[j]) j--;      // Move `j` backward if a[j] > pivot
        if(i<j) swap(a[i], a[j]);
    }
    swap(a[j], a[low]);     // Place pivot element at the correct position
    
    return j; // Return pivot index
}

void quickSort(int a[],int low, int high){
    if(low < high){
        int j = partition(a, low, high);

        quickSort(a, low, j - 1); // Sort left subarray
        quickSort(a, j + 1, high); // Sort right subarray
    }
}

void print(int a[], int n){
    for(int i=0; i<n; i++) cout << a[i];
    cout << endl;
}


int main(){
    // int a[] {3, 4, 5, 7, 1, 2, 3, 4, 5, 0};

    int n; cin >> n;
    int a[n];
    for(int i=0; i<n; i++) cin >> a[i];

    quickSort(a, 0, n-1);
    print(a, n);

}