#include<bits/stdc++.h>
using namespace std;


class Node{
    public:
        int value;
        Node *left, *right, *parent;

        Node(int value){
            this->value = value;
            left = right = parent =  nullptr;    
        }

        Node(){
           left = right = parent = nullptr; 
        }
};

class BST{
public:
    Node* root;
    BST(){
        root = nullptr;
    }

    void insert(int value){
        Node *node = new Node(value);
        if(root== nullptr){
            root = node;
            return;
        }

        Node *slow = nullptr, *fast = root;

        while(fast){
            slow = fast;
            if(value < fast->value) fast = fast->left;
            else fast = fast->right;
        }

        if(value < slow->value) slow->left = node;
        else slow->right = node;
        
        node->parent = slow;        
    }


    int size(Node* node){
        return 1 + size(node->left) + size(node->right);
    }

    void inOrder(Node *node){
        if(node == nullptr) return;
        inOrder(node->left);
        cout << node->value << " ";
        inOrder(node->right);
    }

    int height(Node* node){
        if(height==nullptr) return 0;
        return 1 + max(height(node->left), height(node->right));
    }




};


int main(){
    
}