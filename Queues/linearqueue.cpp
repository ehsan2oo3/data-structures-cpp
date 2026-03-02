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
                if (rear == size - 1) {
                    cout << "Queue Overflow\n";
                } else {
                    if (front == -1)
                        front = 0;
                    cout << "Enter value: ";
                    cin >> value;
                    queue[++rear] = value;
                    cout << "Enqueued successfully\n";
                }
                break;

            case 2: // Dequeue
                if (front == -1 || front > rear) {
                    cout << "Queue Underflow\n";
                } else {
                    cout << "Dequeued element: " << queue[front++] << endl;
                }
                break;

            case 3: // Peek
                if (front == -1 || front > rear) {
                    cout << "Queue is empty\n";
                } else {
                    cout << "Front element: " << queue[front] << endl;
                }
                break;

            case 4: // Display
                if (front == -1 || front > rear) {
                    cout << "Queue is empty\n";
                } else {
                    cout << "Queue elements: ";
                    for (int i = front; i <= rear; i++) {
                        cout << queue[i] << " ";
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