/*
Given a time in 12-hour AM/PM format, convert it to military (24-hour) time.

Note: - 12:00:00AM on a 12-hour clock is 00:00:00 on a 24-hour clock.
- 12:00:00PM on a 12-hour clock is 12:00:00 on a 24-hour clock.

Sample Input
07:05:45PM

Sample Output
19:05:45
*/

#include <iostream>
#include <string>

using namespace std;

string timeConversion(string s)
{
  char amPm = s[8];
  string hourS = s.substr(0, 2);
  string newHourS;
  string minSec = s.substr(2, 6);

  if (hourS == "12" && amPm == 'A')
  {
    newHourS = "00";
  }
  else if (hourS == "12" && amPm == 'P')
  {
    newHourS = "12";
  }
  else if (amPm == 'P')
  {
    newHourS = to_string(stoi(hourS) + 12);
  }
  else
  { // amPm == 'A'
    newHourS = hourS;
  }
  return newHourS + minSec;
}

int main()
{
  string time1 = "07:05:45AM";
  string time2 = "07:05:45PM";
  string time3 = "12:35:35AM";
  string time4 = "12:35:35PM";
  string time5 = "05:55:55AM";
  string time6 = "05:55:55PM";

  cout << "\n"
       << timeConversion(time1);
  cout << "\n"
       << timeConversion(time2);
  cout << "\n"
       << timeConversion(time3);
  cout << "\n"
       << timeConversion(time4);
  cout << "\n"
       << timeConversion(time5);
  cout << "\n"
       << timeConversion(time6);

  return 0;
}
