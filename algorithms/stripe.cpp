/* This problem was asked by Stripe via dailycodingproblem.com in 2022-06-18.
Given an array of integers, find the first missing positive integer in linear time
and constant space. In other words, find the lowest positive integer that does not
exist in the array. The array can contain duplicates and negative numbers as well.
For example, the input [3, 4, -1, 1] should give 2. The input [1, 2, 0] should give 3.
You can modify the input array in-place.
*/

#include <iostream>
#include <vector>
#include <cstdlib>   //for use of rand()
#include <ctime>     //for use of time()
#include <algorithm> //for use of sort()

using namespace std;

vector<int> randomArrayGenerator()
{
  // create an array of 'n' random elements
  srand(time(0));
  int numElem = (rand() % 10);
  vector<int> arrayTemp;
  for (int i = 0; i < numElem; i++)
  {
    arrayTemp.push_back((rand() % 19 + (-9))); // add random element (between -9 and 9) to vector
  }

  // show elements recently created
  cout << "Num of elements: [" << arrayTemp.size() << "] : { ";
  for (int element : arrayTemp)
  {
    cout << element << " ";
  }
  cout << "}";

  return arrayTemp;
}

int findNextLowestInteger(vector<int> a)
{
  // The main idea is increase a variable 'result' +1 every time a equal value is found in vector.
  // Once we are looking for the 1st POSITIVE integer not included in the array, we start the
  // variable 'result' in 1.
  int result = 1;
  sort(a.begin(), a.end()); // sort vector in crescent order
  for (int element : a)     // iterates over array
  {
    if (result == element)
    {
      result++;
    }
  }
  return result;
}

int main()
{
  vector<int> array1 = {3, 4, -1, 1};
  vector<int> array2 = {1, 2, 0};
  vector<int> array3 = {9, 2, 8, -6, 5, 1, 3, 2};

  cout << "Result: " << findNextLowestInteger(array1) << endl;
  cout << "Result: " << findNextLowestInteger(array2) << endl;
  cout << "Result: " << findNextLowestInteger(array3) << endl;

  cout << endl
       << "Result: " << findNextLowestInteger(randomArrayGenerator()) << endl;
  return 0;
}