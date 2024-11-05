#include <iostream>
#include <vector>

using namespace std;

class Heap {
private:
    vector<int> heap; // Dynamic array to store heap elements

    // Heapify function to maintain max-heap property
    void heapify(int index) {
        int size = heap.size() - 1;
        int largest = index;
        int left = 2 * index;       // Left child index
        int right = 2 * index + 1;  // Right child index

        // If left child is larger than root
        if (left <= size && heap[left] > heap[largest]) {
            largest = left;
        }

        // If right child is larger than the current largest
        if (right <= size && heap[right] > heap[largest]) {
            largest = right;
        }

        // If largest is not root, swap and heapify the affected subtree
        if (largest != index) {
            swap(heap[index], heap[largest]);
            heapify(largest);
        }
    }

public:
    // Constructor
    Heap() {
        heap.push_back(-1); // Dummy element for 1-based indexing
    }

    // Insert key into the max-heap
    void insert(int key) {
        heap.push_back(key);
        int index = heap.size() - 1;

        // Bubble up the new element to maintain the heap property
        while (index > 1 && heap[index / 2] < heap[index]) {
            swap(heap[index / 2], heap[index]);
            index = index / 2;
        }
    }

    // Delete the root from the max-heap and return the deleted element
    int deleteMax() {
        if (heap.size() == 1) {
            cout << "Heap is empty!" << endl;
            return -1;
        }

        int maxElement = heap[1];            // The root (max element)
        heap[1] = heap.back();               // Move the last element to the root
        heap.pop_back();                     // Remove the last element

        // Call heapify to restore the heap property
        heapify(1);

        return maxElement;
    }

    // Display the current heap
    void display() {
        for (int i = 1; i < heap.size(); i++) {
            cout << heap[i] << " ";
        }
        cout << endl;
    }

    // Heap sort function
    void heapSort() {
        vector<int> sortedHeap = heap; // Copy the current heap

        int size = sortedHeap.size() - 1;
        for (int i = size; i >= 2; i--) {
            swap(sortedHeap[1], sortedHeap[i]); // Move the largest element to the end
            size--;
            heapify(1); // Restore the heap property on the reduced heap
        }

        // Print sorted elements
        for (int i = 1; i < sortedHeap.size(); i++) {
            cout << sortedHeap[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Heap h;

    // Insert elements into the heap
    h.insert(3);
    h.insert(5);
    h.insert(9);
    h.insert(6);
    h.insert(8);
    h.insert(2);

    cout << "Max-Heap:" << endl;
    h.display(); // Display the heap

    // Delete the maximum element
    cout << "Deleted max element: " << h.deleteMax() << endl;
    h.display(); // Display the heap after deletion

    cout << "Heap after sorting:" << endl;
    h.heapSort(); // Sort and display the sorted elements

    return 0;
}
