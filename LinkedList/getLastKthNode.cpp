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
};

int main()
{
    LinkedList l;
    l.add(10);
    l.add(20);
    l.add(30);
    l.add(40);
    cout << l.getKlastNode(4) << endl;
}