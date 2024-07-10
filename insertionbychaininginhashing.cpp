#include <iostream>
using namespace std;

#define SIZE 7

struct Node {
    int data;
    Node* next;
    Node(int val){
    	data=val;
    	next=NULL;
	}
};

Node* chain[SIZE];

void init() {
    for (int i = 0; i < SIZE; i++) {
        chain[i] = NULL;
    }
}

void insert(int value) {
    // Create a new node with value
    Node* n = new Node(value);
    

    // Calculate hash key
    int key = value % SIZE;

    // Check if chain[key] is empty
    if (chain[key] == NULL) {
        chain[key] = n;
    }
    // Handle collision
    else {
        // Add the node at the end of chain[key]
        Node* temp = chain[key];
        while (temp->next!=NULL) {
            temp = temp->next;
        }
        temp->next = n;
    }
}

void print() {
    for (int i = 0; i < SIZE; i++) {
        Node* temp = chain[i];
        cout << "chain[" << i << "]-->";
        while (temp!=NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
}

void deleteNode(int value) {
    int key = value % SIZE;
    Node* temp = chain[key];
    Node* prev = NULL;

    // Check if the node to be deleted is the first node
    if (temp != NULL && temp->data == value) {
        chain[key] = temp->next;
        delete temp;
        return;
    }

    // Find the node to be deleted
    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    // If value was not present in the list
    if (temp == NULL) return;

    // Unlink the node from the linked list
    prev->next = temp->next;

    delete temp;
}

int main() {
    // Init array of list to NULL
    init();
    insert(7);
    insert(0);
    insert(3);
    insert(10);
    insert(4);
    insert(5);
    print();

    cout << "After deleting 10:\n";
    deleteNode(10);
    print();

    return 0;
}

