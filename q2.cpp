#include <iostream>
using namespace std;

// Node class
class Node
{
public:
    int id;
    Node* next;
    Node* prev;

    Node(int value)
    {
        id = value;
        next = nullptr;
        prev = nullptr;
    }
};

// Find a coach
Node* searchCoach(Node* head, int id)
{
    if (head == nullptr)
        return nullptr;

    Node* current = head;

    do
    {
        if (current->id == id)
            return current;

        current = current->next;

    } while (current != head);

    return nullptr;
}

// Insert a NEW node at the end
void insertCoach(Node*& head, int id)
{
    Node* newNode = new Node(id);

    if (head == nullptr)
    {
        head = newNode;
        head->next = head;
        head->prev = head;
        return;
    }

    Node* tail = head->prev;

    newNode->next = head;
    newNode->prev = tail;

    tail->next = newNode;
    head->prev = newNode;
}

// Detach a node from the circular list
void detach(Node*& head, Node* node)
{
 
    if (node->next == node)
    {
        head = nullptr;
        delete node;
        return;
    }

    if (node == head)
    {
        head = node->next;
    }

    node->prev->next = node->next;
    node->next->prev = node->prev;

    delete node;
}

// Move existing node immediately after head
void moveRight(Node*& head, int id)
{
    Node* node = searchCoach(head, id);

    if (node == nullptr)
    {
        cout << "Coach " << id << " not found.\n";
        return;
    }

    if (head->next == node)
        return;

    if (node == head)
        return;

    node->prev->next = node->next;
    node->next->prev = node->prev;

    node->next = head->next;
    node->prev = head;

    head->next->prev = node;
    head->next = node;
}

// Move existing node immediately before head
void moveLeft(Node*& head, int id)
{
    Node* node = searchCoach(head, id);

    if (node == nullptr)
    {
        cout << "Coach " << id << " not found.\n";
        return;
    }

    if (head->prev == node)
        return;
    if (node == head)
        return;

    node->prev->next = node->next;
    node->next->prev = node->prev;

    node->next = head;
    node->prev = head->prev;

    head->prev->next = node;
    head->prev = node;
}

// Print train clockwise
void display(Node* head)
{
    if (head == nullptr)
    {
        cout << "Train is empty.\n";
        return;
    }

    Node* current = head;

    do
    {
        cout << current->id << " ";
        current = current->next;

    } while (current != head);

    cout << endl;
}

// Search using shorter direction
void findCoach(Node* head, int id)
{
    if (head == nullptr)
    {
        cout << "Train is empty.\n";
        return;
    }

    Node* target = searchCoach(head, id);

    if (target == nullptr)
    {
        cout << "Coach " << id << " not found.\n";
        return;
    }

    // Find steps using NEXT
    int nextSteps = 0;
    Node* current = head;

    while (current != target)
    {
        current = current->next;
        nextSteps++;
    }

    int prevSteps = 0;
    current = head;

    while (current != target)
    {
        current = current->prev;
        prevSteps++;
    }

    if (nextSteps <= prevSteps)
    {
        cout << "Direction: NEXT\n";
        cout << "Path: ";

        current = head;

        cout << current->id;

        while (current != target)
        {
            current = current->next;
            cout << " -> " << current->id;
        }

        cout << "\nSteps: " << nextSteps << endl;
    }
    else
    {
        cout << "Direction: PREV\n";
        cout << "Path: ";

        current = head;

        cout << current->id;

        while (current != target)
        {
            current = current->prev;
            cout << " -> " << current->id;
        }

        cout << "\nSteps: " << prevSteps << endl;
    }
}

// Delete entire list
void deleteList(Node*& head)
{
    while (head != nullptr)
    {
        Node* temp = head;

        if (head->next == head)
        {
            head = nullptr;
            delete temp;
        }
        else
        {
            head = head->next;
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            delete temp;
        }
    }
}

int main()
{
    Node* head = nullptr;

    int n;

    cout << "Enter number of coaches: ";
    cin >> n;

    cout << "Enter coach IDs:\n";

    for (int i = 0; i < n; i++)
    {
        int id;
        cin >> id;

        insertCoach(head, id);
    }

    int commands;

    cout << "Enter number of commands: ";
    cin >> commands;

    cout << "\n";

    for (int i = 0; i < commands; i++)
    {
        char command;
        int id;

        cout << "Enter command: ";
        cin >> command >> id;

        if (command == 'R')
        {
            moveRight(head, id);

            cout << "After R " << id << ": ";
            display(head);
        }
        else if (command == 'L')
        {
            moveLeft(head, id);

            cout << "After L " << id << ": ";
            display(head);
        }
        else if (command == 'D')
        {
            Node* node = searchCoach(head, id);

            if (node != nullptr)
            {
                detach(head, node);
            }
            else
            {
                cout << "Coach " << id << " not found.\n";
            }

            cout << "After D " << id << ": ";
            display(head);
        }
        else if (command == 'S')
        {
            Node* node = searchCoach(head, id);

            if (node != nullptr)
            {
                head = node;
            }
            else
            {
                cout << "Coach " << id << " not found.\n";
            }

            cout << "After S " << id << ": ";
            display(head);
        }
        else if (command == 'F')
        {
            cout << "\nF " << id << ":\n";

            findCoach(head, id);
        }
        else
        {
            cout << "Invalid command.\n";
        }

        cout << endl;
    }

    deleteList(head);

    return 0;
}
