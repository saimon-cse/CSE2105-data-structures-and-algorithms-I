#include <iostream>

using namespace std;

const int MAX_SIZE = 3; // Maximum size of the stack

struct StackArray {
    int arr[MAX_SIZE];
    int top;
    int size; // Size of the stack

    StackArray() {
        top = -1; // Initialize top index to -1 (empty stack)
        size = 0; // Initialize size to 0
    }
};

void push(StackArray& stack, int x) {
    if(stack.top>=MAX_SIZE-1){
        cout << "Stack Overflow. Cannot push more elements.\n";
        return;
    }

    stack.arr[++stack.top] = x;
    stack.size++;
    cout << x << " has been pushed ono the stack\n";

}

int pop(StackArray& stack) {
    if(stack.top<0){
        cout << "Stack Underflow. Cannot pop from an empty stack\n";
        return -1;
    }
    int popedValue = stack.arr[stack.top--]; 
    // decrement top and retuen poped element
    stack.size--; // decrement size
    return popedValue;
}

void print(const StackArray& stack) {
    if(stack.top<0){
        cout << "Stack is empty\n";
        return;
    }
    
    for(int i=stack.top; i>=0; i--){
        cout << stack.arr[i] << " ";
    }
    cout << endl;

}

int topValue(const StackArray& stack) {
    if(stack.top<0){
        cout << "Stack is empty\n";
        return -1;
    }

    return stack.arr[stack.top];
}

bool isEmpty(const StackArray& stack) {
    if(stack.top <0) return false;
    else return true;
}

int main() {
    StackArray stack;
    int choice, value;

    while (true) {
        cout << "\n1. Push\n2. Pop\n3. Print\n4. Top\n5. Size\n6. Exit" << endl;
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                push(stack, value);
                break;
            case 2:
                cout << "Popped value: " << pop(stack) << endl;
                break;
            case 3:
                print(stack);
                break;
            case 4:
                cout << "Top value: " << topValue(stack) << endl;
                break;
            case 5:
                cout << "Size of the stack: " << stack.size << endl;
                break;
            case 6:
                cout << "Exiting program." << endl;
                exit(0);
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}