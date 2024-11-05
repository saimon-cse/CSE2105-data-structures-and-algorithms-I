#include<bits/stdc++.h>
using namespace std;

#define INF INT_MAX

void merge(int a[], int p, int q){
    int mid = p + q >> 1;
    int l = mid - p + 1;
    int r = q - mid;

    int L[l+1], R[r+1];

    for(int i=0; i<l; i++) L[i] = a[p + i];
    for(int i=0; i<r; i++) R[i] = a[mid + i + 1];

    L[l] = INF, R[r] = INF;

    for(int i=0, j=0, k=p; k<=q; k++)
        if(L[i] < R[j]) a[k] = L[i++];
        else a[k] = R[j++];
}

void mergeSort(int a[], int p, int q){
    if(p >= q) return;
    int mid = p + q >> 1;
    mergeSort(a, p, mid);
    mergeSort(a, mid+1, q);
    merge(a, p, q);
}

int main(){
    int a[] {4, 2, 1, 7, 9, 3};
    mergeSort(a, 0, 6);
    for(int i=0; i<6; i++) cout << a[i];
}