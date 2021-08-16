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
        size = 0;
        head = NULL;
        tail = NULL;
    }
    int getSize()
    {
        return size;
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
    void remove()
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        size--;
    }
    int peek()
    {
        if (size == 0)
        {
            cout << "Empty" << endl;
            return -1;
        }
        return head->data;
    }
};

int main()
{
    LinkedList l;
}