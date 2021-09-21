#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <string.h>
using namespace std;
struct data
{
    unsigned int rollno; 
    char name[50];
    float sgpa;
};

class student
{
private:
struct data a[20]; 
int n; 

public:
void accept();
void bubble();
void insertion();
void search();
void binary();
void display();

};

void student::accept(){
        cout << "Enter the size of Array :";
        cin >> n;
        for (int i=0;i<n;i++){
        cout << "Enter the Roll No. ";
        cin >> a[i].rollno;
        cout << "Enter the Name :";
        cin >> a[i].name;
        cout << "Enter SGPA :";
        cin >> a[i].sgpa;
        }
}


void student::display()
{
cout << "Roll No." << setw(25) << "Name" << setw(30) << "SGPA"<< endl;
for (int i=0;i<n;i++)
        {
            cout << a[i].rollno << setw(30) << a[i].name << setw(30) << a[i].sgpa <<endl;
        }
}

void student::bubble(){
    struct data temp;
    for (int i = 1; i <= n - 1; i++) 
    {
        for (int j = 0; j < (n - 1); j++)
        {
            if (a[j].rollno > a[j+1].rollno) 
            {
                temp.rollno = a[j].rollno;
                strcpy(temp.name, a[j].name);
                temp.sgpa = a[j].sgpa;
                a[j].rollno = a[j + 1].rollno;
                strcpy(a[j].name, a[j + 1].name);
                a[j].sgpa = a[j + 1].sgpa;
                a[j + 1].rollno = temp.rollno;
                strcpy(a[j + 1].name, temp.name);
                a[j + 1].sgpa = temp.sgpa;
            }
        }
    }


}

void student::insertion(){
    int k,j;
    struct data temp;
    for(k=1;k<n;k++){
        temp=a[k];
        j=k-1;

        while (strcmp(a[j].name,temp.name)>0 && j>=0)
        {
            a[j+1] = a[j];
            --j;
        }
        a[j+1]=temp;
        
    }
}

void student::search(){
    
    float sgpa;
    int i;
    cout<<"\nenter sgpa to be searched: ";
    cin>>sgpa;

    cout << "Roll No." << setw(25) << "Name" << setw(30) << "SGPA"<< endl;
    for (i = 0; i < n; i++)
    {
        if (sgpa==a[i].sgpa)
        {
            cout << a[i].rollno << setw(30) << a[i].name << setw(30) << a[i].sgpa <<endl;
        }
        
    }
    
}


void student::binary(){
    int k, l, r, mid;
    char search[80];
    cout<<"\n enter the name of the student u want to search :";
    cin>>search;

    l=0;
    r=n-1;
    mid = (l+r)/2;

    while (l<=r)
    {
        if (strcmp(a[mid].name,search)<0)
        l=mid+1;
        else if(strcmp(a[mid].name,search)==0){
            cout << a[mid].rollno << setw(30) << a[mid].name << setw(30) << a[mid].sgpa <<endl;
            break;
        }else
        r=mid-1;

        
    }if (l>r)
    {
        cout<<search<<"not found in the list";
    }
}

int main()
{
    int ch, i;
    cout << "\n 1: Arrange list according to roll no.(bubble sort)";
    cout << "\n 2: Arrange list of students alphabetically. (Use Insertion sort)";
    cout << "\n 3: Search students according to SGPA. If more than one student having same SGPA, then print list";
    cout << "\n 4: Search a particular student according to name using binary)\n";
    cout << "\n enter your choice : ";
    cin >> ch;

student s;

switch(ch)
    {case 1:
    s.accept();
    s.bubble();
    s.display();
    break;
    
    case 2:
    s.accept();
    s.insertion();
    s.display();
    break;

    case 3:
    s.accept();
    s.search();
    break;


    case 4:
    s.accept();
    s.binary();
    break;


default:
        cout << "invalid choice...";

}
return 0;
}