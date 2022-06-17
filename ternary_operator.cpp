//ternary operator use
#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

bool isNumber(const string& str)
{
    for (char const &c : str) {
        if (std::isdigit(c) == 0) return false;
    }
    return true;
}

int main(){
    string str1 = "231524randstr23";
    string str2 = "23152423";
    string str3 = "a3152423";

    isNumber(str1) ? cout << "Number\n" : cout << "Not number\n";
    isNumber(str2) ? cout << "Number\n" : cout << "Not number\n";
    isNumber(str3) ? cout << "Number\n" : cout << "Not number\n";

    return EXIT_SUCCESS;
}
