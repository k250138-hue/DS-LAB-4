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
// Returns the tail of the flattened list
Node* flatten(Node* head)
{
    if (head == nullptr)
        return nullptr;

    Node* cur = head;
    Node* tail = head;

    while (cur != nullptr)
    {
        // Save original next
        Node* originalNext = cur->next;

        // If current node has a child
        if (cur->child != nullptr)
        {
            Node* childHead = cur->child;

            // Recursively flatten child list
            Node* childTail = flatten(childHead);

            // Put child list after current node
            cur->next = childHead;

            // Remove child pointer
            cur->child = nullptr;

            // Connect child tail to original next
            childTail->next = originalNext;

            // Update tail
            tail = childTail;
        }
        else
        {
            tail = cur;
        }

        // Continue with original next
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

    // First node is the head
    Node* head = nodes[0];

    // Flatten the list
    flatten(head);

    cout << "\nFinal list: ";
    printList(head);

    // Delete nodes
    for (int i = 0; i < n; i++)
    {
        delete nodes[i];
    }

    delete[] nodes;

    return 0;
}