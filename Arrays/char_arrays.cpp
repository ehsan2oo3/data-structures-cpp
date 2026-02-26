#include <iostream>
using namespace std;

#define MAX 100

// Calculate length of char array
int length(char str[]) {
    int count = 0;
    while (str[count] != '\0')
        count++;
    return count;
}

// Reverse char array
void reverse(char str[]) {
    int len = length(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

// Palindrome check
bool isPalindrome(char str[]) {
    int len = length(str);
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1])
            return false;
    }
    return true;
}

int main() {
    char str[MAX];
    int size;

    cout << "Enter maximum size of char array: ";
    cin >> size;

    cout << "Enter string (no spaces): ";
    cin >> str;

    cout << "Length of string: " << length(str) << endl;

    reverse(str);
    cout << "Reversed string: " << str << endl;

    if (isPalindrome(str))
        cout << "It is a palindrome" << endl;
    else
        cout << "It is not a palindrome" << endl;

    return 0;
}