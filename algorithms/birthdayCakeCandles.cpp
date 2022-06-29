/*
You are in charge of the cake for a child's birthday.
You have decided the cake will have one candle for each year of their total age.
They will only be able to blow out the tallest of the candles.
Count how many candles are tallest.
*/

#include <iostream>
#include <vector>
#include <algorithm> //for use of sort()

using namespace std;

int birthdayCakeCandles(vector<int> candles)
{
  int res{0}, highest{0};
  sort(candles.begin(), candles.end()); // sort in crescent order
  highest = candles.back();             // get the last value (highest)

  for (int elem : candles)
  {                      // iteract with each element
    if (elem == highest) // when element is equals the highest
    {
      res++;
    }
  }
  return res;
}

int main()
{
  vector<int> arr1{4, 4, 1, 3};                // -> 2
  vector<int> arr2{3, 2, 1, 3};                // -> 2
  vector<int> arr3{3, 2, 5, 3, 5, 2, 5, 2, 5}; // -> 4

  cout << birthdayCakeCandles(arr1) << endl;
  cout << birthdayCakeCandles(arr2) << endl;
  cout << birthdayCakeCandles(arr3) << endl;

  return 0;
}
