#include <iostream>
#include <string>
using namespace std;

// NODE CLASS FOR SINGLY LINKED LIST

class SNode
{
public:
    int data;
    SNode* next;

    SNode(int value)
    {
        data = value;
        next = NULL;
    }
};


// NODE CLASS FOR DOUBLY LINKED LIST

class DNode
{
public:
    int data;
    DNode* next;
    DNode* prev;

    DNode(int value)
    {
        data = value;
        next = NULL;
        prev = NULL;
    }
};



// SINGLY LINKED LIST CLASS


class SinglyLinkedList
{
private:
    SNode* head;

public:

    SinglyLinkedList()
    {
        head = NULL;
    }

    void insert(int value)
    {
        SNode* newNode = new SNode(value);

        if (head == NULL)
        {
            head = newNode;
            return;
        }

        SNode* temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    // Insertion Sort
    void insertionSort()
    {
        if (head == NULL || head->next == NULL)
            return;

        SNode* sorted = NULL;
        SNode* current = head;

        while (current != NULL)
        {
            SNode* nextNode = current->next;

            if (sorted == NULL || current->data < sorted->data)
            {
                current->next = sorted;
                sorted = current;
            }
            else
            {
                SNode* temp = sorted;

                while (temp->next != NULL &&
                       temp->next->data <= current->data)
                {
                    temp = temp->next;
                }

                current->next = temp->next;
                temp->next = current;
            }

            current = nextNode;
        }

        head = sorted;
    }

    bool hasCycle()
    {
        SNode* slow = head;
        SNode* fast = head;

        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
                return true;
        }

        return false;
    }

    int getSize()
    {
        int count = 0;
        SNode* temp = head;

        while (temp != NULL)
        {
            count++;
            temp = temp->next;
        }

        return count;
    }

    void copyValues(int arr[])
    {
        SNode* temp = head;
        int i = 0;

        while (temp != NULL)
        {
            arr[i] = temp->data;
            i++;
            temp = temp->next;
        }
    }

    void display()
    {
        SNode* temp = head;

        while (temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }

        cout << "NULL";
    }
};


// DOUBLY LINKED LIST CLASS

class DoublyLinkedList
{
private:
    DNode* head;
    DNode* tail;

public:

    DoublyLinkedList()
    {
        head = NULL;
        tail = NULL;
    }

    void insert(int value)
    {
        DNode* newNode = new DNode(value);

        if (head == NULL)
        {
            head = tail = newNode;
            return;
        }

        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    // Insertion Sort
    void insertionSort()
    {
        if (head == NULL || head->next == NULL)
            return;

        DNode* current = head->next;

        while (current != NULL)
        {
            int key = current->data;
            DNode* temp = current->prev;

            while (temp != NULL && temp->data > key)
            {
                temp->next->data = temp->data;
                temp = temp->prev;
            }

            if (temp == NULL)
                head->data = key;
            else
                temp->next->data = key;

            current = current->next;
        }
    }

    bool hasCycle()
    {
        DNode* slow = head;
        DNode* fast = head;

        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
                return true;
        }

        return false;
    }

    int getSize()
    {
        int count = 0;
        DNode* temp = head;

        while (temp != NULL)
        {
            count++;
            temp = temp->next;
        }

        return count;
    }

    void copyValues(int arr[])
    {
        DNode* temp = head;
        int i = 0;

        while (temp != NULL)
        {
            arr[i] = temp->data;
            i++;
            temp = temp->next;
        }
    }

    void display()
    {
        DNode* temp = head;

        while (temp != NULL)
        {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }

        cout << "NULL";
    }
};


// CIRCULAR LINKED LIST CLASS

class CircularLinkedList
{
private:
    SNode* head;

public:

    CircularLinkedList()
    {
        head = NULL;
    }

