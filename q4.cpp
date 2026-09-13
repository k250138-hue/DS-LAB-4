#include <iostream>
using namespace std;


// SINGLY LINKED LIST

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


class SinglyLinkedList
{
private:
    SNode* head;
    SNode* tail;
    int size;

public:

    SinglyLinkedList()
    {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    void insert(int value)
    {
        SNode* newNode = new SNode(value);

        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }

        size++;
    }

    void rotateLeft(int k)
    {
        if (head == NULL || size <= 1)
            return;

        k = k % size;

        if (k == 0)
            return;

        // Make the list temporarily circular
        tail->next = head;

        SNode* newTail = head;

        for (int i = 1; i < k; i++)
        {
            newTail = newTail->next;
        }

        head = newTail->next;
        tail = newTail;

        // Break the circle
        tail->next = NULL;
    }

    void rotateRight(int k)
    {
        if (head == NULL || size <= 1)
            return;

        k = k % size;

        if (k == 0)
            return;

        // Right rotation by k
        // is same as left rotation by size-k
        rotateLeft(size - k);
    }

    void display()
    {
        SNode* temp = head;

        while (temp != NULL)
        {
            cout << temp->data;

            if (temp->next != NULL)
                cout << " -> ";

            temp = temp->next;
        }

        cout << endl;
    }
};


// DOUBLY LINKED LIST

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


class DoublyLinkedList
{
private:
    DNode* head;
    DNode* tail;
    int size;

public:

    DoublyLinkedList()
    {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    void insert(int value)
    {
        DNode* newNode = new DNode(value);

        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }

        size++;
    }

    void rotateLeft(int k)
    {
        if (head == NULL || size <= 1)
            return;

        k = k % size;

        if (k == 0)
            return;

        // Temporarily make it circular
        tail->next = head;
        head->prev = tail;

        DNode* newTail = head;

        for (int i = 1; i < k; i++)
        {
            newTail = newTail->next;
        }

        DNode* newHead = newTail->next;

        // Break the circle
        newTail->next = NULL;
        newHead->prev = NULL;

        head = newHead;
        tail = newTail;
    }

    void rotateRight(int k)
    {
        if (head == NULL || size <= 1)
            return;

        k = k % size;

        if (k == 0)
            return;

        rotateLeft(size - k);
    }

    void display()
    {
        DNode* temp = head;

        while (temp != NULL)
        {
            cout << temp->data;

            if (temp->next != NULL)
                cout << " <-> ";

            temp = temp->next;
        }

        cout << endl;
    }
};


// CIRCULAR LINKED LIST

class CNode
{
public:
    int data;
    CNode* next;

    CNode(int value)
    {
        data = value;
        next = NULL;
    }
};


class CircularLinkedList
{
private:
    CNode* head;
    CNode* tail;
    int size;

public:

    CircularLinkedList()
    {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    void insert(int value)
    {
        CNode* newNode = new CNode(value);

        if (head == NULL)
        {
            head = tail = newNode;

            tail->next = head;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
            tail->next = head;
        }

        size++;
    }

    void rotateLeft(int k)
    {
        if (head == NULL || size <= 1)
            return;

        k = k % size;

        if (k == 0)
            return;

        // Since the list is already circular,
        // simply move head k times.

        for (int i = 0; i < k; i++)
        {
            head = head->next;
        }

        // Tail is the node before head
        tail = head;

        while (tail->next != head)
        {
            tail = tail->next;
        }
    }

    void rotateRight(int k)
    {
        if (head == NULL || size <= 1)
            return;

        k = k % size;

        if (k == 0)
            return;

        // Move head backwards by k.
        // Since this is singly circular,
        // find the node before head.

        for (int i = 0; i < k; i++)
        {
            CNode* temp = head;

            while (temp->next != head)
            {
                temp = temp->next;
            }

            head = temp;
        }

        tail = head;

        while (tail->next != head)
        {
            tail = tail->next;
        }
    }

    void display()
    {
        if (head == NULL)
        {
            cout << "EMPTY" << endl;
            return;
        }

        CNode* temp = head;

        do
        {
            cout << temp->data;

            temp = temp->next;

            if (temp != head)
                cout << " -> ";

        } while (temp != head);

        cout << " -> HEAD" << endl;
    }
};


// DOUBLY CIRCULAR LINKED LIST

class DCNode
{
public:
    int data;
    DCNode* next;
    DCNode* prev;

    DCNode(int value)
    {
        data = value;
        next = NULL;
        prev = NULL;
    }
};


class DoublyCircularLinkedList
{
private:
    DCNode* head;
    DCNode* tail;
    int size;

public:

