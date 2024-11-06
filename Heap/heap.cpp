#include<bits/stdc++.h>
using namespace std;

void heapify(int *arr, int size, int i){
    int large = i;
    int left = 2*i;
    int right = 2*i + 1;

    if(left <= size && arr[large] < arr[left])
        large = left;
    
    if(right <= size && arr[large] < arr[right]) 
        large = right;

    if(large != i){
        swap(arr[i], arr[large]);
        heapify(arr, size, large);
    }

}

void heapSort(int *arr, int size){
    for(int i = size / 2; i >= 1; i--){
        heapify(arr, size, i);
    }

    for(int i = size; i> 1; i--){
        swap(arr[1], arr[i]);
        heapify(arr, i - 1, 1);
    }
}

int main(){
    int arr[10] {0, 3, 4, 7, 1, 4, 8};
    int n=6;

    heapSort(arr, n);

    for(auto i : arr) cout << i << " ";
}