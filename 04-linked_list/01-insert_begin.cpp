#include<iostream>
using namespace std;

struct Node
{
  int data;
  Node *next;
};



Node *Insert(int x, Node *head)
{
  Node *temp = new Node;
  temp->data = x;
  temp->next = NULL;
  if (head == NULL)
  {
    head = temp;
  }
  else
  {
    temp->next = head;
    head = temp;
  }
  return head;
}

void Print(Node *head)
{
  while (head != NULL)
  {
    cout << head->data << " ";
    head = head->next;
  }
  cout << endl;
}

int main()
{
  
  Node *head = NULL;
  int n;
  cout<<"enter the numer of nodes : ";
  cin >> n;
  int x;
  
  for (int i = 0; i < n; ++i)
  { cout<<"enter the elements : ";
    cin >> x;
    head = Insert(x, head);
    // Print(head);
  }
  cout<<"the final linked list is :";
  Print(head);
  return 0;
}