#include<bits/stdc++.h>
using namespace std;


class Node{
    public:
        int key;
        Node *right, *left;    

    Node(int key){
        this->key = key;
        left = right = nullptr;
    }    
};

class SingleLinkedList{
    private:
        Node *head, *tail;
        int len;

    public:
        SingleLinkedList(){
            head = tail = nullptr;
            len = 0;
        }

        SingleLinkedList(int key){
            Node* newNode = new Node(key);
            head = tail = newNode;
            len = 1;
        }

        void printList(){
            Node* tmp = head;

            cout << (tmp == nullptr ? "There is no element in the list!\n" : "The list: ");
            while(tmp){
                cout << tmp->key << " ";
                tmp = tmp->right;
            }
            cout << endl;
        }


        void insertFirst(int key){
            Node* node = new Node(key);
            node->right = head;
            head = node;
            len++;
            if(tail == nullptr)  tail = head ;
            // cout << key << " is inserted!\n";
        }


        void insertLast(int key){
            Node* node = new Node(key);
            if(head == nullptr) head = tail = node;
            else tail->right = node, tail = node, len++;
        }

        int getLength() {return len;}


        Node* getHead(){
            return head;
        }

    Node* middleElement() {
        Node* fast = head;
        Node* slow = head;

        // Loop until the fast pointer reaches the end of the list
        while (fast != nullptr && fast->right != nullptr) {
            fast = fast->right->right;  // Move fast pointer by two steps
            slow = slow->right;         // Move slow pointer by one step
        }

        return slow;  // slow will be at the middle when fast reaches the end
    }


        void sort(){

        }
        bool isEmpty(){
            return head == nullptr;
        }


        bool deleteFirst(){
            if(isEmpty()){
                cout << "Empty!\n";
                return false;
            }
            Node* tmp = head;
            head = head->right;
            len--;
            delete tmp;
            return true;
        }
    
        bool deleteLast(){
            if(isEmpty()){
                cout << "Empty!\n";
                return false;
            }
            Node *fast=head, *slow=nullptr;
            while(fast->right) slow = fast, fast = fast->right;

            tail = slow;
            delete fast;    
            len--;
            (tail == nullptr) ? head = nullptr : tail->right = nullptr;

            return true;
        }

        void deleteKey(int key){ /* Delete the first occurance*/

        }

        Node* find(Node *tmp, int key){
            if(tmp == nullptr) return nullptr;
            if(tmp->key == key) return tmp;
            return find(tmp->right, key);
        }

        void removeDuplicant(){

        }

        Node* fistOccurance(int key) {

        };
        

};


class DoubleLinkedList{
    private: 
        Node *head, *tail;
        int len;

    public:

        DoubleLinkedList(){
            head = tail = nullptr;
            len = 0;
        }

        DoubleLinkedList(int key){
            Node* node = new Node(key);
            head = tail = node;
            len++;
        }
};




int main(){
    SingleLinkedList sll;
    
    cout << "1. insert first    2.insert last\n";
    cout << "3. print           4.delete first\n";
    cout << "5. delete last     6.Find\n\n";
    // cout << "7.inset at first occurance\n";
    // cout << 
     while(1){

        int n; cin >> n;

        if(n==1){
            int x ; cin >> x;
            sll.insertFirst(x);
            
            cout << x << " is inserted\n\n";
        }
        else if(n==2){
            int x ; cin >> x;
            sll.insertLast(x);            
            cout << x << " is inserted\n\n";
        }

        else if(n==3){
            cout << "the list is: ";
            sll.printList();
        }
        else if(n==4){
            if(sll.deleteFirst()) cout << "first element deleted\n\n";
            else cout << "unsuccessful\n\n";
        }
        else if(n==5){
             if(sll.deleteLast()) cout << "Last element deleted\n\n";
            else cout << "unsuccessful\n\n";
        }
        else if(n==6){
            int x; cin>>x;
            Node* tmp = sll.find(sll.getHead(), x);
            if(tmp) cout << tmp->key << " is found!\n";
            else cout << "Not found :(\n"; 
            // insetAfterFirstOccur(x, nV);
        }
        else cout << "invalid!\n";
        
     }

}