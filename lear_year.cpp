// this code check if a year is leap or not

#include <iostream>
using namespace std;

int main()
{
  int year;

  cout << "Type an year: ";
  cin >> year;

  if (year % 4 == 0)
  {
    if (year % 100 == 0)
    {
      if (year % 400 == 0)
      { // if divisible by 4, by 100 and by 400.
        cout << year << " is a leap year!";
      }
      else
      { // if divisible by 4, by 100 and but not by 400.
        cout << year << " is not a leap year!";
      }
    }
    else
    { // if divisible by 4, but not by 100.
      cout << year << " is a leap year!";
    }
  }
  else
  { // if not divisible by 4.
    cout << year << " is not a leap year!";
  }

  return 0;
}
