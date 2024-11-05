#include<bits/stdc++.h>
using namespace std;


class Node{
    public:
        int key;
        Node* parent, *left, *right;

        Node();
        Node(int key);
};

Node::Node(){
    parent = left = right = nullptr;
}
Node::Node(int key){
    parent = left = right = nullptr;
    this->key = key;
}


class BST{
private:
    Node* root;
public:
    BST(int key);

    void insert(int key);
    Node* find(int key);
    Node* findMin(Node* root);
    Node* findMax(Node* root);
    void inorder(Node* root);
    int height(Node* root);
    int size(Node* root);
    Node* findSuccessor(Node* tmp);
    bool deleteElement(int key);
    void print();
    
};

void BST::insert(int value){
    Node* node = new Node(value);

    if(root == nullptr){
        root = node;
        return;
    }

    
}

Node* BST::find(int key){

}

BST::BST(int key){
    root = nullptr;
}




int main(){

}