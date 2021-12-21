#include <iostream>
using namespace std;

int linear(int arr[], int n, int x)
{
	
	for (int i = 0; i < n; i++){
		if (arr[i] == x)
			return i;

	}
	return -1;
}


int main()
{
	int arr[] = { 2, 3, 4, 10, 40 };
	int x = 4;
	int n = sizeof(arr) / sizeof(arr[0]);

	int result = linear(arr, n, x);
	cout<<"x is present at :" <<result;
	return 0;
}
