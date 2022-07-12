#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    // Complete the code.
    int a=1, b=50;
    string literals[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    for(int i=a; i <= b; i++){
        if(i>9 && (i%2==0)){
            cout << "even" << endl;
        } else if (i>9 && (i%2!=0)) {
            cout << "odd" << endl;      
        } else {
        cout << literals[i] << endl;
        }
    }
    
    /*
    int a=8,b=11;
    for(int i=a; i <= b; i++){
        if (i == 1){
            cout << "one";
        }else if (i == 2) {
            cout << "two";
        }else if (i == 3) {
            cout << "three";
        }else if (i == 4) {
            cout << "four";
        }else if (i == 5) {
            cout << "five";
        }else if (i == 6) {
            cout << "six";
        }else if (i == 7) {
            cout << "seven";
        }else if (i == 8) {
            cout << "eight";
        }else if (i == 9) {
            cout << "nine";
        }else if (i > 9 && (i%2==0)) {
            cout << "even";
        }else if (i > 9 && (i%2!=0)){
            cout << "odd";
        }
        cout << "\n";
    }
    */
    
    return 0;
}
