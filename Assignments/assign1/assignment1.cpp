// Consider a student database of SEIT class (at least 15 records). Database contains different fields of
// every student like Roll No, Name and SGPA.(array of structure)
// a) Design a roll call list, arrange list of students according to roll numbers in ascending order (Use
// Bubble Sort)
// b) Arrange list of students alphabetically. (Use Insertion sort)
// c) Arrange list of students to find out first ten toppers from a class. (Use Quick sort)
// d) Search students according to SGPA. If more than one student having same SGPA, then print list
// of all students having same SGPA.
// e) Search a particular student according to name using binary search without recursion. (all the student records having the presence of search key should be displayed)


#include <iostream>
#include <iomanip>
using namespace std;

struct student
{
    int roll_no;
    char name[20];
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
            
            while (j >= 0 && a[j].roll_no > key.roll_no)
            {
                a[j + 1] = a[j];
                j = j - 1;
            }
            a[j + 1] = key;
        }
        
        cout << "Roll No." << setw(15) << "Name" << setw(25) << "SGPA" << endl;
        
    }
    
    // This is quick_sort to Arrange list of students to find out first ten toppers from a class.  
    void quick_sort()
    {
        int low = 0;
        int high = size - 1;
        int i = low;
        int j = high;
        int pivot = a[low + (high - low) / 2].roll_no;
        
        while (i <= j)
        {
            while (a[i].roll_no < pivot)
            {
                i++;
            }
            
            while (a[j].roll_no > pivot)
            {
                j--;
            }
            
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
        {
            quick_sort(low, j);
        }
        
        if (i < high)
        {
            quick_sort(i, high);
        }
        
        cout << "Roll No." << setw(15) << "Name" << setw(25) << "SGPA" << endl;
        
        for (int i = 0; i < size; i++)
        {
            cout << a[i].roll_no << setw(25) << a[i].name << setw(30) << a[i].sgpa << endl;
        }
    }

    // This is binary_search to search a particular student according to name using binary search without recursion.

    void binary_search()
    {
        int low = 0;
        int high = size - 1;
        int mid;
        int i = 0;
        int flag = 0;
        char name[20];
        cout << "Enter the name of student :";
        cin >> name;
        
        while (low <= high)
        {
            mid = (low + high) / 2;
            if (strcmp(a[mid].name, name) == 0)
            {
                flag = 1;
                break;
            }
            else if (strcmp(a[mid].name, name) < 0)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        
        if (flag == 1)
        {
            cout << "Roll No." << setw(15) << "Name" << setw(25) << "SGPA" << endl;
            cout << a[mid].roll_no << setw(25) << a[mid].name << setw(30) << a[mid].sgpa << endl;
        }
        else
        {
            cout << "Student not found" << endl;
        }
    }
};


int main()
{
    Student s;

    char ch;
    do
    {
        cout << "1. Create\n2. Bubble Sort\n3. Insertion Sort\n4. Quick Sort\n5. Binary Search\n6. Exit\n";
        cout << "Enter your choice :";
        cin >> ch;
        switch (ch)
        {
            case '1':
                s.create();
                break;
            case '2':
                s.bubble_sort();
                break;
            case '3':
                s.insertion_sort();
                break;
            case '4':
                s.quick_sort();
                break;
            case '5':
                s.binary_search();
                break;
            case '6':
                break;
            default:
                cout << "Invalid choice" << endl;
        }
    } while (ch != '6');


    return 0;
}
