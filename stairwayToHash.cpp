/* www.hackerhank.com
Staircase detail
This is a staircase of size :

   #
  ##
 ###
####
Its base and height are both equal to . It is drawn using # symbols and spaces. The last line is not preceded by any spaces.
Write a program that prints a staircase of size .

Function Description
Complete the staircase function in the editor below.

staircase has the following parameter(s):
int n: an integer
Print

Print a staircase as described above.
Input Format

A single integer, , denoting the size of the staircase.
*/

#include <iostream>

void staircase(int n)
{
  int spaces{n};
  int hashes{1};
  while (spaces)
  {
    for (int i{(spaces - 1)}; i > 0; i--)
    {
      std::cout << ' ';
    }
    for (std::size_t i{}; i < hashes; i++)
    {
      std::cout << '#';
    }
    std::cout << '\n';
    spaces--;
    hashes++;
  }
}

int main()
{
  staircase(10);
  return 0;
}
