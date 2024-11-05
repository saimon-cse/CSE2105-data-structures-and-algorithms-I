#include<bits/stdc++.h>
using namespace std;

struct Node{
    int key;
    Node* left, *right, *parent;

    Node(int x){
        key = x;
        left = right = parent = nullptr;
    }
};

struct BST{
    Node* root;
    BST(){
        root = nullptr;
    }

    void insert(int x){
        Node * temp = new Node(x);
        if(!root){
            root = temp;
            return;
        }        
        Node *fast = root, *slow = nullptr;

        while(fast){
            slow = fast;            
            if(x < fast->key) fast = fast->left;
            else fast = fast->right;
        }
        
        if(x < slow->key) slow->left = temp;
        else slow->right = temp;
        temp->parent = slow;
    }

    void inOrder(Node* temp){
        if(!temp) return;
        inOrder(temp->left);
        cout << temp->key << " ";
        inOrder(temp->right);
    }

    int maximum(Node* temp){
        if(temp->right == NULL) return temp->key;
        return maximum(temp->right);
    }

    // int delete(){
    //     delete0child
    // }

    int height(Node* temp){
        if(temp==NULL) return -1;
        return 1+max(height(temp->left), height(temp->right));
    }
};


int main(){
    BST bst;
    
    cout << "1. Insert\n2. print\n3. Maximum\n";
    while(1){
        cout << "Choice: "; int cmd; cin >> cmd;
        if(cmd == 1){
            // int x;
            // cout << "Enter element to insert: "; cin >> x;
            // bst.insert(x);
            cout << "Enter size: ";
            int n; cin>> n;
            while (n--)
            {
                int x;
             cin >> x;
            bst.insert(x);
            }
            
        }
        else if(cmd == 2){
            cout << "Sorted List: ";
            bst.inOrder(bst.root);
            cout << endl;
        }
        else if(cmd==3){
            cout << "Max: " << bst.maximum(bst.root) << endl;;
        }

    }
}


/*

1 44 
1 17
1 88 
1 32
1 65
1 97
1 28
1 54
1 82
1 76
1 80



*/