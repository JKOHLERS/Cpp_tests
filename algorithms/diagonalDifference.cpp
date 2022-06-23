/*
Given a square matrix, calculate the absolute difference between the sums of its diagonals.
For example, the square matrix  is shown below:
1 2 3
4 5 6
9 8 9
The left-to-right diagonal = 1+5+9=15.
The right to left diagonal = 3+5+9=17.
Their absolute difference is 15-17=2.
*/

#include <iostream>
#include <vector>

using namespace std;

int diagonalDifference(vector<vector<int>> arr)
{
  int rowsQty = 0;
  int colsQty = 0;
  int currCol = 0;  // counter
  int sumLeft = 0;  // left-to-right diagonal
  int sumRight = 0; // right-to-left diagonal
  int result = 0;   // difference between sumLRD and sumRLD

  // get qtd of rows (size)
  rowsQty = arr.size();

  // check if its a square matrix
  for (int i = 0; i < rowsQty; i++)
  {
    // get qtd of column of each row (size)
    colsQty = arr[i].size();
    // check if the columns and rows are equal
    if (colsQty != rowsQty)
    {
      cout << "This is not a square matrix! You can't continue!";
      exit(1);
    }
  }

  // sum left-to-right diagonal
  for (int i = 0; i < rowsQty; i++)
  {
    sumLeft = sumLeft + arr[i][i];
  }

  // sum right-to-left diagonal
  currCol = colsQty - 1;
  for (int i = 0; i < rowsQty; i++)
  {
    sumRight = sumRight + arr[i][currCol];
    currCol--;
  }

  // module of difference
  result = abs(sumLeft - sumRight);
  return result;
}

int main()
{
  vector<vector<int>> matrix1 = {{1, 2, 3},
                                 {4, 5, 6},
                                 {9, 8, 9}}; // answer = 2

  vector<vector<int>> matrix2 = {{11, 2, 4},
                                 {4, 5, 6},
                                 {10, 8, -12}}; // answer = 15

  vector<vector<int>> matrix3 = {{11, 22, 33, 44},
                                 {44, 55, 66, 77},
                                 {77, 88, 99, 11},
                                 {-22, 33, 44, 55}}; // answer = 44

  vector<vector<int>> matrix4 = {{11},
                                 {44, 55, 66},
                                 {77, 88},
                                 {44, 55, 66, 77, 55},
                                 {11, 22, 33, 44}}; // you shall no pass!

  cout << diagonalDifference(matrix1) << endl;
  cout << diagonalDifference(matrix2) << endl;
  cout << diagonalDifference(matrix3) << endl;
  cout << diagonalDifference(matrix4) << endl;

  return 0;
}
