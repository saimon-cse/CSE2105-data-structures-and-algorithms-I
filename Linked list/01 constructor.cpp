#include <iostream>

using namespace std;

class Node { 
    public:
        int value;
        Node* next;

        Node(int value) {
            this->value = value;
            next = nullptr;
        }
}; 


class LinkedList {
    private:
        Node* head;
        Node* tail;
        int length;

    public:
        //   +======================================================+
        //   |                 WRITE YOUR CODE HERE                 |
        //   | Description:                                         |
        //   | - Write the LinkedList constructor                   |
        //   | - Constructor takes an int value                     |
        //   | - Create a new node                                  |
        //   | - Initialize head, tail to the new node              |
        //   | - Length starts at 1                                 |
        //   |                                                      |
        //   | Tips:                                                |
        //   | - Use 'new' to allocate memory for the new node      |
        //   | - Make sure to set head and tail pointers            |
        //   | - Make sure to set length                            |
        //   | - Check output from Test.cpp in "User logs"          |
        //   +======================================================+

        LinkedList(int key){
            Node* newNode = new Node(key);
            head = newNode;
            tail = newNode;
            length = 1;
        }

        ~LinkedList() {
            Node* temp = head;
            while (head) {
                head = head->next;
                delete temp;
                temp = head;
            }
        }

        void printList() {
            Node* temp = head;
            if (temp == nullptr) {
                cout << "empty";
            } else {
                while (temp != nullptr) {
                    cout << temp->value;
                    temp = temp->next;
                    if (temp != nullptr) {
                        cout << " -> ";
                    }
                }
            }
            cout << endl;
        }

        Node* getHead() {
            return head;
        }

        Node* getTail() {
            return tail; 
        }

        int getLength() {
            return length;
        }

};



//  +=====================================================+
//  |                                                     |
//  |          THE TEST CODE BELOW WILL PRINT             |
//  |              OUTPUT TO "USER LOGS"                  |
//  |                                                     |
//  |  Use the output to test and troubleshoot your code  |
//  |                                                     |
//  +=====================================================+


static void test() {
    
    // Helper function to check test result
    auto checkTestResult = [](bool condition) {
        cout << (condition ? "PASS" : "FAIL") << endl;
    };

    // Test 1: InitializesHeadCorrectly
    {
        cout << "\n------ LinkedList Test: InitializesHeadCorrectly ------\n";
        
        LinkedList ll(5);
        
        cout << "Expected Head Value: 5\n";
        cout << "Actual Head Value: " << ll.getHead()->value << "\n";

        checkTestResult(ll.getHead()->value == 5);
    }

    // Test 2: InitializesTailCorrectly
    {
        cout << "\n------ LinkedList Test: InitializesTailCorrectly ------\n";
        
        LinkedList ll(5);
        
        cout << "Expected Tail Value: 5\n";
        cout << "Actual Tail Value: " << ll.getTail()->value << "\n";

        checkTestResult(ll.getTail()->value == 5);
    }

    // Test 3: InitializesLengthCorrectly
    {
        cout << "\n------ LinkedList Test: InitializesLengthCorrectly ------\n";
        
        LinkedList ll(5);
        
        cout << "Expected Length: 1\n";
        cout << "Actual Length: " << ll.getLength() << "\n";

        checkTestResult(ll.getLength() == 1);
    }

    // Test 4: HeadAndTailAreTheSameNode
    {
        cout << "\n------ LinkedList Test: HeadAndTailAreTheSameNode ------\n";
        
        LinkedList ll(5);
        
        cout << "Checking if head and tail point to the same node...\n";
        
        checkTestResult(ll.getHead() == ll.getTail());
    }
    
}