    DoublyCircularLinkedList()
    {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    void insert(int value)
    {
        DCNode* newNode = new DCNode(value);

        if (head == NULL)
        {
            head = tail = newNode;

            head->next = head;
            head->prev = head;
        }
        else
        {
            newNode->prev = tail;
            newNode->next = head;

            tail->next = newNode;
            head->prev = newNode;

            tail = newNode;
        }

        size++;
    }

    void rotateLeft(int k)
    {
        if (head == NULL || size <= 1)
            return;

        k = k % size;

        if (k == 0)
            return;

        for (int i = 0; i < k; i++)
        {
            head = head->next;
        }

        tail = head->prev;
    }

    void rotateRight(int k)
    {
        if (head == NULL || size <= 1)
            return;

        k = k % size;

        if (k == 0)
            return;

        for (int i = 0; i < k; i++)
        {
            head = head->prev;
        }

        tail = head->prev;
    }

    void display()
    {
        if (head == NULL)
        {
            cout << "EMPTY" << endl;
            return;
        }

        DCNode* temp = head;

        do
        {
            cout << temp->data;

            temp = temp->next;

            if (temp != head)
                cout << " <-> ";

        } while (temp != head);

        cout << " <-> HEAD" << endl;
    }
};

int main()
{
    int choice;
    int n;
    int k;
    char direction;


    cout << "========================================\n";
    cout << "     LINKED LIST ROTATION PROGRAM\n";
    cout << "========================================\n\n";


    // SELECT LIST TYPE

    cout << "Select Linked List Type:\n";
    cout << "1. Singly Linked List\n";
    cout << "2. Doubly Linked List\n";
    cout << "3. Circular Linked List\n";
    cout << "4. Doubly Circular Linked List\n";

    cout << "\nEnter your choice: ";
    cin >> choice;


    if (choice < 1 || choice > 4)
    {
        cout << "Invalid choice." << endl;
        return 0;
    }


    // NUMBER OF ELEMENTS

    cout << "\nEnter number of elements: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Number of elements must be greater than 0." << endl;
        return 0;
    }


    // CREATE THE SELECTED LIST

    if (choice == 1)
    {
        SinglyLinkedList list;

        cout << "Enter " << n << " elements:\n";

        for (int i = 0; i < n; i++)
        {
            int value;
            cin >> value;

            list.insert(value);
        }


        cout << "\nOriginal List:\n";
        list.display();


        cout << "\nEnter K: ";
        cin >> k;


        cout << "Enter direction (L for Left / R for Right): ";
        cin >> direction;


        if (direction == 'L' || direction == 'l')
        {
            list.rotateLeft(k);
        }
        else if (direction == 'R' || direction == 'r')
        {
            list.rotateRight(k);
        }
        else
        {
            cout << "Invalid direction." << endl;
            return 0;
        }


        cout << "\nRotated List:\n";
        list.display();
    }


    else if (choice == 2)
    {
        DoublyLinkedList list;

        cout << "Enter " << n << " elements:\n";

        for (int i = 0; i < n; i++)
        {
            int value;
            cin >> value;

            list.insert(value);
        }


        cout << "\nOriginal List:\n";
        list.display();


        cout << "\nEnter K: ";
        cin >> k;


        cout << "Enter direction (L for Left / R for Right): ";
        cin >> direction;


        if (direction == 'L' || direction == 'l')
        {
            list.rotateLeft(k);
        }
        else if (direction == 'R' || direction == 'r')
        {
            list.rotateRight(k);
        }
        else
        {
            cout << "Invalid direction." << endl;
            return 0;
        }


        cout << "\nRotated List:\n";
        list.display();
    }


    else if (choice == 3)
    {
        CircularLinkedList list;

        cout << "Enter " << n << " elements:\n";

        for (int i = 0; i < n; i++)
        {
            int value;
            cin >> value;

            list.insert(value);
        }


        cout << "\nOriginal List:\n";
        list.display();


        cout << "\nEnter K: ";
        cin >> k;


        cout << "Enter direction (L for Left / R for Right): ";
        cin >> direction;


        if (direction == 'L' || direction == 'l')
        {
            list.rotateLeft(k);
        }
        else if (direction == 'R' || direction == 'r')
        {
            list.rotateRight(k);
        }
        else
        {
            cout << "Invalid direction." << endl;
            return 0;
        }


        cout << "\nRotated List:\n";
        list.display();
    }


    else if (choice == 4)
    {
        DoublyCircularLinkedList list;

        cout << "Enter " << n << " elements:\n";

        for (int i = 0; i < n; i++)
        {
            int value;
            cin >> value;

            list.insert(value);
        }


        cout << "\nOriginal List:\n";
        list.display();


        cout << "\nEnter K: ";
        cin >> k;


        cout << "Enter direction (L for Left / R for Right): ";
        cin >> direction;


        if (direction == 'L' || direction == 'l')
        {
            list.rotateLeft(k);
        }
        else if (direction == 'R' || direction == 'r')
        {
            list.rotateRight(k);
        }
        else
        {
            cout << "Invalid direction." << endl;
            return 0;
        }


        cout << "\nRotated List:\n";
        list.display();
    }


    return 0;
}