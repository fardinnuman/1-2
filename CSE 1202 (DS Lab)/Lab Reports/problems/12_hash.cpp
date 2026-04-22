#include <iostream>
using namespace std;

#define TABLE_SIZE 10

int hash_table[TABLE_SIZE];

int hash_func(int key)
{
    return key % TABLE_SIZE;
}

void insert_hash(int key)
{
    int index = hash_func(key);
    int start = index;

    while (hash_table[index] != -1)
    {
        index = (index + 1) % TABLE_SIZE;
        if (index == start)
        {
            cout << "Table full!\n";
            return;
        }
    }

    hash_table[index] = key;
}

int search_hash(int key)
{
    int index = hash_func(key);
    int start = index;

    while (hash_table[index] != -1)
    {
        if (hash_table[index] == key)
            return index;

        index = (index + 1) % TABLE_SIZE;

        if (index == start)
            break;
    }

    return -1;
}

void delete_hash(int key)
{
    int idx = search_hash(key);
    if (idx != -1)
        hash_table[idx] = -1;
    else
        cout << "Not found!\n";
}

void display()
{
    for (int i = 0; i < TABLE_SIZE; i++)
        cout << i << " -> " << hash_table[i] << endl;
}

int main()
{
    for (int i = 0; i < TABLE_SIZE; i++)
        hash_table[i] = -1;

    int choice, val;

    while (true)
    {
        cout << "\n--- Hash Table Operations ---\n";
        cout << "1. Insert\n2. Search\n3. Delete\n4. Display\n5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> val;
            insert_hash(val);
            break;

        case 2:
            cout << "Enter value: ";
            cin >> val;
            if (search_hash(val) != -1)
                cout << "Found\n";
            else
                cout << "Not found\n";
            break;

        case 3:
            cout << "Enter value: ";
            cin >> val;
            delete_hash(val);
            break;

        case 4:
            display();
            break;

        case 5:
            return 0;

        default:
            cout << "Invalid choice!\n";
        }
    }
}
