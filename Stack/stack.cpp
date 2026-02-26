#include <iostream>
using namespace std;

int main() {
    int size;
    cout << "Enter stack size: ";
    cin >> size;

    int stack[size];   // array stack
    int top = -1;
    int choice, value;

    do {
        cout << "\n1. Push";
        cout << "\n2. Pop";
        cout << "\n3. Peek";
        cout << "\n4. Display";
        cout << "\n5. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: // Push
                if (top == size - 1) {
                    cout << "Stack Overflow\n";
                } else {
                    cout << "Enter value: ";
                    cin >> value;
                    stack[++top] = value;
                    cout << "Pushed successfully\n";
                }
                break;

            case 2: // Pop
                if (top == -1) {
                    cout << "Stack Underflow\n";
                } else {
                    cout << "Popped element: " << stack[top--] << endl;
                }
                break;

            case 3: // Peek
                if (top == -1) {
                    cout << "Stack is empty\n";
                } else {
                    cout << "Top element: " << stack[top] << endl;
                }
                break;

            case 4: // Display
                if (top == -1) {
                    cout << "Stack is empty\n";
                } else {
                    cout << "Stack elements (top to bottom): ";
                    for (int i = top; i >= 0; i--) {
                        cout << stack[i] << " ";
                    }
                    cout << endl;
                }
                break;

            case 5: // Exit
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice\n";
        }

    } while (choice != 5);

    return 0;
}