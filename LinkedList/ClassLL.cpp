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

    void addLast(int data)
    {
        Node *n = new Node(data);
        if (head == NULL)
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
    void print()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    void removeFirst()
    {
        if (size <= 1)
        {
            head = NULL;
            tail = NULL;
            size = 0;
        }
        else
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            size--;
        }
    }

    int getValue(int j)
    {
        if (size == 0)
        {
            cout << "List is empty" << endl;
            return -1;
        }
        if (size < j || j < 0)
        {
            cout << "Invalid argument" << endl;
            return -1;
        }
        Node *temp = head;
        for (int i = 0; i < j; i++)
        {
            temp = temp->next;
        }
        return temp->data;
    }
    int getfirst()
    {
        if (size == 0)
        {
            cout << "List is empty" << endl;
            return -1;
        }
        return head->data;
    }
    int getlast()
    {
        if (size == 0)
        {
            cout << "List is empty" << endl;
            return -1;
        }
        return tail->data;
    }
    void addfirst(int data)
    {
        Node *n = new Node(data);
        if (size == 0)
        {
            head = n;
            tail = n;
        }
        else
        {
            n->next = head;
            head = n;
        }
        size++;
    }

    void addAti(int data, int j)
    {
        Node *n = new Node(data);
        if (j < 0 || j > size)
        {
            cout << "Invalid Argument" << endl;
            return;
        }
        if (j == 0)
        {
            n->next = head;
            head = n;
        }
        else if (j == size)
        {
            tail->next = n;
            tail = n;
        }
        else
        {
            Node *temp = head;
            for (int i = 1; i < j; i++)
            {
                temp = temp->next;
            }
            n->next = temp->next;
            temp->next = n;
        }
        size++;
    }
    void removeLast()
    {
        if (size == 0)
        {
            cout << "List is empty" << endl;
            return;
        }
        if (size == 1)
        {
            delete head;
            head = NULL;
            tail = NULL;
        }
        else
        {
            Node *temp = head;
            while (temp->next != tail)
            {
                temp = temp->next;
            }
            delete tail;
            temp->next = NULL;
            tail = temp;
        }
        size--;
    }
    void reverse()
    {
        Node *curr = head;
        Node *prev = NULL;
        Node *Next = head->next;
        tail = head;
        while (curr != NULL)
        {
            curr->next = prev;
            prev = curr;
            curr = Next;
            if (Next != NULL)
            {
                Next = Next->next;
            }
        }
        head = prev;
    }
    void removeAt(int j)
    {
        if (size == 0)
        {
            cout << "List is empty" << endl;
            return;
        }
        if (j < 0 || j >= size)
        {
            cout << "Invalid Argument" << endl;
            return;
        }
        if (j == 0)
        {
            removeFirst();
        }
        else if (j == size - 1)
        {
            removeLast();
        }
        else
        {
            Node *temp = head;
            for (int i = 0; i < j - 1; i++)
            {
                temp = temp->next;
            }
            Node *temp2 = temp->next;
            temp->next = temp2->next;
            delete temp2;
        }
        size--;
    }
};

int main()
{
    LinkedList l;
    l.addLast(10);
    l.addLast(20);
    l.addLast(30);
    l.addLast(40);
    l.removeAt(2);
    l.print();
}