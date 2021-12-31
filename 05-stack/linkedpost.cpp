#include <iostream>
#include <string.h>
#include <stdlib.h>
#define max 30
using namespace std;

struct node
{
    char data;
    struct node *next;
};

class stack
{   
    public:
    node *top;
    char x;

    public:
    stack()
    {
        top = NULL;
    }
    int empty()
    {
        if (top == NULL)
        {
            return (1);
        }
        else
        {
            return (0);
        }
    }

    void push(char x)
    {
        node *p;
        p = new node;
        p->data = x;
        p->next = top;
        top = p;
    }

    char pop()
    {
        if (!empty())
        {
            node *p;
            p = new node;
            p = top;
            top = top->next;
            x = p->data;
            delete p;
            return (x);
        }
        else
        {
            cout << "stack is empty" << endl;
            return (0);
        }
    }

    

};

int priority ( char alpha )
{
    if(alpha == '+' || alpha =='-')
    {
        return(1);
    }

    if(alpha == '*' || alpha =='/')
    {
        return(2);
    }

    if(alpha == '$')
    {
        return(3);
    }

    return 0;
}

void convert(string infix)
{
    int i=0;
    string postfix = "";   
    stack s;
    while(infix[i]!='\0')
    {
        if(infix[i]>='a' && infix[i]<='z')
        {
            postfix+=infix[i];
        }
        else if(infix[i]=='(')
        {
            s.push(infix[i]);
        }
        else if(infix[i]==')')
        {
            while(s.top->data!='(')
            {
                postfix+=s.pop();
            }
            s.pop();
        }
        else
        {
            while(!s.empty() && priority(infix[i])<=priority(s.top->data))
            {
                postfix+=s.pop();
            }
            s.push(infix[i]);
        }
        i++;
    }
    while(!s.empty())
    {
        postfix+=s.pop();
    }
    cout<<postfix;
}


int main()
{
    string infix;
    cout<<"Enter infix expression: ";
    cin>>infix;
    convert(infix);
    return 0;
}