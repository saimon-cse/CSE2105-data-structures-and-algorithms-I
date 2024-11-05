#include<bits/stdc++.h>
using namespace std;

#define INF INT_MAX

void Merge(int a[], int left, int right){
    int mid = (left + right) >> 1;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1 + 1];
    int R[n2 + 1];

    for(int i=0; i<n1; i++) L[i] = a[left + i];
    for(int i=0; i<n2; i++) R[i] = a[mid + i + 1];

    L[n1] = INF;
    R[n2] = INF;

    for(int i=0, j=0, k=left; k<=right; k++){
        if(L[i] < R[j]) a[k] = L[i++];
        else a[k] = R[j++];
    }
}
void MergeSort(int a[], int left, int right){
    if(left >= right) return ;
    int mid = (left + right) >> 1;

    MergeSort(a, left, mid);
    MergeSort(a, mid+1, right);
    Merge(a, left, right);
}   

void print(int a[], int n){
    // int n = sizeof(a);
    for(int i=0; i<n; i++) cout << a[i] << " ";
}

int main(){
    int n; cin >> n;
    int arr[n];

    for(int i=0; i<n; i++) cin >> arr[i];

    MergeSort(arr, 0, n-1);    
    print(arr, n);
    

}