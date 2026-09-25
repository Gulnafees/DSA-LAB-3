/* Problem Statement:
You are required to design and implement a menu-driven C++ program that demonstrates the use of Singly Linked Lists, one of the fundamental data structures in computer science. A linked list is a linear data structure where each element (called a node) contains two parts:
    1. Data field – to store the actual value.
    2. Pointer field (link) – to store the address of the next node in the sequence.
Unlike arrays, linked lists do not require contiguous memory allocation, making them efficient for insertion and deletion operations at arbitrary positions. Through this task, you will practice dynamic memory allocation, pointer manipulation, and function-based program design.
Your program should perform the following tasks:
    1. Create a simple linked list with insertion at the head
        ◦ Implement a function insertAtHead() which takes an integer value as input, dynamically creates a new node, and inserts it at the beginning of the list.
        ◦ Demonstrate this by inserting multiple nodes so that the most recently inserted node always becomes the new head of the list.
    2. Insert a node at the 3rd location of the linked list
        ◦ Implement a function insertAtThird() that creates a new node and inserts it specifically at the 3rd position of the list.
        ◦ If the list has fewer than 2 nodes, display a message and handle insertion appropriately (either at the end or with an error message).
        ◦ This will require traversal of the list until the correct insertion point is found.
    3. Display the contents of the linked list
        ◦ Write a function displayList() that traverses the entire list from the head node to the last node and prints all the values in sequence, separated by arrows (->).
        ◦ Ensure that the list clearly shows the termination at NULL.
    4. Delete the last node of the linked list
        ◦ Implement a function deleteLast() which removes the final node in the list.
        ◦ Special cases must be handled, such as when the list is empty or when there is only one node.
        ◦ After deletion, display the updated list to confirm the operation.
    5. Count the number of nodes present in the list
        ◦ Write a function countNodes() which traverses the linked list and returns the total number of nodes currently present.
        ◦ Display the count to the user as part of the program’s menu options.
    6. Reverse the linked list iteratively
        ◦ Implement a function reverseList() which modifies the list so that the last node becomes the first, the second-last becomes the second, and so on.
        ◦ This should be done iteratively (not using recursion).
        ◦ After reversal, display the updated list to confirm correctness.
    7. Search for a given value in the list
        ◦ Implement a function searchValue() that accepts a value from the user and checks if it exists in the linked list.
        ◦ If found, display the position (index) of the node where the value occurs.
        ◦ If not found, display an appropriate message.
    8. Menu-driven interface
        ◦ In the main() function, design a menu that repeatedly prompts the user to select one of the operations listed above (insert at head, insert at 3rd position, display, delete last, count, reverse, search, exit).
        ◦ The program should continue to run until the user chooses the exit option.
        ◦ Each menu option should invoke the corresponding function and display the results clearly.*/
#include <iostream>
using namespace std;

// Node Structure
struct Node {
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

Node* head = NULL;

// 1. Insert at Head
void insertAtHead(int val) {
    Node* newNode = new Node(val);
    newNode->next = head;
    head = newNode;
    cout << "Inserted " << val << " at head." << endl;
}

// 2. Insert at 3rd Location
void insertAtThird(int val) {
    if (head == NULL || head->next == NULL) {
        cout << "Fewer than 2 nodes! Cannot insert at 3rd position." << endl;
        return;
    }

    Node* temp = head->next; // Point to 2nd node
    Node* newNode = new Node(val);
    newNode->next = temp->next;
    temp->next = newNode;
    cout << "Inserted " << val << " at 3rd location." << endl;
}

// 3. Display List
void displayList() {
    if (head == NULL) {
        cout << "List is empty (NULL)" << endl;
        return;
    }

    Node* temp = head;
    cout << "List: ";
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// 4. Delete Last Node
void deleteLast() {
    if (head == NULL) {
        cout << "List is empty!" << endl;
        return;
    }

    if (head->next == NULL) {
        delete head;
        head = NULL;
        cout << "Deleted last node." << endl;
        return;
    }

    Node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    delete temp->next;
    temp->next = NULL;
    cout << "Deleted last node." << endl;
}

// 5. Count Nodes
int countNodes() {
    int count = 0;
    Node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

// 6. Reverse Linked List Iteratively
void reverseList() {
    Node* prev = NULL;
    Node* current = head;
    Node* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    cout << "List reversed." << endl;
}

// 7. Search Value
void searchValue(int val) {
    Node* temp = head;
    int index = 1;

    while (temp != NULL) {
        if (temp->data == val) {
            cout << "Value " << val << " found at index: " << index << endl;
            return;
        }
        temp = temp->next;
        index++;
    }

    cout << "Value " << val << " not found in the list." << endl;
}

// 8. Menu-Driven Interface
int main() {
    int choice, val;

    do {
        cout << "--- MENU ---" << endl;
        cout << "1. Insert at Head" << endl;
        cout << "2. Insert at 3rd Position" << endl;
        cout << "3. Display List" << endl;
        cout << "4. Delete Last Node" << endl;
        cout << "5. Count Nodes" << endl;
        cout << "6. Reverse List" << endl;
        cout << "7. Search Value" << endl;
        cout << "8. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                insertAtHead(val);
                break;
            case 2:
                cout << "Enter value: ";
                cin >> val;
                insertAtThird(val);
                break;
            case 3:
                displayList();
                break;
            case 4:
                deleteLast();
                displayList();
                break;
            case 5:
                cout << "Total Nodes: " << countNodes() << endl;
                break;
            case 6:
                reverseList();
                displayList();
                break;
            case 7:
                cout << "Enter value: ";
                cin >> val;
                searchValue(val);
                break;
            case 8:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 8);

    return 0;
}