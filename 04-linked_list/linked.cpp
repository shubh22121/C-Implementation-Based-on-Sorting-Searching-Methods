// Singly linked list of integers creation and display
#include <iostream>
using namespace std;
struct Sllnode
{
    int data;             // field/ member to store integer in each node
    struct Sllnode *next; // self referential pointer. to point similar structure i.e. next node
};
class SLL
{
private:
    Sllnode *first; // class data member to hold address of first node of SLL
public:
    SLL(void) // default constructor, constructor is automatically called upon object creation
    {
        first = NULL;
    }
    void create_sll(void);  // member function/method declaration to create SLL
    void display_sll(void); // member function/method declaration to display SLL
};                          // class declaration ends
// function definition
void SLL ::create_sll(void)
{
    int n, i;
    Sllnode *last = NULL, *newp = NULL;
    cout << " How many data items in the list:";
    cin >> n;
    for (i = 1; i <= n; i++) // for creating n nodes
    {                        // create a node and fill data
        newp = new Sllnode;
        cout << "Enter data :";
        cin >> newp->data;
        newp->next = NULL;
        if (i == 1) // means it is first Sllnode
        {
            first = newp; // copy first node address in pointer first
            last = newp;  // last pointer points to last node in SLL which is first node now
        }
        else
        {                      // if the node is not a first node then connect at the end of list i.e to node pointed by last pointer
            last->next = newp; // connect new node at the end of list
            last = newp;       // get address of latest i.e last node in pointer last
        }
    }
}
void SLL ::display_sll(void)
{
    Sllnode *temp;
    temp = first; // copy address of fiest node in tempm i.e temp pointing to first node
    while (temp != NULL)
    {
        cout << temp->data << "-->"; // print data field of node pointed by temp
        temp = temp->next;           // advance pointer temp to next node
    }
    cout << "NULL"; // print NULL at the end of output
}
int main(void)
{
    SLL L;           // object L declared
    L.create_sll();  // call to function create_sll
    L.display_sll(); // call to function display_sll
    return 0;
}