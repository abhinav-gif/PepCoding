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
            //cout << "List is empty" << endl;
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
    void kReverse(int k)
    {
        if (k > size)
        {
            return;
        }

        LinkedList final;
        Node *temp = head;
        while (k < size)
        {
            LinkedList curr;
            for (int i = 0; i < k; i++)
            {
                curr.addfirst(temp->data);
                temp = temp->next;
                removeFirst();
            }
            if (final.head == NULL)
            {
                final.head = curr.head;
                final.tail = curr.tail;
                final.size = curr.size;
            }
            else
            {
                final.tail->next = curr.head;
                final.tail = curr.tail;
                final.size = final.size + curr.size;
            }
        }
        if (size > 0)
        {
            final.tail->next = temp;
            final.tail = temp;
            final.size += this->size;
        }
        this->head = final.head;
        this->tail = final.tail;
        this->size = final.size;
    }
    void displayReverse()
    {
        displayReverseHelper(head);
        cout << endl;
    }

    void reverse()
    {
        tail = head;
        head = reverseHelper(head);
    }
    void reverseData()
    {
        left = head;
        reverseDataHelper(head, 0);
    }

    void isPalindrome()
    {
        left = head;
        if (isPalindromeHelper(head))
        {
            cout << "True" << endl;
        }
        else
        {
            cout << "False" << endl;
        }
    }

    void fold()
    {
        left = head;
        foldHelper(head, 0);
    }

private:
    void displayReverseHelper(Node *head)
    {
        if (head == NULL)
        {
            return;
        }
        displayReverseHelper(head->next);
        cout << head->data << " ";
    }
    Node *reverseHelper(Node *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }
        Node *sh = reverseHelper(head->next);
        head->next->next = head;
        head->next = NULL;
        return sh;
    }
    Node *left;
    Node *reverseDataHelper(Node *head, int count)
    {
        if (head == NULL)
        {
            return head;
        }
        reverseDataHelper(head->next, count + 1);
        if (count <= size / 2)
        {
            swap(head->data, left->data);
        }
        left = left->next;
    }
    bool isPalindromeHelper(Node *head)
    {
        if (head == NULL)
        {
            return true;
        }
        bool so = isPalindromeHelper(head->next);
        if (head->data != left->data)
        {
            left = left->next;
            return false;
        }
        else
        {
            left = left->next;
            return so;
        }
    }
    void foldHelper(Node *head, int count)
    {
        if (head == NULL)
        {
            return;
        }
        foldHelper(head->next, count + 1);
        if (count > size / 2)
        {
            Node *temp = left->next;
            left->next = head;
            head->next = temp;
            left = temp;
        }
        else if (count == size / 2)
        {
            head->next = NULL;
            tail = head;
        }
    }
};

int main()
{
    LinkedList l;
    l.addLast(1);
    l.addLast(2);
    l.addLast(3);
    l.addLast(4);
    l.addLast(5);
    l.addLast(6);
    l.addLast(7);
    l.fold();
    l.print();
}