/*
 * In this challenge, you are required to calculate and print the sum of the elements in
 * an array, keeping in mind that some of those integers may be quite large.
 *
 * Function Description
 * Complete the aVeryBigSum function in the editor below. It must return the sum of all
 * array elements.
 *
 * aVeryBigSum has the following parameter(s):
 * int ar[n]: an array of integers.
 *
 * Return
 * long: the sum of all array elements
 *
 * Input Format
 * The first line of the input consists of an integer .
 * The next line contains  space-separated integers contained in the array.
 *
 * Output Format
 * Return the integer sum of the elements in the array.
 *
 */

#include <iostream>
#include <vector>

using namespace std;

// we are using 'long long int' because for Windows OS there's no difference between
// long and int. so we need to extend a little bit more the range.
long long int aVeryBigSum(vector<long long int> ar)
{
  long long int x{0};
  for (long long int elem : ar)
  {
    x = x + elem;
  }
  return x;
}

int main()
{
  vector<long long int> vect1{1000000001, 1000000002, 1000000003, 1000000004, 1000000005}; // -> 5000000015

  cout << aVeryBigSum(vect1);

  return 0;
}
