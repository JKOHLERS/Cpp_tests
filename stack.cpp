/// This code is intended to simulate the use of the
/// stack structure in the UNDO & REDO context.

#include <conio.h> //to use of getch()
#include <iostream>
#include <stack>
#include <string>

using namespace std;

/// keyboard keys definition
//#define KEY_UP 72 -> unused. can implement some future functionality
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_DOWN 80
#define ESC 27

stack<string> undoStack, undoTemp;
stack<string> redoStack, redoTemp;

/// functions
int dataCounter = 4; // starts in 4 due 3 pre-loaded "data_".

void addData()
{
  undoStack.push("data_" + to_string(dataCounter));
  dataCounter++;
}

void undo()
{
  if (!undoStack.empty())
  {
    string undoTemp = undoStack.top();
    undoStack.pop();
    redoStack.push(undoTemp);
  }
  else
  {
    cout << "**** No more data! ****" << endl;
  }
}

void redo()
{
  if (!redoStack.empty())
  {
    string redoTemp = redoStack.top();
    redoStack.pop();
    undoStack.push(redoTemp);
  }
  else
  {
    cout << "**** No more data! ****" << endl;
  }
}

void display()
{
  /// UNDO stack display
  undoTemp = undoStack;
  cout << endl
       << "UNDO STACK["
       << undoStack.size()
       << "] : ";
  while (!undoTemp.empty())
  {
    cout << undoTemp.top() << " ";
    undoTemp.pop();
  }

  /// REDO stack display
  redoTemp = redoStack;
  cout << endl
       << "REDO STACK["
       << redoStack.size()
       << "] : ";
  while (!redoTemp.empty())
  {
    cout << redoTemp.top() << " ";
    redoTemp.pop();
  }
}

/// main function
int main()
{
  int pressKey,
      extendedKey;

  /// preloaded data sample
  undoStack.push("data_1");
  undoStack.push("data_2");
  undoStack.push("data_3");

  display();
  /// main menu
  do
  {
    cout << endl
         << endl
         << "Press keyboard key for: " << endl
         << "Left Arrow - UNDO" << endl
         << "Right Arrow - REDO" << endl
         << "Down Arrow - ADD DATA TO STACK" << endl
         << "ESC - EXIT" << endl
         << "Choose an option: ";
    pressKey = getch();
    /*
      Important note: On pressing an arrow key, 2 characters are received.
      The first character is the ASCII value '224' or '0', which indicates an arrow key
      was pressed. The second character indicates the specific pressed key code, as
      demonstred on above definitions.
    */
    if (pressKey == 0 || pressKey == 224)
    {
      switch (extendedKey = getch())
      {
      case KEY_LEFT:
        cout << "UNDO" << endl;
        undo();
        display();
        break;
      case KEY_RIGHT:
        cout << "REDO" << endl;
        redo();
        display();
        break;
      case KEY_DOWN:
        cout << "ADD DATA TO UNDO" << endl;
        addData();
        display();
        break;
      default:
        cout << "Please enter a valid option!" << endl;
      }
    }
    else if (pressKey != ESC) // condition to any other key pressed than arrows
    {
      cout << "Please press an arrow key!" << endl;
    }
  } while (pressKey != ESC);
  cout << "Thanks for coming! Bye!"
       << endl
       << endl;
  return 0;
}
