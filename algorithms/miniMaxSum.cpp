/*
Given five positive integers, find the minimum and maximum values that can be calculated
by summing exactly four of the five integers. Then print the respective minimum and
maximum values as a single line of two space-separated long integers.

Example
arr = [1,3,5,7,9]
The minimum sum is 1+3+5+7=16 and the maximum sum is 3+5+7+9 = 24. The function prints:
16 24
*/

#include <iostream>
#include <vector>
#include <algorithm> //for use of sort()

using namespace std;

void miniMaxSum(vector<long long> arr)
{
  long long min{0};
  long long max{0};
  sort(arr.begin(), arr.end()); // sort vector in crescent order
  for (int i = 0; i < arr.size() - 1; i++)
  {
    min = min + arr[i];
  }
  for (int i = 1; i < arr.size(); i++)
  {
    max = max + arr[i];
  }
  cout << min << " " << max;
}

int main()
{
  vector<long long> vect1{1, 3, 5, 7, 9}; // -> 16 24
  vector<long long> vect2{1, 2, 3, 4, 5}; // -> 10 14

  miniMaxSum(vect1);
  miniMaxSum(vect2);

  return 0;
}
