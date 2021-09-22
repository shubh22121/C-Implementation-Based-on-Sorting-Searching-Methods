#include<iostream>
using namespace std;


class linked_list{
	private:
	int data;
	int *addr;
	public:
	linked_list(){
		cout << "Enter the data" << endl;
		cin >> data;
		addr = NULL;
	}
};

int main(int argc, char const *argv[])
{
    linked_list s;
    s.linked_list();
    return 0;
}
