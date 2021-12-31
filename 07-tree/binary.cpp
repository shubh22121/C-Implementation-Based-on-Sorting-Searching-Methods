#include <iostream>
using namespace std;
struct ITBSTnode
{
    int data;
    int lt, rt;
    ITBSTnode *lc, *rc;
};
class ITBST
{
private:
    ITBSTnode *temp, *newp, *root, *par, *dummy;

public:
    ITBST()
    {
        root = NULL;
    }
    void ITBST_create();
    void ITBST_insert(ITBSTnode *, ITBSTnode *);
    void ITBST_display();
    void inorder_ITBST(ITBSTnode *, ITBSTnode *);
    void preorder_ITBST(ITBSTnode *, ITBSTnode *);
};
void ITBST ::ITBST_create()
{
    newp = new ITBSTnode;
    newp->lc = newp->rc = NULL;
    newp->lt = newp->rt = 0;
    cout << "Enter the value : ";
    cin >> newp->data;

    if (root == NULL)
    {
        root = newp;
        dummy = new ITBSTnode;
        dummy->data = -999;
        dummy->lc = root;
        root->lc = dummy;
        root->rc = dummy;
    }
    else
    {
        ITBST_insert(root, newp);
    }
}
void ITBST ::ITBST_insert(ITBSTnode *root, ITBSTnode *newp)
{
    if (newp->data < root->data)
    {
        if (root->lt == 0)
        {
            newp->lc = root->lc;
            newp->rc = root;
            root->lc = newp;
            root->lt = 1;
        }
        else
        {
            ITBST_insert(root->lc, newp);
        }
    }

    if (newp->data > root->data)
    {
        if (root->rt == 0)
        {
            newp->rc = root->rc;
            newp->lc = root;
            root->rt = 1;
            root->rc = newp;
        }
        else
        {
            ITBST_insert(root->rc, newp);
        }
    }
}
void ITBST ::inorder_ITBST(ITBSTnode *temp, ITBSTnode *dummy)
{
    while (temp != dummy)
    {
        while (temp->lt == 1)
        {
            temp = temp->lc;
        }
        cout << " " << temp->data;
        while (temp->rt == 0)
        {
            temp = temp->rc;
            if (temp == dummy)
                return;
            cout << " " << temp->data;
        }
        temp = temp->rc;
    }
}
void ITBST ::preorder_ITBST(ITBSTnode *temp, ITBSTnode *dummy)
{
    int flag = 0;
    while (temp != dummy)
    {
        if (flag == 0)
        {
            cout << " " << temp->data;
        }
        if ((temp->lt == 1) && (flag == 0))
        {
            temp = temp->lc;
        }
        else
        {
            while (1)
            {
                if (temp->rt == 1)
                {
                    flag = 0;
                    temp = temp->rc;
                    break;
                }
                else
                {
                    if (temp != dummy)
                    {
                        flag = 1;
                        temp = temp->rc;
                        break;
                    }
                }
            }
        }
    }
}
void ITBST ::ITBST_display()
{
    void inorder_ITBST(ITBSTnode * root, ITBSTnode * dummy);
    void preorder_ITBST(ITBSTnode * root, ITBSTnode * dummy);
    ITBST it;

    if (root == NULL)
    {
        cout << "Inorder threaded Binar search tree has not been created." << endl;
    }
    else
    {
        cout << "Inorder Traversal of ITBST - " << endl;
        it.inorder_ITBST(root, dummy);
        cout << "\nPreorder Traversal of ITBST - " << endl;
        it.preorder_ITBST(root, dummy);
    }
}
int main()
{
    int ch;
    ITBST it;
    char ans = 'n';

    do
    {
        cout << "**Inorder Threaded Binary Search Tree**" << endl;
        cout << "1.Create ITBST" << endl;
        cout << "2.Display ITBST with Inorder and Preorder Traversals" << endl;
        cin >> ch;

        switch (ch)
        {
        case 1:
            do
            {
                it.ITBST_create();
                cout << "Do you want to enter more elments(y/n)" << endl;
                cin >> ans;
            } while (ans == 'y');
            break;

        case 2:
            it.ITBST_display();
            break;
        }
        cout << "\nWant to go back to Main Menu(y/n)" << endl;
        cin >> ans;
    } while (ans == 'y');

    return 0;
}