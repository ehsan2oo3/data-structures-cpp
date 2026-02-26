#include <iostream>
using namespace std;

#define MAX 100

// Display matrix
void display(int arr[MAX][MAX], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
}

// Row-wise sum
void rowSum(int arr[MAX][MAX], int size) {
    for (int i = 0; i < size; i++) {
        int sum = 0;
        for (int j = 0; j < size; j++)
            sum += arr[i][j];
        cout << "Sum of row " << i << ": " << sum << endl;
    }
}

// Column-wise sum
void columnSum(int arr[MAX][MAX], int size) {
    for (int j = 0; j < size; j++) {
        int sum = 0;
        for (int i = 0; i < size; i++)
            sum += arr[i][j];
        cout << "Sum of column " << j << ": " << sum << endl;
    }
}

int main() {
    int arr[MAX][MAX];
    int size;

    cout << "Enter matrix size: ";
    cin >> size;

    cout << "Enter matrix elements:\n";
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            cin >> arr[i][j];

    cout << "\nMatrix:\n";
    display(arr, size);

    cout << endl;
    rowSum(arr, size);
    cout << endl;
    columnSum(arr, size);

    return 0;
}