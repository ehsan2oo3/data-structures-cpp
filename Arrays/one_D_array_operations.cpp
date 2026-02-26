#include <iostream>
using namespace std;

// Display array
void display(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Insert element at position
void insertElement(int arr[], int &n, int pos, int value) {
    for (int i = n; i > pos; i--)
        arr[i] = arr[i - 1];

    arr[pos] = value;
    n++;
}

// Delete element at position
void deleteElement(int arr[], int &n, int pos) {
    for (int i = pos; i < n - 1; i++)
        arr[i] = arr[i + 1];
    n--;
}

// Linear search
int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++)
        if (arr[i] == key)
            return i;
    return -1;
}

// Find minimum and maximum
void findMinMax(int arr[], int n) {
    int min = arr[0], max = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] < min) min = arr[i];
        if (arr[i] > max) max = arr[i];
    }

    cout << "Minimum: " << min << endl;
    cout << "Maximum: " << max << endl;
}

int main() {
    int size, choice;

    cout << "Enter number of elements: ";
    cin >> size;

    int arr[size];

    cout << "Enter elements:\n";
    for (int i = 0; i < size; i++)
        cin >> arr[i];

    do {
        cout << "\n1. Display";
        cout << "\n2. Insert element";
        cout << "\n3. Delete element";
        cout << "\n4. Linear search";
        cout << "\n5. Find min and max";
        cout << "\n0. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        if (choice == 1) {
            display(arr, size);
        }
        else if (choice == 2) {
            int pos, value;
            cout << "Enter position (0-based): ";
            cin >> pos;
            cout << "Enter value: ";
            cin >> value;
            insertElement(arr, size, pos, value);
        }
        else if (choice == 3) {
            int pos;
            cout << "Enter position (0-based): ";
            cin >> pos;
            deleteElement(arr, size, pos);
        }
        else if (choice == 4) {
            int key;
            cout << "Enter value to search: ";
            cin >> key;
            int index = linearSearch(arr, size, key);
            if (index != -1)
                cout << "Found at index " << index << endl;
            else
                cout << "Not found" << endl;
        }
        else if (choice == 5) {
            findMinMax(arr, size);
        }

    } while (choice != 0);

    return 0;
}