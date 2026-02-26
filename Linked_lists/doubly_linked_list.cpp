#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* prev;
    Node* next;
};

// Insert at beginning
void insertAtBeginning(Node* &head, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL)
        head->prev = newNode;

    head = newNode;
}

// Insert at end
void insertAtEnd(Node* &head, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        newNode->prev = NULL;
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

// Delete by value
void deleteNode(Node* &head, int value) {
    if (head == NULL)
        return;

    Node* temp = head;

    while (temp != NULL && temp->data != value)
        temp = temp->next;

    if (temp == NULL)
        return;

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    delete temp;
}

// Display forward
void displayForward(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// Display backward
void displayBackward(Node* head) {
    if (head == NULL)
        return;

    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    while (temp != NULL) {
        cout << temp->data << " <-> ";
        temp = temp->prev;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* head = NULL;
    int choice, value;

    do {
        cout << "\n1. Insert at beginning";
        cout << "\n2. Insert at end";
        cout << "\n3. Delete a value";
        cout << "\n4. Display forward";
        cout << "\n5. Display backward";
        cout << "\n0. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter value: ";
            cin >> value;
            insertAtBeginning(head, value);
        }
        else if (choice == 2) {
            cout << "Enter value: ";
            cin >> value;
            insertAtEnd(head, value);
        }
        else if (choice == 3) {
            cout << "Enter value to delete: ";
            cin >> value;
            deleteNode(head, value);
        }
        else if (choice == 4) {
            displayForward(head);
        }
        else if (choice == 5) {
            displayBackward(head);
        }

    } while (choice != 0);

    return 0;
}