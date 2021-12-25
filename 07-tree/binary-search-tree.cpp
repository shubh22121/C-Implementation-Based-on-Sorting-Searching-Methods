#include <iostream>
using namespace std;

#include <iomanip>
#include <string.h>
struct Bstnode
{
    struct Bstnode *lc;
    int data;
    struct Bstnode *rc;
};
class BST
{
private:
    Bstnode *root;

public:
    BST(void)
    {
        root = NULL;
    }
    void create_BST(void);
    void inorder(Bstnode *temp);
    void traverse()
    {
        cout << "\ninorder :";
        inorder(root);
    }
};
void BST::inorder(Bstnode *temp)
{
    if (temp != NULL)
    {
        inorder(temp->lc);
        cout << temp->data;
        inorder(temp->rc);
    }
}
void BST ::create_BST(void)
{
    Bstnode *newp = NULL, *par = NULL, *temp = NULL;
    int n;
    cout << " How many Values to be inseted in BST:";
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cout << " Enter node data value:";
        newp = new Bstnode;
        cin >> newp->data;
        newp->lc = newp->rc = NULL;
        if (i == 1)
            root = newp;
        else
        {
            par = NULL;
            temp = root;
            while (temp != NULL)
            {
                par = temp;
                if (newp->data < temp->data)
                    temp = temp->lc;
                else
                    temp = temp->rc;
            }
            if (newp->data > par->data)
                par->rc = newp;
            else
                par->lc = newp;
        }
    }
}
int main()
{
    BST T;
    T.create_BST();
    T.traverse();
    return 0;
}