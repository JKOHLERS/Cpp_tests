// use of lists
#include <iostream>
#include <list>

using namespace std;

void printElem(string listName, list<int> myList)
{
  // printing list elements
  cout << endl
       << listName << " : ";
  for (int element : myList)
  {
    cout << element << " ";
  }
}

int main()
{
  list<int> basicList;                          // basic list declaration
  list<int> basicList1, basicList2, basicList3; // declaring 3 list at same time
  list<int> positionList(10);                   // list with 10 positions
  list<int> positionListValues(10, 30);         // list with 10 positions, each position valued as 30
  // printing list elements
  printElem("positionListValues", positionListValues); // print list

  // insert list elements by front
  for (int i = 0; i < 10; i++)
  {
    basicList.push_front(i);
  }

  // removing list elements
  basicList.pop_front();

  // insert list elements by back
  basicList.push_back(100);

  // inserting elements in the middle of list
  list<int>::iterator it;  // creating iterator to control position
  it = basicList.begin();  // attrib the iterator the first position value
  advance(it, 3);          // advance to position 3 to insert value
  basicList.insert(it, 0); // insert value 0 on postiion 'it'

  printElem("basicList", basicList); // print list

  // sort list elements
  basicList.sort();
  printElem("basicList", basicList); // print list

  // reverse list elements
  basicList.reverse();
  printElem("basicList", basicList); // print list

  return 0;
}
