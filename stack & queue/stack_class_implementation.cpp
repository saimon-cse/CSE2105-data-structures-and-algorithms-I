#include<bits/stdc++.h>
using namespace std;


class Node{
public:
    int key;
    Node* next;
};

class Stack{
private:
    Node* top=nullptr; // NULL
    int length=0;

public:

    bool isEmpty(){
        if(top==nullptr) return true;
        return false;
        
    }

    void insertFirstElement(int x){
        Node* temp = new Node;
        // Node* temp == (Node*) malloc(sizeof(Node))
        temp->key = x;
        temp->next = nullptr;
        top = temp;
        length++;
        // return;
    }

    void push(int x){
        if (isEmpty()) {
            insertFirstElement(x);
            return;
        }
        Node* temp = new Node;
        temp->next = top;
        temp->key = x;
        top = temp;
        length++;

    }

    int pop(){
        if (isEmpty()) return -1; 

        Node* temp = top;
        top = top->next;
        length--;
        int x = temp->key;
        delete temp;
        return x;
    }
    
    int size(){
        return length;
    }

    int topV(){
          if (isEmpty()) return -1; 
          return top->key;
    }

    void print(){
        if(!top){
            cout << "Stack is empty\n";
            return;
        }
        Node* temp = top;
        cout << "List: ";
        while(temp){
            cout << temp->key << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    

};

int main() {
    Stack st1[2];
    cout << "Enter commands (1 for push, 2 for pop, 3 for print,\n4 for topValue, 5 for Size, 6 to exit):" << endl;

    int cmd;
    while (true) {
        cin >> cmd;
        if (cmd == 1) {
            int x;
            cout << "Enter a number to push: ";
            cin >> x;
            st1[1].push(x);
        } else if (cmd == 2) {
            int val = st1[1].pop();
            if (val == -1) cout << "Stack is empty." << endl;
            else  cout << "Popped: " << val << endl;
            
        }else if(cmd==3){
            st1[1].print();
        } 
        else if(cmd==4){
            if(st1[1].topV()==-1) cout << "Stack is empty\n";
            else cout << "Top Value: " << st1[1].topV() << endl;
        }
        else if(cmd==5){
            cout << "Size: " << st1[1].size() << endl;
        }
        else if (cmd == 6) {
            break;  
        } else {
            cout << "Invalid command!" << endl;
        }
    }

    return 0;
}


/*

()())))()))

*/