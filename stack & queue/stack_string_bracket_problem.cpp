#include<bits/stdc++.h>
using namespace std;


class Node{
public:
    char key;
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

    void insertFirstElement(char x){
        Node* temp = new Node;
        // Node* temp == (Node*) malloc(sizeof(Node))
        temp->key = x;
        temp->next = nullptr;
        top = temp;
        length++;
        // return;
    }

    void push(char x){
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

    char pop(){
        if (isEmpty()) return -1; 

        Node* temp = top;
        top = top->next;
        length--;
        char x = temp->key;
        delete temp;
        return x;
    }
    
    int size(){
        return length;
    }

    char topV(){
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
    Stack st;
    // cout << "Enter commands (1 for push, 2 for pop, 3 for print,\n4 for topValue, 5 for Size, 6 to exit):" << endl;

    // int cmd; 
    // int n; cin>>n;
    string s; cin >> s;
    int n = s.size();
    
    for(int i=0; i<s.size(); i++){
        if((s[i]==')' or s[i]=='}' or s[i]==']') and st.isEmpty()) {
            st.push(s[i]);
            break;
        }
        else if(s[i]=='(' or s[i]=='{' or s[i]=='[') st.push(s[i]);

        else if(s[i]==')' and st.topV()=='(') st.pop();
        else if(st.topV()=='{' and s[i]=='}') st.pop();
        else if(st.topV()=='[' and s[i]==']') st.pop();
    }

    if(st.isEmpty()) cout << "Balanced\n";
    else cout << "Unbalanced\n";
}

/*

)({a+b}[c+d]){{e+f}}

(a+b))c+d(
(a+b){[c+d}]

*/