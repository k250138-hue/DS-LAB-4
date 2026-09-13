#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;

    Node(int value)
    {
        data = value;
        next = NULL;
    }
};

class LinkedList
{
private:
    Node* head;

public:

    LinkedList()
    {
        head = NULL;
    }
    // INSERT AT END
    void insert(int value)
    {
        Node* newNode = new Node(value);

        if (head == NULL)
        {
            head = newNode;
            return;
        }

        Node* temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }
    // DISPLAY
    void display()
    {
        Node* temp = head;

        while (temp != NULL)
        {
            cout << temp->data;

            if (temp->next != NULL)
                cout << " -> ";

            temp = temp->next;
        }

        cout << endl;
    }
    // COUNT NUMBER OF NODES
    int getSize()
    {
        int count = 0;

        Node* temp = head;

        while (temp != NULL)
        {
            count++;
            temp = temp->next;
        }

        return count;
    }
    // REVERSE IN GROUPS OF K
    void reverseInGroups(int k)
    {
        if (head == NULL || k <= 1)
            return;

        Node* current = head;
        Node* previousGroupTail = NULL;

        while (current != NULL)
        {
            // Check whether at least K nodes remain

            Node* check = current;

            int count = 0;

            while (check != NULL && count < k)
            {
                check = check->next;
                count++;
            }

            // Fewer than K nodes remain
            // Leave them unchanged
            if (count < k)
                break;

            // Reverse K nodes

            Node* previous = NULL;
            Node* groupStart = current;

            for (int i = 0; i < k; i++)
            {
                Node* nextNode = current->next;

                current->next = previous;

                previous = current;
                current = nextNode;
            }

            // Connect previous group with current group

            if (previousGroupTail == NULL)
            {
                // First group
                head = previous;
            }
            else
            {
                previousGroupTail->next = previous;
            }


            // groupStart is now the last node
            // of the reversed group
            previousGroupTail = groupStart;
        }


        // Connect last reversed group to remaining nodes
        if (previousGroupTail != NULL)
        {
            previousGroupTail->next = current;
        }
    }
};

int main()
{
    LinkedList list;

    int n;
    int k;


    cout << "========================================\n";
    cout << "   REVERSE LINKED LIST IN GROUPS OF K\n";
    cout << "========================================\n";


    // INPUT NUMBER OF ELEMENTS

    cout << "\nEnter number of elements: ";
    cin >> n;


    if (n <= 0)
    {
        cout << "Number of elements must be greater than 0."
             << endl;

        return 0;
    }


    // INPUT ELEMENTS

    cout << "Enter " << n << " elements:\n";

    for (int i = 0; i < n; i++)
    {
        int value;

        cin >> value;

        list.insert(value);
    }


    // DISPLAY ORIGINAL LIST

    cout << "\nOriginal Linked List:\n";
    list.display();


    // INPUT K

    cout << "\nEnter K: ";
    cin >> k;


    if (k <= 0)
    {
        cout << "K must be greater than 0." << endl;

        return 0;
    }


    // REVERSE GROUPS

    list.reverseInGroups(k);


    // DISPLAY RESULT

    cout << "\nLinked List after reversing groups of "
         << k << ":\n";

    list.display();


    return 0;
}