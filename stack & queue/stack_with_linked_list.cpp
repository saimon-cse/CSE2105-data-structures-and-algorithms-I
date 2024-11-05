#include <iostream>

using namespace std;

struct Node {
    int key;
    Node* next;
};

Node* top = nullptr;

void push(int x) {
   
}

int pop() {
    if(top==nullptr){
        cout << "Stack Underflow. Cannot pop from an empty stack.\n";
        return -1;
    }

    int poppedValue = top->key;

}

void print() {
    if(top==nullptr){
        cout << "Stack is empty\n";
        return;
    }

    Node* current = top;
    while(current){
        cout << current->key << " ";
        current = current->next;
    }
    cout << endl;
}

int topValue() {
   if(top == nullptr){
    cout << "Satck is empty.\n";
    return -1;
   }

   return top->key;
}


bool isEmpty() {
    return (top == nullptr);
}

int size() {
    int count = 0;
    Node* current = top;
    
    while(current != nullptr){
        count++;
        current = current->next;
    }
    return count;
}

int main() {
    int choice, value;

    while (true) {
        cout << "\n1.Push\n2.Pop\n3.Print\n4.Top\n5.Swap\n6.Emplace\n7.Empty\n8.Size\n9.Exit" << endl;
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                push(value);
                break;
            case 2:
                cout << "Popped value: " << pop() << endl;
                break;
            case 3:
                print();
                break;
            case 4:
                cout << "Top value: " << topValue() << endl;
                break;
            case 5: {
                Node* secondTop = nullptr;
                int secondValue;
                cout << "Enter values for second stack: ";
                while (cin >> secondValue) {
                    push(secondValue);
                }
                swap(top, secondTop);
                cout << "Stacks swapped." << endl;
                break;
            }
            case 6:
                cout << "Enter value to emplace: ";
                cin >> value;
                // emplace(value);
                break;
            case 7:
                cout << (isEmpty() ? "Stack is empty." : "Stack is not empty.") << endl;
                break;
            case 8:
                cout << "Size of the stack: " << size() << endl;
                break;
            case 9:
                cout << "Exiting program." << endl;
                exit(0);
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}