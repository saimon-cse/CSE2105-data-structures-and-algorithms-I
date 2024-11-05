#include<bits/stdc++.h>
using namespace std;



void heapfy(int a[], int n, int i){

    int small = i;
    int left = i*2, right = i*2+1;

    if(left<=n && a[small] > a[left])
        small = left;

    if(right<=n and a[small] > a[right])
        small = right;

    if(i != small){
    swap(a[small], a[i]);

    heapfy(a, n, small);

    } 
}

void HeapSort(int a[], int& size){
    for(int i=size/2; i>0; i--){
        heapfy(a, size, i);
    }

    for(int i=size; i>1; i--){
        swap(a[1], a[i]);

        heapfy(a, i-1, 1);
    }
}


int main(){


    int a[6] {0, 1, 2, 3, 5 , 6};
    int n = 5;
    HeapSort(a, n);
    for(auto i:a) cout << i <<" ";

}