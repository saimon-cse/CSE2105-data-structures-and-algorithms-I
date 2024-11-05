#include <iostream>

using namespace std;

const int MAX_SIZE = 100; // Maximum size of the queue

struct Queue {
    int arr[MAX_SIZE];
    int front, rear;

    Queue() {
        front = -1; // Initialize front index to -1 (empty queue)
        rear = -1; // Initialize rear index to -1 (empty queue)
    }
};

void enqueue(Queue& q, int x) {
    if(q.rear == MAX_SIZE) {

    }
}

int dequeue(Queue& q) {
   if(q.front == -1 || q.front > q.rear){
    cout << "Queue Underflow. Cannot dequeue from an empty queue.\n";
    return -1;
   }
   
   int dequeueValue = q.arr[q.front++];
}

int front(const Queue& q) {
    
}


int back(const Queue& q) {
    
}

bool empty(const Queue& q) {
}

int size(const Queue& q) {
   
}

void display(const Queue& q) {
    
}

int main() {
    Queue q;
    int choice, value;

    while (true) {
        cout << "\n1. Enqueue\n2. Dequeue\n3. Front\n4. Back\n5. Empty\n6. Size\n7. Display\n8. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                enqueue(q, value);
                break;
            case 2: {
                int dequeuedValue = dequeue(q);
                if (dequeuedValue != -1)
                    cout << "Dequeued value: " << dequeuedValue << endl;
                break;
            }
            case 3:
                cout << "Front value: " << front(q) << endl;
                break;
            case 4:
                cout << "Back value: " << back(q) << endl;
                break;
            case 5:
                cout << "Queue is " << (empty(q) ? "empty." : "not empty.") << endl;
                break;
            case 6:
                cout << "Queue size: " << size(q) << endl;
                break;
            case 7:
                display(q);
                break;
            case 8:
                cout << "Exiting program." << endl;
                exit(0);
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}