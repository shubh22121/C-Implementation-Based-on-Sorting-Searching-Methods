#include<iostream>
using namespace std;
# define max 6
int queue[max];
int front=-1;
int rear=-1;
void enqueue(int ele)
{
    if(front==-1 && rear==-1)
    {
        front=0;
        rear=0;
        queue[rear]=ele;
    }
    else if((rear+1)%max==front){
            cout<<"Queue is overflow!!";
    }
    else
    {
        rear=(rear+1)%max;
        queue[rear]=ele;
    }
}
int dequeue()
{
    if((front==-1)&& (rear==-1))
    {

        cout<<"\n queue is underflow..";
    }
    else if(front==rear)
    {
      cout<<"the deueued element is:"<<queue[front];
      front--;
      rear--;

    }
    else{
        cout<<"the dequeued element is"<<queue[front];
        front=(front+1)%max;
    }

    return 0;
}
void display()
{
    if(front==-1 && rear==-1)
    {
        cout<<"\n queue is empty..";
    }
    else
    {
        for(int i=front;i<=rear;i++)
        {
            cout<<queue[i]<<" ";
        }
    }

}
int main()
{   
    int choice,ele;
    while(1)
    {
        cout<<"\n1.enqueue\n2.dequeue\n3.display\n4.exit\n";
        cin>>choice;
        switch(choice)
        {
            case 1:
                cout<<"enter the element to be enqueued:";
                cin>>ele;
                enqueue(ele);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                cout<<"-------------------"<<endl;
                display();
                cout<<"-------------------"<<endl;
                break;
            case 4:
                exit(0);
            default:
                cout<<"\n invalid choice";
        }
    }
    return 0;

}