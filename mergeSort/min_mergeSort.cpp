#include<bits/stdc++.h>
using namespace std;
#define INF INT_MAX

int minimum  = INF;

void merge(int a[], int p, int q){
    int mid = (p + q ) / 2;
    
    int n1 = mid - p + 1;
    int n2 = q - mid;
    int L[n1], R[n2];

    for(int i =0; i<n1; i++) L[i] = a[p + i];
    for(int i=0; i<n2; i++)  R[i] = a[mid + 1 + i];

    L[n1] = INF;
    R[n2] = INF;

    minimum = min(minimum, min(L[0], R[0])); 
}

void mergeSort(int a[], int p, int q){
    if(p >= q) return;
    int mid = (p+q)/2;
    mergeSort(a, p, mid);
    mergeSort(a, mid+1, q);
    merge(a, p, q);
}

int main(){
    int n; cin >> n;
    
    int a[n];
    for(int i=0; i<n; i++) cin >> a[i];

    mergeSort(a, 0, n-1);
    cout << minimum << endl;
}