#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

// Insert at beginning
void insertAtBeginning(Node* &head, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

// Insert at end
void insertAtEnd(Node* &head, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

// Delete by value
void deleteNode(Node* &head, int value) {
    if (head == NULL)
        return;

    if (head->data == value) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* current = head;
    while (current->next != NULL && current->next->data != value)
        current = current->next;

    if (current->next != NULL) {
        Node* temp = current->next;
        current->next = temp->next;
        delete temp;
    }
}

// Display list
void display(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
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
        cout << "\n4. Display list";
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
            display(head);
        }

    } while (choice != 0);

    return 0;
}