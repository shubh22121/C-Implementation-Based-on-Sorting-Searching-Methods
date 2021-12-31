// Consider a student databas eof SEITclass(atleast15records).
// DatabasecontainsdifferentfieldsofeverystudentlikeRollNo,NameandSGPA.(arrayofstructure)
// b)Arrangelistofstudentsalphabetically.(UseInsertionsort)
// c)Arrangelistofstudentstofindoutfirsttentoppersfromaclass.(UseQuicksort)

#include <iostream>
#include <cstdio>
#include <iomanip>
#include <string.h>
using namespace std;

struct student
{
    unsigned int roll_no;
    char name[50];
    float sgpa;
};

class Student
{
private:
    student a[20];
    int size;
    
public:
    int get_size()
    {
        return size;
    }
    
    // This is create method
    void create()
    {
        
        cout << "Enter the size of Array :";
        cin >> size; // Takes the size and input
        for (int i = 0; i < size; i++)
        {
            cout << "Enter the Roll No. ";
            cin >> a[i].roll_no;
            cout << "Enter the Name :";
            cin >> a[i].name;
            cout << "Enter SGPA :";
            cin >> a[i].sgpa;
        }
    }
    
    // This is bubble_sort to sort according to roll_no
    void bubble_sort()
    {
        for (int i = 0; (i < size); i++)
        {
            for (int j = 0; j < size - 1; j++)
            {
                if (a[j].roll_no < a[i].roll_no)
                {
                    student temp = a[i];
                    a[i] = a[j];
                    a[j] = temp;
                }
            }
        }
        
        cout << "Roll No." << setw(15) << "Name" << setw(25) << "SGPA" << endl;
        
    }

    // This is insertion_sort to arrange the list of students alphabetically

    void insertion_sort()
    {
        for (int i = 1; i < size; i++)
        {
            student key = a[i];
            int j = i - 1;
            while (j >= 0 && strcmp(a[j].name, key.name) > 0)
            {
                a[j + 1] = a[j];
                j = j - 1;
            }
            a[j + 1] = key;
        }
        
        cout << "Roll No." << setw(15) << "Name" << setw(25) << "SGPA" << endl;
        
        for (int i = 0; i < size; i++)
        {
            
            cout << a[i].roll_no << setw(25) << a[i].name << setw(30) << a[i].sgpa << endl;
        }
    }


    // this is quicksort to arrange list of student to find out first ten toppers

    void quiksort(int low, int high)
    {
        int i = low, j = high;
        student pivot = a[(low + high) / 2];
        while (i <= j)
        {
            while (a[i].sgpa < pivot.sgpa)
                i++;
            while (a[j].sgpa > pivot.sgpa)
                j--;
            if (i <= j)
            {
                student temp = a[i];
                a[i] = a[j];
                a[j] = temp;
                i++;
                j--;
            }
        }
        if (low < j)
            quiksort(low, j);
        if (i < high)
            quiksort(i, high);
    }
};


int main()
{
    Student s;
    int ch;


    cout<<"1.Create\n2.Bubble Sort\n3.Insertion Sort\n4.Quicksort\n";

    do
    {
        
        cout<<"Enter your choice :";
        cin>>ch;
        switch(ch)
        {
            case 1:
                s.create();
                break;
            case 2:
                s.bubble_sort();
                break;
            case 3:
                s.insertion_sort();
                break;
            case 4:
                s.quiksort(0, s.get_size()-1);
                break;
            default:
                cout<<"Invalid choice";
        }
        cout<<"Do you want to continue(1/0) :";
        cin>>ch;}

        while(ch==1);
    return 0;


}