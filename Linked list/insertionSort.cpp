#include<bits/stdc++.h>
using namespace std;

void insertSort(int a[], int n){
    for(int i = 1; i < n; i++){
        int key = a[i];
        int j = i - 1;
        while(j >= 0 && a[j] > key){
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

void sort(int a[], int n){
    for(int i=1; i<n; i++){
        int key = a[i];
        int j = i-1;
        while(j>=0 and a[j]>key){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }
}

int main(){
    int a[]{1,2,4,3,5,6,0};
    insertSort(a, 7);
    for(int i=0; i<7; i++) cout << a[i] << " ";
}