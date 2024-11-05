 #include<bits/stdc++.h>
using namespace std;


class Node{
    public:
    int key;
    Node *left, *right, *parent;

};

class DLL{
private:
    Node* head, *tail;

public:
    DLL(){
        head = tail = nullptr;
    }

    void creatFirstElement(int x){
        head = new Node;
        head->key = x;
        head->left = head->right = nullptr;
        tail = head;
    }

    void insertFront(int val){
        if(head==nullptr) {creatFirstElement(val); return;}
        Node* node = new Node;
        node->key = val;
        node->left = nullptr;
        node->right = head;
        head->left = node;
        

    }
};


int main(){

}
