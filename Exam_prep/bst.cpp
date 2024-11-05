#include<bits/stdc++.h>
using namespace std;


class Node{
public:
    int key;
    Node *left, *right, *parent;

    Node(int x){
        key = x;
        left = right = parent = nullptr;
    }
};

class BST{
public:
    Node* root;
    BST(){
        root = nullptr;
    }

    void insert(int v){
        Node* temp = new Node(v);
        if(root == nullptr){
            root = temp; return;
        }

        Node *slow = nullptr, *fast = root;

        while(fast){
            slow = fast;
            if(v < fast->key) fast = fast->left;
            else fast = fast->right;
        }
        
        if(v < slow->key) slow->left = temp;
        else slow->right = temp;

        temp->parent = slow;
    }

    void inOrder(Node* node){
        if(!node) return;
        inOrder(node->left);
        cout << node->key << " ";
        inOrder(node->right);
    }

    int height(Node* node){
        if(!node) return 0;
        return 1 + max(height(node->left), height(node->right));
    }

    int size(Node* node){
        if(!node) return 0;
        return 1 + size(node->left) + size(node->right);
    }

    bool delete0child(Node* node){
        if(root == node){
            delete root;
            root = nullptr;
            return true;
        }

        Node* par = node->parent;
        if(node->key < par->key) par->left = nullptr;
        else par->right = nullptr;

        delete node;
        return true;
    }

    bool delete1child(Node* node){
        if(root == node){
            Node *child = node->left;
            if(child==nullptr) child = node->right;
            root = child;
            delete node;
            return true;
        }

        Node* par = node->parent;
        Node* child = node->left;
        if(child==nullptr) child = node->right;

        if(child->key < par->key) par->left = child;
        else par->right = child;
        delete node;
        child->parent = par;
        return true;
    }

    Node* findSuccessor(Node* node){
        if(node->left == nullptr) return node;
        return findSuccessor(node->left);
    }

    bool delete2child(Node* node){
        Node* ios = findSuccessor(node->right);
        node->key = ios->key;

        if(ios->right==nullptr) delete0child(ios);
        else delete1child(ios);
        
        return true;
    }

    bool deleteNode(Node* node){
        
    }

};


int main(){
    BST bst;
     while (1){
        cout << "Choice: "; int cmd; cin >> cmd;
        

        if(cmd==1){
        
            cout << "Enter the List Size: "; int n; cin >> n;

            for(int i=0; i<n; i++){
                int x; cin >> x;
                bst.insert(x);
            }
            
        }
        else if(cmd == 2){
            cout << "Sorted List: ";
            bst.inOrder(bst.root);
            cout << endl << endl;

        }
    } 
}