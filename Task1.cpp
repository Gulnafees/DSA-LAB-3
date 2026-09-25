#include <iostream>
#include <string>
#include <cctype>

using namespace std;

// Function to check if a string is a palindrome iteratively
bool isPalindrome(string str) {
    int left = 0;
    int right = str.length() - 1;

    while (left < right) {
        if (str[left] != str[right]) {
            return false; // Not a palindrome
        }
        left++;
        right--;
    }
    return true; // Is a palindrome
}

int main() {
    string str;
    cout << "Enter a string: ";
    getline(cin, str);

    // Remove spaces and non-alphanumeric characters, and convert to lowercase
    string processedStr;
    for (char c : str) {
        if (isalnum(c)) { // Check if the character is alphanumeric
            processedStr += tolower(c); // Convert to lowercase and append
        }
    }

    if (isPalindrome(processedStr)) {
        cout << "\"" << str << "\" is a palindrome." << endl;
    } else {
        cout << "\"" << str << "\" is not a palindrome." << endl;
    }

    return 0;
}