    void insert(int value)
    {
        SNode* newNode = new SNode(value);

        if (head == NULL)
        {
            head = newNode;
            newNode->next = head;
            return;
        }

        SNode* temp = head;

        while (temp->next != head)
        {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->next = head;
    }

    // Insertion Sort
    void insertionSort()
    {
        if (head == NULL || head->next == head)
            return;

        SNode* current = head->next;

        while (current != head)
        {
            int key = current->data;

            SNode* previous = head;

            while (previous->next != current)
            {
                previous = previous->next;
            }

            SNode* temp = head;

            while (temp != current &&
                   temp->data <= key)
            {
                temp = temp->next;
            }

            if (temp != current)
            {
                int value = current->data;

                while (current != temp)
                {
                    SNode* p = head;

                    while (p->next != current)
                    {
                        p = p->next;
                    }

                    current->data = p->data;
                    current = p;
                }

                temp->data = value;
            }

            current = current->next;
        }
    }

    bool hasCycle()
    {
        if (head == NULL)
            return false;

        SNode* slow = head;
        SNode* fast = head;

        do
        {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
                return true;

        } while (fast != head && fast->next != head);

        return false;
    }

    int getSize()
    {
        if (head == NULL)
            return 0;

        int count = 0;
        SNode* temp = head;

        do
        {
            count++;
            temp = temp->next;

        } while (temp != head);

        return count;
    }

    void copyValues(int arr[])
    {
        if (head == NULL)
            return;

        SNode* temp = head;
        int i = 0;

        do
        {
            arr[i] = temp->data;
            i++;
            temp = temp->next;

        } while (temp != head);
    }

    void display()
    {
        if (head == NULL)
        {
            cout << "EMPTY";
            return;
        }

        SNode* temp = head;

        do
        {
            cout << temp->data << " -> ";
            temp = temp->next;

        } while (temp != head);

        cout << "(back to HEAD)";
    }
};


// DOUBLY CIRCULAR LINKED LIST CLASS

class DoublyCircularLinkedList
{
private:
    DNode* head;
    DNode* tail;

public:

    DoublyCircularLinkedList()
    {
        head = NULL;
        tail = NULL;
    }

    void insert(int value)
    {
        DNode* newNode = new DNode(value);

        if (head == NULL)
        {
            head = tail = newNode;

            head->next = head;
            head->prev = head;

            return;
        }

        newNode->prev = tail;
        newNode->next = head;

        tail->next = newNode;
        head->prev = newNode;

        tail = newNode;
    }

    // Insertion Sort
    void insertionSort()
    {
        if (head == NULL || head->next == head)
            return;

        DNode* current = head->next;

        while (current != head)
        {
            int key = current->data;
            DNode* temp = current->prev;

            while (temp != head &&
                   temp->data > key)
            {
                temp->next->data = temp->data;
                temp = temp->prev;
            }

            if (temp == head &&
                head->data > key)
            {
                head->data = key;
            }
            else
            {
                temp->next->data = key;
            }

            current = current->next;
        }
    }

    bool hasCycle()
    {
        if (head == NULL)
            return false;

        DNode* slow = head;
        DNode* fast = head;

        do
        {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
                return true;

        } while (fast != head && fast->next != head);

        return false;
    }

    int getSize()
    {
        if (head == NULL)
            return 0;

        int count = 0;
        DNode* temp = head;

        do
        {
            count++;
            temp = temp->next;

        } while (temp != head);

        return count;
    }

    void copyValues(int arr[])
    {
        if (head == NULL)
            return;

        DNode* temp = head;
        int i = 0;

        do
        {
            arr[i] = temp->data;
            i++;
            temp = temp->next;

        } while (temp != head);
    }

    void display()
    {
        if (head == NULL)
        {
            cout << "EMPTY";
            return;
        }

        DNode* temp = head;

        do
        {
            cout << temp->data << " <-> ";
            temp = temp->next;

        } while (temp != head);

        cout << "(back to HEAD)";
    }
};

// LIST RECORD CLASS

class ListRecord
{
public:
    string type;

    SinglyLinkedList singly;
    DoublyLinkedList doubly;
    CircularLinkedList circular;
    DoublyCircularLinkedList doublyCircular;

    int size;

    ListRecord()
    {
        type = "";
        size = 0;
    }
};


// BUBBLE SORT

void bubbleSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        bool swapped = false;

        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                swapped = true;
            }
        }

        if (!swapped)
            break;
    }
}



// CHECK COMPATIBILITY


