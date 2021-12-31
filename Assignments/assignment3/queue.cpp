#include <iostream>
using namespace std;
#define max 101

class Queue // class declaration
{
    int queue[max];
    int front, rear;

public:
    Queue() // constructor to initialize the queue
    {
        front = -1;
        rear = -1;
    }

    bool isEmpty() // returns true if queue is empty
    {
        if (front == -1 && rear == -1)
            return true;
        else
            return false;
    }

    bool isFull() // returns true if queue if full
    {
        if ((rear + 1) % max == front)
            return true;
        else
            return false;
    }

    void enqueue(int x) // inserts an element at rear
    {
        if (isFull())
        {
            cout << "Queue is overflow!!";
        }
        else
        {
            if (isEmpty())
            {
                front = 0;
                rear = 0;
                queue[rear] = x;
            }
            else
            {
                rear = (rear + 1) % max;
                queue[rear] = x;
            }
        }
    }

    int dequeue() // deletes an element from front
    {
        if (isEmpty())
        {
            cout << "\n queue is underflow..";
            return -1;
        }
        else
        {
            if (front == rear)
            {
                cout << "the dequeued element is:" << queue[front];
                front--;
                rear--;
            }
            else
            {
                cout << "the dequeued element is" << queue[front];
                front = (front + 1) % max;
            }
        }

        return 0;
    }

    void display() // displays the queue
    {
        if (isEmpty())
        {
            cout << "\n queue is empty..";
        }
        else
        {
            for (int i = front; i <= rear; i++)
            {
                cout << queue[i] << " ";
            }
        }
    }
};

int main()
{
    Queue q;

    int choice, ele;
    while (1)
    {
        cout << "\n1.enqueue\n2.dequeue\n3.display\n4.exit\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "enter the element to be enqueued:";
            cin >> ele;
            q.enqueue(ele);
            break;
        case 2:
            q.dequeue();
            break;
        case 3:
            cout << "-------------------" << endl;
            q.display();
            cout << "\n-------------------" << endl;
            break;
        case 4:
            exit(0);
        default:
            cout << "\n invalid choice";
        }
    }
}