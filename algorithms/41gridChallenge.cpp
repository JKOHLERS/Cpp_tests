/*
Given a square grid of characters in the range ascii[a-z], rearrange elements of each row alphabetically, ascending.
Determine if the columns are also in ascending alphabetical order, top to bottom.
Return YES if they are or NO if they are not.
Example:
grid = ['abc','ade','efg']
The grid is illustrated below:
a b c
a d e
e f g

The rows are already in alphabetical order.
The columns a a e, b d f and c e g are also in alphabetical order, so the answer would be YES.
Only elements within the same row can be rearranged. They cannot be moved to a different row.

Sample Input:
STDIN   Function
-----   --------
1       t = 1
5       n = 5
ebacd   grid = ['ebacd', 'fghij', 'olmkn', 'trpqs', 'xywuv']
fghij
olmkn
trpqs
xywuv

Sample Output
YES

Explanation:
The 5x5 grid in the 1 test case can be reordered to:
abcde
fghij
klmno
pqrst
uvwxy

This fulfills the condition since the rows 1, 2, ..., 5 and the columns 1, 2, ..., 5 are all alphabetically sorted.
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
 * Complete the 'gridChallenge' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING_ARRAY grid as parameter.
 */

string gridChallenge(vector<string> grid)
{
    int const columnSize = grid[0].size();
    int const rowSize = grid.size();
    string result = "YES";

    // sort each element in ascending order
    for (string elem : grid)
    {
        sort(grid.begin(), grid.end());
    }

    // read columns
    for (int c = 0; c < columnSize; c++)
    {
        for (int r = 0; r < rowSize; r++)
        {
            // cout << grid[r][c] << " "; //test reading columns.

            /// test if column char is not in ascending order.
            if (grid[r][c] > grid[r][c + 1])
            {
                result = "NO";
                break;
            }
        }
        // cout << "\n"; //test reading columns.
    }

    return result;
}

int main()
{
    vector<string> gridA = {"ebacd",
                            "fghij",
                            "olmkn",
                            "trpqs",
                            "xywuv"}; // ->YES

    cout << gridChallenge(gridA) << "\n";

    return 0;
}
