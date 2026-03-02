#include <iostream>
using namespace std;

int main() {
    int size;
    cout << "Enter queue size: ";
    cin >> size;

    int queue[size];
    int front = -1, rear = -1;
    int choice, value;

    do {
        cout << "\n1. Enqueue";
        cout << "\n2. Dequeue";
        cout << "\n3. Peek";
        cout << "\n4. Display";
        cout << "\n5. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {

            case 1: // Enqueue
                if ((rear + 1) % size == front) {
                    cout << "Queue Overflow\n";
                } else {
                    if (front == -1) {
                        front = rear = 0;
                    } else {
                        rear = (rear + 1) % size;
                    }
                    cout << "Enter value: ";
                    cin >> value;
                    queue[rear] = value;
                    cout << "Enqueued successfully\n";
                }
                break;

            case 2: // Dequeue
                if (front == -1) {
                    cout << "Queue Underflow\n";
                } else {
                    cout << "Dequeued element: " << queue[front] << endl;

                    if (front == rear) {
                        front = rear = -1; // queue becomes empty
                    } else {
                        front = (front + 1) % size;
                    }
                }
                break;

            case 3: // Peek
                if (front == -1) {
                    cout << "Queue is empty\n";
                } else {
                    cout << "Front element: " << queue[front] << endl;
                }
                break;

            case 4: // Display
                if (front == -1) {
                    cout << "Queue is empty\n";
                } else {
                    cout << "Queue elements: ";
                    int i = front;
                    while (true) {
                        cout << queue[i] << " ";
                        if (i == rear)
                            break;
                        i = (i + 1) % size;
                    }
                    cout << endl;
                }
                break;

            case 5:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice\n";
        }

    } while (choice != 5);

    return 0;
}