#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

class LinkedList
{
public:
    Node *head;
    Node *tail;
    int size;
    LinkedList()
    {
        head = NULL;
        tail = NULL;
        size = 0;
    }
    void add(int data)
    {
        Node *n = new Node(data);
        if (size == 0)
        {
            head = n;
            tail = n;
        }
        else
        {
            tail->next = n;
            tail = tail->next;
        }
        size++;
    }
    int getKlastNode(int k)
    {
        Node *fast = head;
        Node *slow = head;
        for (int i = 0; i < k; i++)
        {
            if (fast != NULL)
            {
                cout << "Invalid Argument" << endl;
                return -1;
            }
            fast = fast->next;
        }
        while (fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
        return slow->data;
    }
    int mid()
    {
        Node *slow = head;
        Node *fast = head;
        while (fast->next != NULL && fast->next->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow->data;
    }
};

Node *mergeSorted(Node *h1, Node *h2)
{
    Node *fh = NULL;
    Node *tail = NULL;
    while (h1 != NULL && h2 != NULL)
    {
        if (fh == NULL)
        {
            if (h1->data < h2->data)
            {
                fh = h1;
                tail = h1;
                h1 = h1->next;
            }
            else
            {
                fh = h2;
                tail = h2;
                h2 = h2->next;
            }
        }
        else
        {
            if (h1->data < h2->data)
            {
                tail->next = h1;
                tail = tail->next;
                h1 = h1->next;
            }
            else
            {
                tail->next = h2;
                tail = tail->next;
                h2 = h2->next;
            }
        }
    }
    if (h1 != NULL)
    {
        tail->next = h1;
    }
    if (h2 != NULL)
    {
        tail->next = h2;
    }
    return fh;
}

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    LinkedList l;
    l.add(10);
    l.add(20);
    l.add(30);
    LinkedList m;
    m.add(1);
    m.add(25);
    m.add(36);
    Node *head = mergeSorted(l.head, m.head);
    print(head);
}