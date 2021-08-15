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
    // Node *tail;
    int size;
    LinkedList()
    {
        size = 0;
        head = NULL;
        // tail = NULL;
    }
    // void push(int data)
    // {
    //     Node *n = new Node(data);
    //     if (size == 0)
    //     {
    //         head = n;
    //         tail = n;
    //     }
    //     else
    //     {
    //         tail->next = n;
    //         tail = tail->next;
    //     }
    //     size++;
    // }
    // int top()
    // {
    //     if (size == 0)
    //     {
    //         cout << "Empty" << endl;
    //         return -1;
    //     }
    //     else
    //     {
    //         return tail->data;
    //     }
    // }
    // void pop()
    // {
    //     if (size == 0)
    //     {
    //         cout << "Empty" << endl;
    //         return;
    //     }
    //     Node *temp = head;
    //     while (temp->next != tail)
    //     {
    //         temp = temp->next;
    //     }
    //     delete tail;
    //     temp->next = NULL;
    //     tail = temp;
    //     size--;
    // }
    // time complexity O(1)

    void push(int data)
    {
        Node *n = new Node(data);
        if (size == 0)
        {
            head = n;
        }
        else
        {
            n->next = head;
            head = n;
        }
        size++;
    }
    void pop()
    {
        if (size == 0)
        {
            cout << "Empty" << endl;
            return;
        }
        else
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
        size--;
    }
    int top()
    {
        if (size == 0)
        {
            cout << "Empty" << endl;
            return -1;
        }
        else
        {
            return head->data;
        }
    }
    int getSize()
    {
        return size;
    }
};

int main()
{
    LinkedList l;
    l.push(10);
    l.push(20);
    l.push(30);
    cout << l.top() << " " << l.getSize() << endl;
    l.pop();
    cout << l.top() << " " << l.getSize() << endl;
}