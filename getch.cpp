#include <conio.h> //to use of getch()
#include <iostream>
#include <stack>

using namespace std;

int main()
{
  int pressKey;
  int extendedChar;
  pressKey = getch();
  extendedChar = getch();
  cout << pressKey << " - " << extendedChar;
}