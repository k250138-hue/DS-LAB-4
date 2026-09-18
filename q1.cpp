#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;
    Node* child;

    Node(int value)
    {
        data = value;
        next = nullptr;
        child = nullptr;
    }
};

// Flatten the peculiar linked list
Node* flatten(Node* head)
{
    if (head == nullptr)
        return nullptr;

    Node* cur = head;
    Node* tail = head;

    while (cur != nullptr)
    {
        Node* originalNext = cur->next;

        if (cur->child != nullptr)
        {
            Node* childHead = cur->child;

            Node* childTail = flatten(childHead);

            cur->next = childHead;
            cur->child = nullptr;

            childTail->next = originalNext;

            tail = childTail;
        }
        else
        {
            tail = cur;
        }

        if (originalNext == nullptr)
            break;

        cur = originalNext;
    }

    return tail;
}

void printList(Node* head)
{
    Node* temp = head;

    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

int main()
{
    int n;

    cout << "Enter number of nodes: ";
    cin >> n;

    Node** nodes = new Node*[n];

    // Create nodes
    for (int i = 0; i < n; i++)
    {
        int data;

        cout << "Enter data for node " << i + 1 << ": ";
        cin >> data;

        nodes[i] = new Node(data);
    }

    // Enter next and child positions
    for (int i = 0; i < n; i++)
    {
        int nextIndex, childIndex;

        cout << "\nFor node " << nodes[i]->data << endl;

        cout << "Enter next node index (-1 for NULL): ";
        cin >> nextIndex;

        cout << "Enter child node index (-1 for NULL): ";
        cin >> childIndex;

        if (nextIndex != -1)
            nodes[i]->next = nodes[nextIndex];

        if (childIndex != -1)
            nodes[i]->child = nodes[childIndex];
    }

    Node* head = nodes[0];

    // Flatten the list
    flatten(head);

    cout << "\nFinal list: ";
    printList(head);
    for (int i = 0; i < n; i++)
    {
        delete nodes[i];
    }

    delete[] nodes;

    return 0;
}
