/*
hackerLand University has the following grading policy:

Every student receives a grade in the inclusive range from 0 to 100.
Any  grade less than 40 is a failing grade.
Sam is a professor at the university and likes to round each student's grade  according
to these rules:
 - If the difference between grade the and the next multiple of 5 is less than 3, round grade
  up to the next multiple of 5.
 - If the value of grade is less than 38, no rounding occurs as the result will still be
  a failing grade.

Examples:
  - grade = 84 round to 85(85 - 84 is less than 3)
  - grade = 29 do not round (result is less than 40)
  - grade = 57 do not round (60 - 57 is 3 or higher)
Given the initial value of grade for each of Sam's n students, write code to automate the
rounding process.
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> gradingStudents(vector<int> grades)
{
  vector<int> vTemp = grades;

  for (int i = 0; i < vTemp.size(); i++)
  {
    if (vTemp[i] >= 38)
    {
      int nextMultiple = (((vTemp[i] / 5) * 5) + 5);
      if ((nextMultiple - vTemp[i]) < 3)
      {
        vTemp[i] = nextMultiple;
      }
    }
  }
  return vTemp;
}

int main()
{
  vector<int> grades1{73, 67, 38, 33};

  vector<int> result = gradingStudents(grades1);
  for (int elements : result)
  {
    cout << elements << endl;
  };

  return 0;
}
