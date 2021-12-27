#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

class LinkedList
{   
    Node *head;
    Node *tail;
    int size;
public:
    LinkedList()
    {
        head = NULL;
        tail = NULL;
        size = 0;
    }
    void insert_begin(int x)
    {
        Node *temp = new Node;
        temp->data = x;
        temp->next = NULL;
        if (head == NULL)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            temp->next = head;
            head = temp;
        }
        size++;
    }
    void insert_end(int x)
    {
        Node *temp = new Node;
        temp->data = x;
        temp->next = NULL;
        if (head == NULL)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
        size++;
    }
    
    void insert(int x, int pos)
    {
        if (pos < 0 || pos > size)
        {
            cout << "Invalid Position" << endl;
            return;
        }
        if (pos == 0)
        {
            insert_begin(x);
            return;
        }
        if (pos == size)
        {
            insert_end(x);
            return;
        }
        Node *temp = new Node;
        temp->data = x;
        temp->next = NULL;
        Node *curr = head;
        for (int i = 0; i < pos - 1; i++)
        {
            curr = curr->next;
        }
        temp->next = curr->next;
        curr->next = temp;
        size++;
    }

    void delete_begin()
    {
        if (head == NULL)
        {
            cout << "List is Empty" << endl;
            return;
        }
        Node *temp = head;
        head = head->next;
        delete temp;
        size--;
    }


    void delete_end()
    {
        if (head == NULL)
        {
            cout << "List is Empty" << endl;
            return;
        }
        Node *curr = head;
        Node *prev = NULL;
        while (curr->next != NULL)
        {
            prev = curr;
            curr = curr->next;
        }
        tail = prev;
        prev->next = NULL;
        delete curr;
        size--;
    }

    void delete_pos(int pos)
    {
        if (head == NULL)
        {
            cout << "List is Empty" << endl;
            return;
        }
        if (pos < 0 || pos > size)
        {
            cout << "Invalid Position" << endl;
            return;
        }
        if (pos == 0)
        {
            delete_begin();
            return;
        }
        if (pos == size)
        {
            delete_end();
            return;
        }
        Node *curr = head;
        Node *prev = NULL;
        for (int i = 0; i < pos; i++)
        {
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        delete curr;
        size--;
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
};



int main()
{
    LinkedList l;
    l.insert(10, 0);
    l.insert(20, 1);
    l.insert(30, 2);
    l.insert(40, 3);
    l.insert_begin(50);
    l.insert_end(60);
    l.delete_begin();
    l.delete_end();
    l.delete_pos(2);
    l.print();
    return 0;
}