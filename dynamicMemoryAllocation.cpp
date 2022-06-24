// code C++
// Dinamic Memory Allocaton example

#include <iostream>

using namespace std;

int main()
{
  int size;
  int *ptr;
  cout << "Enter number of values you want to store: " << endl;
  cin >> size;

  ptr = new int[size];

  cout << "Enter number of values to be stored in array: " << endl;
  for (int i = 0; i < size; i++)
  {
    cin >> ptr[i];
  }

  for (int i = 0; i < size; i++)
  {
    cout << ptr[i] << endl;
  }

  return 0;
}