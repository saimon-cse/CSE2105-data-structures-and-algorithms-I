#include<bits/stdc++.h>
using namespace std;

void insert(int heap[], int key, int &heapSize){
    int index = heapSize;
    heap[index] = key;
    heapSize++;
    while(index > 1 && heap[index / 2] < heap[index])
        swap(heap[index / 2], heap[index]), index = index / 2;
}

int Delete(int heap[], int &size){
    int element = heap[1];

    heap[1] = heap[size];
    size--;

    int root = 1;

    while(root * 2 <= size){
        int child = root * 2;

        if(child + 1 <= size && heap[child + 1] > heap[child]) 
            child = child + 1; 

        if(heap[child] > heap[root]) swap(heap[child], heap[root]), root = child;
        else break;

    }
        return element;
}

void heapSort(int a[], int size){
    int heap[size + 1];
    int i, heapSize = 1;
    for( i=0; i<size; i++){
        insert(heap, a[i], heapSize);
    }
    for(int i=size - 1; i >=0 ; i--)
        a[i] = Delete(heap, heapSize);
}

void heapify(int a[], int size, int root) {
    int largest = root;        
    int left = 2 * root;        
    int right = 2 * root + 1;   // Right child index

    // If left child is larger than root
    if (left <= size && a[left] > a[largest])
        largest = left;

    // If right child is larger than the current largest
    if (right <= size && a[right] > a[largest])
        largest = right;

    if (largest != root) {
        swap(a[root], a[largest]);

        heapify(a, size, largest);
    }
}



int main(){
    int a[] = {3, 5, 1, 9, 8, 2, 6, 4};
    int size = sizeof(a) / sizeof(a[0]);

    heapSort(a, size);

    // Print the sorted array
    for(int i = 0; i < size; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}