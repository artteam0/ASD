#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <chrono>

using namespace std;
#define INT_MAX 32767
double a, b;

struct Notebook {
    int key;
    string full_name;
};

int hashFunction(int key, int size) 
{
    return key % size;
}

void Add(vector<list<Notebook>>& notebookArray, int key, string& full_name) 
{
    int ind = hashFunction(key, notebookArray.size());
    notebookArray[ind].push_back({ key, full_name });
}

void Display(vector<list<Notebook>>& notebookArray) 
{
    cout << "Notebook" << endl;
    for (int i = 0; i < notebookArray.size(); ++i) {
        cout << "Element " << i << ": ";
        for ( auto& element : notebookArray[i]) {
            cout << "Phone number: " << element.key << ". Full name: " << element.full_name << " ";
        }
        cout << endl;
    }
}

void Del(vector<list<Notebook>>& notebookArray, int key) 
{
    int ind = hashFunction(key, notebookArray.size());
    for (auto pointer = notebookArray[ind].begin(); pointer != notebookArray[ind].end(); ++pointer) {
        if (pointer->key == key) {
            notebookArray[ind].erase(pointer);
            return;
        }
    }
}

void Search(vector<list<Notebook>>& notebookArray, int key) 
{
    int ind = hashFunction(key, notebookArray.size());
    for (auto& element : notebookArray[ind]) {
        if (element.key == key) {
            cout << "Phone number: " << element.key << ". Full name: " << element.full_name << endl;
        }
    }
    cout << "Phone number " << key << " not found." << endl;
}

int main() {
    int choice;
    int size;
    cout << "Enter size: ";
    cin >> size;
    vector<list<Notebook>> notebookArray(size);

    auto start_time = chrono::steady_clock::now();
    auto end_time = chrono::steady_clock::now();

    for (;;) {
        cout << "1. Add" << endl;
        cout << "2. Display" << endl;
        cout << "3. Del" << endl;
        cout << "4. Search" << endl;
        cout << "5. Exit" << endl;
        cin >> choice;

        switch (choice) {
        case 1: {
            int key;
            string full_name;
            cout << "Key (max 32767; min 1): ";
            cin >> key;
            if (key > INT_MAX || key <= 0) {
                cout << "Error." << endl;
                break;
            }
            cout << "Full name: ";
            cin.ignore();
            getline(cin, full_name);
            Add(notebookArray, key, full_name);
            break;
        }
        case 2:
            Display(notebookArray);
            break;
        case 3: {
            int key;
            cout << "Phone number to delete: ";
            cin >> key;
            Del(notebookArray, key);
            break;
        }
        case 4: {
            int key;
            cout << "Phone number to search: ";
            cin >> key;
            start_time = chrono::steady_clock::now();
            Search(notebookArray, key);
            end_time = chrono::steady_clock::now();
            cout << "Time of searching: " << chrono::duration_cast<chrono::nanoseconds>(end_time - start_time).count() << " nanoseconds" << endl;
            break;
        }
        case 5:
            return 0;
        default:
            cout << "Error." << endl;
            break;
        }
    }

    return 0;
}
