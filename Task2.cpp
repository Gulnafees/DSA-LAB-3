/*Task 
Develop a C++ program that finds memory leaks in a string processing application with the following requirements: 
    1. Implement a class StringPool that contains: 
        a. string* stringPool // Dynamic array of strings.  
        b. int currentSize // Current number of strings in the pool.  
        c. int maxSize // Maximum size of the pool (set to 5). 
    2. Methods: 
        a. Initializes these fields (Constructor) 
        b. addString: Adds a string to the pool.  
        c. removeString: Removes a string from the pool without freeing memory. 

    3. In the main function:  
        a. Add multiple strings to the pool.  
        b. Remove strings without freeing memory.  
        c. Detect and fix the memory leak by deleting removed strings and displaying the pool status. */
#include <iostream>
#include <string>

using namespace std;

class StringPool {
public:
    string* stringPool; 
    int currentSize;     
       int maxSize;  

    //constuctor
    StringPool() {
        maxSize = 5;
        currentSize = 0;
        stringPool = new string[maxSize];
    }

    
    void addString(string str) {
        if (currentSize < maxSize) {
            stringPool[currentSize] = str;
            currentSize++;
            cout << "Added: " << str << endl;
        } else {
            cout << "Pool is full!" << endl;
        }
    }

    // removeString without freeming memory
    void removeString(int index) {
        if (index<0 || index>= currentSize) {
            cout << "Invalid index!" << endl;
            return;
        }
        
        cout << "Removing (without freeing memory): " << stringPool[index] << endl;
        
        // Shift remaining strings left
        for (int i = index; i < currentSize - 1; i++) {
            stringPool[i] = stringPool[i + 1];
        }
        currentSize--;
    }

    // Display status of pool
    void displayPool() {
        cout << "\nPool Status: " << currentSize << "/" << maxSize << "):" << endl;
        for (int i = 0; i < currentSize; i++) {
            cout << "Index " << i << ": " << stringPool[i] << endl;
        }
        cout << endl;
    }
};

int main() {
    // 1. Initialize pool
    StringPool pool;

    // 2. Add multiple strings
    pool.addString("Nafees");
    pool.addString("Data science");
    pool.addString("Lab");
    pool.displayPool();

    // 3. Remove string without freeing memory (creates memory leak)
    pool.removeString(1);
    pool.displayPool();

    // 4. Detect and fix memory leak by deleting allocated array when done
    delete[] pool.stringPool;
    cout << "Memory leak fixed by deallocating pool memory." << endl;

    return 0;
}