bool compatible(string a, string b)
{
    if (a == "Singly" && b == "Circular")
        return true;

    if (a == "Circular" && b == "Singly")
        return true;

    if (a == "Doubly" && b == "Doubly Circular")
        return true;

    if (a == "Doubly Circular" && b == "Doubly")
        return true;

    return false;
}


int main()
{
    int n;

    cout << "Enter number of linked lists: ";
    cin >> n;

    if (n < 12)
    {
        cout << "\nAt least 12 linked lists are required.\n";
        return 0;
    }

    // Dynamic array instead of vector
    ListRecord* lists = new ListRecord[n];

    int singlyCount = 0;
    int doublyCount = 0;
    int circularCount = 0;
    int doublyCircularCount = 0;



    // INPUT
  

    for (int i = 0; i < n; i++)
    {
        cout << "\n\n";
        cout << "Linked List " << i + 1 << endl;
        cout << "\n";

        int choice;

        cout << "1. Singly\n";
        cout << "2. Doubly\n";
        cout << "3. Circular\n";
        cout << "4. Doubly Circular\n";

        cout << "Enter type: ";
        cin >> choice;

        string selectedType;

        if (choice == 1)
            selectedType = "Singly";
        else if (choice == 2)
            selectedType = "Doubly";
        else if (choice == 3)
            selectedType = "Circular";
        else if (choice == 4)
            selectedType = "Doubly Circular";
        else
        {
            cout << "Invalid choice.\n";
            i--;
            continue;
        }


        // No consecutive same types
        if (i > 0 && selectedType == lists[i - 1].type)
        {
            cout << "\nERROR: Consecutive lists cannot have "
                 << "the same type.\n";

            i--;
            continue;
        }

        lists[i].type = selectedType;


        if (selectedType == "Singly")
            singlyCount++;

        else if (selectedType == "Doubly")
            doublyCount++;

        else if (selectedType == "Circular")
            circularCount++;

        else
            doublyCircularCount++;


        int elements;

        cout << "Enter number of elements: ";
        cin >> elements;

        lists[i].size = elements;

        cout << "Enter elements:\n";

        for (int j = 0; j < elements; j++)
        {
            int value;
            cin >> value;

            if (selectedType == "Singly")
                lists[i].singly.insert(value);

            else if (selectedType == "Doubly")
                lists[i].doubly.insert(value);

            else if (selectedType == "Circular")
                lists[i].circular.insert(value);

            else
                lists[i].doublyCircular.insert(value);
        }
    }


    //
    // CHECK MINIMUM OCCURRENCE
    //

    if (singlyCount < 3 ||
        doublyCount < 3 ||
        circularCount < 3 ||
        doublyCircularCount < 3)
    {
        cout << "\nERROR!\n";
        cout << "Every type must occur at least 3 times.\n\n";

        cout << "Singly = " << singlyCount << endl;
        cout << "Doubly = " << doublyCount << endl;
        cout << "Circular = " << circularCount << endl;
        cout << "Doubly Circular = "
             << doublyCircularCount << endl;

        delete[] lists;
        return 0;
    }


    //
    // INSERTION SORT
    //

    cout << "\n\n\n";
    cout << "AFTER INSERTION SORT\n";
    cout << "\n";

    for (int i = 0; i < n; i++)
    {
        cout << "\nPosition " << i + 1
             << " [" << lists[i].type << "]: ";

        if (lists[i].type == "Singly")
        {
            lists[i].singly.insertionSort();
            lists[i].singly.display();
        }

        else if (lists[i].type == "Doubly")
        {
            lists[i].doubly.insertionSort();
            lists[i].doubly.display();
        }

        else if (lists[i].type == "Circular")
        {
            lists[i].circular.insertionSort();
            lists[i].circular.display();
        }

        else
        {
            lists[i].doublyCircular.insertionSort();
            lists[i].doublyCircular.display();
        }

        cout << endl;
    }


    //
    // CYCLE DETECTION
    //

    cout << "\n\n\n";
    cout << "CYCLE DETECTION\n";
    cout << "\n";

    for (int i = 0; i < n; i++)
    {
        bool cycle = false;

        if (lists[i].type == "Singly")
            cycle = lists[i].singly.hasCycle();

        else if (lists[i].type == "Doubly")
            cycle = lists[i].doubly.hasCycle();

        else if (lists[i].type == "Circular")
            cycle = lists[i].circular.hasCycle();

        else
            cycle = lists[i].doublyCircular.hasCycle();

        cout << "Position " << i + 1
             << " [" << lists[i].type << "] : ";

        if (cycle)
            cout << "Cycle detected";
        else
            cout << "No cycle";

        cout << endl;
    }

    // FIND CYCLIC GROUPS

    bool* used = new bool[n];

    for (int i = 0; i < n; i++)
        used[i] = false;

    int cycleCount = 0;

    cout << "\n\n\n";
    cout << "CYCLIC GROUPS\n";
    cout << "\n";


    for (int i = 0; i < n; i++)
    {
        if (used[i])
            continue;

        // Only Circular or Doubly Circular can start a cycle
        if (lists[i].type != "Circular" &&
            lists[i].type != "Doubly Circular")
        {
            continue;
        }

        int start = i;
        int end = i;


        // Go backwards through compatible lists
        while (start > 0 &&
               compatible(lists[start - 1].type,
                          lists[start].type))
        {
            start--;
        }


        // Go forward through compatible lists
        while (end < n - 1 &&
               compatible(lists[end].type,
                          lists[end + 1].type))
        {
            end++;
        }


        cycleCount++;

        cout << "\nCycle " << cycleCount << ": ";

        for (int j = start; j <= end; j++)
        {
            used[j] = true;

            cout << "Position " << j + 1
                 << " [" << lists[j].type << "]";

            if (j < end)
                cout << " -> ";
        }

        cout << endl;
    }

    // MERGE CYCLIC LISTS
  
    cout << "\n\n\n";
    cout << "MERGED CYCLIC LISTS\n";
    cout << "\n";


    for (int i = 0; i < n; i++)
    {
        if (!used[i])
            continue;

        // Find beginning of this cycle
        int start = i;

        while (start > 0 &&
               used[start - 1])
        {
            start--;
        }

        // We only process when i is the first position
        if (i != start)
            continue;

        // Find end
        int end = start;

        while (end < n - 1 &&
               used[end + 1])
        {
            end++;
        }


        // Calculate total size
        int totalSize = 0;

        for (int j = start; j <= end; j++)
        {
            totalSize += lists[j].size;
        }


        // Dynamic array for merged elements
        int* merged = new int[totalSize];

        int index = 0;


        // Copy elements
        for (int j = start; j <= end; j++)
        {
            int size = lists[j].size;

            int* tempArray = new int[size];


            if (lists[j].type == "Singly")
                lists[j].singly.copyValues(tempArray);

            else if (lists[j].type == "Doubly")
                lists[j].doubly.copyValues(tempArray);

            else if (lists[j].type == "Circular")
                lists[j].circular.copyValues(tempArray);

            else
                lists[j].doublyCircular.copyValues(tempArray);


            for (int k = 0; k < size; k++)
            {
                merged[index] = tempArray[k];
                index++;
            }

            delete[] tempArray;
        }


        // Bubble Sort merged list
        bubbleSort(merged, totalSize);


        cout << "\nMerged Cycle: ";

        for (int j = 0; j < totalSize; j++)
        {
            cout << merged[j];

            if (j < totalSize - 1)
                cout << " -> ";
        }

        cout << endl;


        delete[] merged;
    }


    //
    // FINAL OUTPUT
    //

    cout << "\n\n\n";
    cout << "FINAL RESULT\n";
    cout << "\n";

    cout << "Number of cycles = "
         << cycleCount << endl;


    cout << "\nAll resultant lists:\n";

    for (int i = 0; i < n; i++)
    {
        cout << "\nPosition " << i + 1
             << " [" << lists[i].type << "]: ";

        if (lists[i].type == "Singly")
            lists[i].singly.display();

        else if (lists[i].type == "Doubly")
            lists[i].doubly.display();

        else if (lists[i].type == "Circular")
            lists[i].circular.display();

        else
            lists[i].doublyCircular.display();

        cout << endl;
    }


    delete[] used;
    delete[] lists;

    return 0;
}