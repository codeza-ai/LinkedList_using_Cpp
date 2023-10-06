// LL: Find Middle Node ( ** Interview Question)
// Implement a member function, findMiddleNode(), which finds and returns the middle node of the linked list.

// Note: this LinkedList implementation does not have a length member variable.
// Function Signature:
// Node* findMiddleNode();


// Input:
// The linked list can have any number of nodes (0 to n).
// Node values are integers.

// Output:
// Return a pointer to the middle node of the linked list.
// If the list has an even number of nodes, return the second middle node (the one closer to the end).

// Constraints:
// You are not allowed to use any additional data structures (such as arrays) or modify the existing data structure.
// You can only traverse the linked list once.

// Example:
// Suppose you have a LinkedList object, list, with the following values:
// 1 -> 2 -> 3 -> 4 -> 5

// After calling the findMiddleNode() function:
// Node* middle = list.findMiddleNode();

// The middle pointer should point to the node with value 3.
// Now suppose you have a LinkedList object, list, with the following values:
// 1 -> 2 -> 3 -> 4 -> 5 -> 6
// After calling the findMiddleNode() function:
// Node* middle = list.findMiddleNode();
// The middle pointer should point to the node with value 4.

// To assist you in the implementation and troubleshooting, a test suite has been provided in the Test.cpp file. This file contains a series of tests that validate the functionality of your code and will output to the "User logs" tab.
// You can also edit the Test.cpp file if you would like to create your own tests.

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
        
    public:
        LinkedList(int value) {
            Node* newNode = new Node(value);
            head = newNode;
            tail = newNode;
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
                // cout<<"printing list"<<endl;
            }
            cout << endl;
        }

        Node* getHead() {
            return head;
        }

        Node* getTail() {
            return tail; 
        }
        
        void makeEmpty() {
            Node* temp = head;
            while (head) {
                head = head->next;
                delete temp;
                temp = head;
            }
            tail = nullptr;
        }

        void append(int value) {
            Node* newNode = new Node(value);
            if (head == nullptr) {
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
        }

        Node* findMiddleNode()
        {
            if(head == nullptr || head->next == nullptr) return head;
            Node* fast = head;
            Node* slow = tail;

            while(fast!= nullptr || fast->next != nullptr)
            {
                slow = slow->next;
                fast = fast->next->next;
            }
            cout<<"worked";
            return slow;
        }

};

int main()
{
    LinkedList* l1 = new LinkedList(1);

    l1->append(2);
    l1->append(3);
    l1->append(4);
    l1->append(5);

    l1->printList();
    Node* middle = l1->findMiddleNode();
    cout<<middle->value<<endl;
}