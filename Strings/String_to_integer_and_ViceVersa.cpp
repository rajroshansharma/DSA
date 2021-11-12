#include <iostream>
#include <string>
using namespace std;

int main()
{
    char abc[] = "89";

    int num1, num2;
    cout << "String = " << abc << endl;
    // converting string into integer using atoi() function
    num1 = atoi(abc);
    cout << "Integer = " << num1 + 1 << endl;

    // Dealing with strings

    string ab = "99";
    cout << "String = " << ab << endl;
    // converting string into integer using atoi() function
    num2 = stoi(ab);
    cout << "Integer = " << num2 + 1 << endl;

    return 0;
}

/*
OUTPUT
String = 89
Integer = 90
String = 99
Integer = 100
*/