// Construct an Expression Tree from postfix and prefix expression. Perform recursive and nonrecursive In-order, pre-order and post-order traversals.

#include <iostream>
using namespace std;
class Node
{
public:
    char data;
    Node *left, *right;
};
class Tree
{
public:
    Node *root;
    Tree()
    {
        root = NULL;
    }
    void inorder_recursive(Node *);
    void preorder_recursive(Node *);
    void postorder_recursive(Node *);
    void inorder_nonrecursive(Node *);
    void preorder_nonrecursive(Node *);
    void postorder_nonrecursive(Node *);
    Node *expression();
};
Node *Tree::expression()
{
    Node *temp;
    int i, top = -1;
    char exp[20];
    Node *stack[10];
    int flag[10];
    cout << "Enter the expression:";
    cin >> exp;
    for (i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] >= 'a' && exp[i] <= 'z')
        {
            temp = new Node;
            temp->data = exp[i];
            temp->left = temp->right = NULL;
            stack[++top] = temp;
        }
        else
        {
            root = new Node;
            root->data = exp[i];
            root->left = root->right = NULL; // root creation for operator
            root->right = stack[top--];
            root->left = stack[top--];
            stack[++top] = root;
        }
    }
    root = stack[top--];
    return root;
}
void Tree::inorder_recursive(Node *root)
{
    if (root != NULL)
    {
        inorder_recursive(root->left);
        cout << root->data;
        inorder_recursive(root->right);
    }
}
void Tree::preorder_recursive(Node *root)
{
    if (root != NULL)
    {
        cout << root->data;
        preorder_recursive(root->left);
        preorder_recursive(root->right);
    }
}
void Tree::postorder_recursive(Node *root)
{
    if (root != NULL)
    {
        postorder_recursive(root->left);
        postorder_recursive(root->right);
        cout << root->data;
    }
}
void Tree::inorder_nonrecursive(Node *root)
{
    struct Node *stack[20];
    int top = -1;
    while (root != NULL || top != -1)
    {
        if (root != NULL)
        {
            stack[++top] = root;
            root = root->left;
        }
        else
        {
            root = stack[top--];
            cout << root->data;
            root = root->right;
        }
    }
}
void Tree::preorder_nonrecursive(Node *root)
{
    struct Node *stack[20];
    int top = -1;
    stack[++top] = root;
    while (top != -1)
    {
        root = stack[top--];
        if (root != NULL)
        {
            cout << root->data;
            stack[++top] = root->right;
            stack[++top] = root->left;
        }
    }
}
void Tree::postorder_nonrecursive(Node *root)
{
    struct Node *stack[20];
    int top = -1;
    int flag[10];
    while (top != -1 || root != NULL)
    {
        if (root != NULL)
        {
            stack[++top] = root;
            flag[top] = 0;
            root = root->left;
        }
        else
        {
            root = stack[top];
            if (flag[top] == 1)
            {
                cout << root->data;
                top--;
                root = NULL;
            }
            else
            {
                flag[top] = 1;
                root = root->right;
            }
        }
    }
}
int main()
{
    Tree s;
    s.root = s.expression();
    int ch, ans;
    cout << "\n*****MENU*****";
    cout << "\n1.Recursive function for inorder";
    cout << "\n2.Recursive function for preorder";
    cout << "\n3.Recursive function for postorder";
    cout << "\n4.Non-recursive function for inorder";
    cout << "\n5.Non-recursive function for preorder";
    cout << "\n6.Non-recursive function forpostorder";
    do
    {
        cout << "\nENTER YOUR CHOICE:";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "\n Inorder Exp with Recursive =>";
            s.inorder_recursive(s.root);
            break;
        case 2:
            cout << "\n preorder Exp with Recursive =>";
            s.preorder_recursive(s.root);
            break;
        case 3:
            cout << "\n postorder Exp with Recursive =>";
            s.postorder_recursive(s.root);
            break;
        case 4:
            cout << "\n Inorder Exp with Non_Recursive =>";
            s.inorder_nonrecursive(s.root);
            break;
        case 5:
            cout << "\n preorder Exp with Non_Recursive =>";
            s.preorder_nonrecursive(s.root);
            break;
        case 6:
            cout << "\n postorder Exp with Non_Recursive =>";
            s.postorder_nonrecursive(s.root);
            break;
        }
        cout << "\n do you want to continue(1/0)";
        cin >> ans;
    } while (ans == 1);
    return 0;
}