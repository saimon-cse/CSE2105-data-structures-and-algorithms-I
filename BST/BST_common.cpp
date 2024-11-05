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
    private:
        int length;
    public:
        Node*root;
        BST(){
            root = nullptr;
            length = 0;
        }
        void insert(int x){
            Node *temp = new Node(x);

            if(root == nullptr){
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
            length++;
        }

        void inOrder(Node* temp){
            // Node* temp = root;
            if(temp == nullptr) return;
            inOrder(temp->left);
            cout << temp->key << " ";
            inOrder(temp->right);
        }


        int maximum(Node* temp){
            if(temp->right == nullptr) return temp->key;
            return maximum(temp->right);
        }

        int minimum(Node* temp){
            if(temp->left == nullptr) return temp->key;
            return minimum(temp->left);
        }

        // int Size(){
        //     return length;
        // }

        int Size(Node*temp){
            if(temp == nullptr) return 0;
            // int x =  1 + Size(temp->left);
            // int y = 1 + Size(temp->right);
            // return (x+y) / 2;

            return 1 + Size(temp->left) + Size(temp->right);
            
        }

        int height(Node* temp){
            if(temp == nullptr) return 0;
            return 1 + max(height(temp->left), height(temp->right));
        }

        Node* find(int x, Node* temp){
            
            if(temp == nullptr ) return temp;
            else if(temp->key == x) return temp;

            if(x < temp->key) return find(x, temp->left);
            return find(x, temp->right);

            // else if((temp->key == maximum(root)) and (x > temp->key)) return NULL;
            // else if((temp->key == minimum(root)) and (x < temp->key)) return NULL;
            // if(x >= temp->key)
            // return nullptr;
        }

        bool delete0child(Node* node){
           if(node==root){
            delete node;
            root = nullptr;
            return true;    
           }
           Node* par = node->parent;
           if(node->key < par->key) par->left = nullptr;
           else par->right = nullptr;
           delete node;
           length--;
           return true;
        }

        bool delete1child(Node* node){
            if(node==root){
                Node* child = node->left;
                if(child==nullptr) child = node->right;
                root = child;
                delete node;
                length--;
                return true;
            }

            Node* par = node->parent;
            Node* child = node->left;
            if(child==nullptr) child = node->right;

            if(child->key < par->key) par ->left = child;
            else par->right  = child;

            delete node;
            child->parent = par;
            length--;
            return true;
        }

        Node* findSuccessor(Node*node){
            if(node) return node->parent;
            return findSuccessor(node->left);
        }

//         Node* BST::findSuccessor(Node* node){
//     if(node->right) findMin(node->right);

//     Node* parent = node->parent;

//     if(parent == nullptr or parent->left == node)
//         return parent;
    
//     return findSuccessor(parent);
// }

        bool delete2child(Node*node){
            
            Node *ios = findSuccessor(node->right);
            node->key = ios->key;

            if(ios->right==nullptr) delete0child(ios);
            else delete1child(ios);
            length--;

            return true;

        }

        bool deleteNode(Node*node){
            if(node->left==nullptr and node->right==nullptr) delete0child(node);
            else if(node->left and node->right) delete2child(node);
            else delete1child(node);
            return true;
        }

        // int pairSum(Node* temp, int n){
        //     if(temp->left==nullptr or temp->right==nullptr) return temp->key ;
        //     return  pairSum(temp->left,n--) + pairSum(temp->right,n--);
           
        // }

};

int main(){
    
    cout << "1. Insert      2. Sort     3. Maximum     4.Minimum\n";
    cout << "5. Size        6. Height   7. Find        5. Delete element\n";
    
    BST bst;

    while (1)
    {
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
        else if(cmd == 3){
            cout << "Maximum Value: " << bst.maximum(bst.root) << endl << endl;
        }
        else if(cmd == 4){
            cout << "Minimum Value: " << bst.minimum(bst.root) << endl << endl;
        }
        else if(cmd == 5){
            cout << "Size: " << bst.Size(bst.root) << endl << endl;

        }
        else if(cmd == 6){
            cout << "Height of the tree: " << bst.height(bst.root) << endl << endl;
        }
        else if(cmd == 7){
            cout << "Enter the number: "; int x; cin >> x;
            if(bst.find(x, bst.root) != NULL) cout << x << " is Found!\n\n";
            else cout << x << " is not found!\n\n";
        }
        else if(cmd == 8 ){
            int x;
            cout << "Enter a number: "; cin >> x;
            
            if(bst.deleteNode(bst.find(x, bst.root))) cout << x << " is deleted!\n\n";
            else cout << x << " is not find!\n\n";
        }
        else if(cmd == 9){
            // cout << "Sum: " << bst.pairSum(bst.root, 100) << endl;
            // bst.pairSum(bst.root,100);
        }


    }
    
}


/*

1
8
10 1 3 11 13 15 12 5


1
9 
20 10 8 15 30 25 38 35 37

*/