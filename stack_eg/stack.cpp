/// This code is intended to simulate the use of the
/// stack structure in a UNDO & REDO context.

/// *** Importante note: This code was kept as an unique  ***
/// *** file in order to make compilation process easier. ***

/// Future Improvements:
/// (FI01) Websites.txt EoF verification (when all lines were already instatiated);
/// (FI02) Improve external file seek function (search for external libraries)
/// (FI03) Expand the quantity of data that can be instantiated.
/// (FI04) Check if use of <chrono> library can improve the performance.

#include <conio.h> //to use getch()
#include <iostream>
#include <stack>
#include <string>
#include <ctime> //can be changed by <chrono>.(FI04)
#include <fstream>

using namespace std;

/// keyboard keys definition
//#define KEY_UP 72 -> unused. can implement some future functionality
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_DOWN 80
#define ESC 27

stack<string> undoStack, undoTemp;
stack<string> redoStack, redoTemp;

/// classes
class WebSiteHistory
{
protected:
  string title;
  string url;
  string acesssDateTime;

public:
  /// setters
  void setTitle(string t) { title = t; }
  void setUrl(string u) { url = u; }
  void setAcesssDateTime(string d) { acesssDateTime = d; }

  /// setters
  string getTitle() { return title; }
  string getUrl() { return url; }
  string getAcesssDateTime() { return acesssDateTime; }

  /// constructors
  WebSiteHistory() {}
  WebSiteHistory(string title, string url)
  {
    time_t curtime;
    time(&curtime);
    this->title = title;
    this->url = url;
    this->acesssDateTime = ctime(&curtime);
  }

  /// methods
};

/// functions
WebSiteHistory history[12]; ///(FI03)
int dataCounter = 3;        // starts in 3 due 3 pre-loaded data.

void addDataFromFile()
{
  string title, url;
  bool newDataFound = false; // flag to check when a new website (data) was found

  /// open file
  ifstream myReadFile("websites.txt");

  /// check if the file can be opened
  if (!myReadFile)
  {
    cout << "Unable to open file!";
    exit(1); // call system to stop
  }

  /// get new data from opened file (FI02)
  /// (to be checked if it can be replaced by a builtin library/method.)
  while (!newDataFound)
  {
    int iterResults = 0;
    /// read next line
    myReadFile >> title;
    myReadFile >> url;

    /// iterate with undoStack data
    for (int i = 0; i <= undoStack.size(); i++)
    {
      string tempName;
      tempName = history[i].getTitle();
      if (tempName.compare(title) == 0) // if similar data is already found in undoStack
      {
        iterResults++;
      }
    }

    /// exit loop checking point
    if (iterResults == 0) // if no similar is found
    {
      newDataFound = true; // finish the while loop
    }

    /// Add EOF checking (FI02)
  };

  /// instance new data
  history[dataCounter] = WebSiteHistory(title, url);
  undoStack.push(history[dataCounter].getUrl() + " " + history[dataCounter].getAcesssDateTime());
  dataCounter++;

  // while (MyReadFile >> myText){cout << endl<< myText;}
  // while (getline(MyReadFile, myText)) { cout << endl << myText;}

  /// close file
  myReadFile.close();
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

  /// instantiating data sample
  history[0] = WebSiteHistory("Momondo", "www.momondo.ca");
  history[1] = WebSiteHistory("Kayak", "www.kayak.com");
  history[2] = WebSiteHistory("Expedia", "www.expedia.com");

  /// preloaded data sample
  undoStack.push(history[0].getUrl() + " " + history[0].getAcesssDateTime());
  undoStack.push(history[1].getUrl() + " " + history[1].getAcesssDateTime());
  undoStack.push(history[2].getUrl() + " " + history[2].getAcesssDateTime());

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
        addDataFromFile();
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
