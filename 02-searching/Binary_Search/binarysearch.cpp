#include <iostream>
using namespace std;

int binarySearch(int arr[], int left, int right, int x)
{
  while (left <= right)
  {
    int mid = left + (right - left) / 2;

    if (arr[mid] == x)
    {
      return mid;
    }
    else if (arr[mid] > x)
    {
      right = mid - 1;
    }
    else
    {
      left = mid + 1;
    }
  }

  return -1;
}

int main()
{
  int arr[] = {2, 3, 4, 10, 40};
  int x = 2;
  int n = sizeof(arr) / sizeof(arr[0]);
  int result = binarySearch(arr, 0, n - 1, x);

  if (result == -1)
  {
    cout << "Element is not present in array";
  }
  else
  {
    cout << "Element is present at index " << result << endl;
  }

  return 0;
}