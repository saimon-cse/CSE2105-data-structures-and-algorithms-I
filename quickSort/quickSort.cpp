#include<bits/stdc++.h>
using namespace std;

int Partition(int a[], int p, int r){
    int i = p;
    for(int j = p; j < r; j++){ // Fix: Changed j < r-1 to j < r
        if(a[j] <= a[r]) swap(a[i++], a[j]);        
    }
    swap(a[i], a[r]); // Fix: Changed a[i+1] to a[i]
    
    return i;
}

void quickSort(int a[], int p, int r){
    if(p >= r) return; // Fix: Changed p < r to p >= r
    int i = Partition(a, p, r);
    quickSort(a, p, i-1);
    quickSort(a, i+1, r);
}

int main(){
    int a[]{3, 2, 5, 1, 10, 4};
    quickSort(a, 0, 5);
    for(int i : a) cout << i << " ";
}