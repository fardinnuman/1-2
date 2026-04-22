#include <iostream>
using namespace std;

#define MAX 100

int heap[MAX];
int heap_size = 0;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void heapify_up(int i)
{
    while (i > 0 && heap[(i - 1) / 2] < heap[i])
    {
        swap(heap[i], heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void heapify_down(int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < heap_size && heap[left] > heap[largest])
        largest = left;

    if (right < heap_size && heap[right] > heap[largest])
        largest = right;

    if (largest != i)
    {
        swap(heap[i], heap[largest]);
        heapify_down(largest);
    }
}

void insert_heap(int val)
{
    heap[heap_size] = val;
    heap_size++;
    heapify_up(heap_size - 1);
}

void delete_heap()
{
    if (heap_size <= 0)
    {
        cout << "Heap empty!\n";
        return;
    }

    heap[0] = heap[heap_size - 1];
    heap_size--;
    heapify_down(0);
}

void print_heap()
{
    for (int i = 0; i < heap_size; i++)
        cout << heap[i] << " ";
    cout << endl;
}

int main()
{
    int choice, val;

    while (true)
    {
        cout << "\n--- Heap Operations ---\n";
        cout << "1. Insert\n2. Delete\n3. Print\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> val;
            insert_heap(val);
            break;

        case 2:
            delete_heap();
            break;

        case 3:
            print_heap();
            break;

        case 4:
            return 0;

        default:
            cout << "Invalid choice!\n";
        }
    }
}

