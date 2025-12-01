#include<iostream>
using namespace std;

const int MAX = 100;
int arr[MAX], n = 0;

void create() {
    cout << "Enter the number of elements: ";
    cin >> n;
    cout << "Enter elements:";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

void display() {
    if(n == 0) {
        cout << "Array is empty.\n";
        return;
    }
    cout << "Array elements are: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void insert() {
    if(n == MAX) {
        cout << "Array is full, cannot insert.\n";
        return;
    }

    int pos, val;
    cout << "Enter position (0 to " << n << "): ";
    cin >> pos;
    if(pos < 0 || pos > n) {
        cout << "Invalid position.\n";
        return;
    }

    cout << "Enter value to insert: ";
    cin >> val;

    for(int i = n; i > pos; i--) {
        arr[i] = arr[i-1];
    }
    arr[pos] = val;
    n++;
    cout << "Element inserted.\n";
}

void Delete() {
    if(n == 0) {
        cout << "Array is empty, cannot delete.\n";
        return;
    }

    int pos;
    cout << "Enter position to delete (0 to " << n - 1 << "): ";
    cin >> pos;
    if(pos < 0 || pos >= n) {
        cout << "Invalid position.\n";
        return;
    }

    for(int i = pos; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    n--;
    cout << "Element deleted.\n";
}

void linearSearch() {
    if(n == 0) {
        cout << "Array is empty.\n";
        return;
    }

    int val, found = 0;
    cout << "Enter value to search: ";
    cin >> val;

    for(int i = 0; i < n; i++) {
        if(arr[i] == val) {
            cout << "Value found at index " << i << endl;
            found = 1;
            break;
        }
    }

    if(!found) {
        cout << "Value not found in array.\n";
    }
}

int main() {
    int choice;
    do {
        cout << "   MENU\n";
        cout << "1. CREATE\n2. DISPLAY\n3. INSERT\n4. DELETE\n5. LINEAR SEARCH\n6. EXIT\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1: create(); break;
            case 2: display(); break;
            case 3: insert(); break;
            case 4: Delete(); break;
            case 5: linearSearch(); break;
            case 6: cout << "Exiting program.\n"; break;
            default: cout << "Invalid choice. Try again.\n";
        }
    } while(choice != 6);

    return 0;
}
