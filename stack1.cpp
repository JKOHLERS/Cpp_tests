//stack exercise

#include <iostream>
using namespace std;

const int elements = 10;
int stack[elements];
int top = -1;

//display all elements
int display()
{
  cout << endl;
  for (int i = 0; i < elements; i++)
  {
    cout << "[" << stack[i] << "] ";
  }
  cout << endl;
}

//insert element
int push()
{
  if (top >= elements - 1)
  {
    cout << "The stack is full!" << endl;
  }
  else
  {
    top++;
    stack[top] = 11;
    display();
  }
}

//delete element
int pop()
{
  if (top < 0)
  {
    cout << "The stack is empty!" << endl;
  }
  else
  {
    stack[top] = 0;
    top--;
    display();
  }
}

//delete all elements
int empty()
{
  for (int i = 0; i <= top; i++)
  {
    stack[i] = 0;
  }
  top = 0;
}

//auto fill for example
int autoFill()
{
  for (int i = 0; i < elements; i++)
  {
    stack[i] = i + 1;
  }
  display();
}

int main()
{
  int option;
  do
  {
    cout << "\nMake you choice:"
         << "\n1 - Push"
         << "\n2 - Pop"
         << "\n3 - Empty"
         << "\n4 - Display"
         << "\n9 - Exit"
         << "\n -> ";
    cin >> option;

    switch (option)
    {
    case 1:
      push();
      break;
    case 2:
      pop();
      break;
    case 3:
      empty();
      break;
    case 4:
      display();
      break;
    case 9:
      cout << "See you soon! Bye!" << endl;
      break;
    default:
      cout << "Option not valid!" << endl;
      break;
    }
  } while (option != 9);

  return 0;
}