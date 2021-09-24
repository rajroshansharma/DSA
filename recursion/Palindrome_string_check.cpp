#include <iostream>
using namespace std;

/*A string is said to be a palindrome
if the string read from left to right is equal to the string 
read from right to left. For example, ABA, ABBCCBBA etc. ABC, UILO are
not palindrome*/

/*
Idea -> we are first reversing a string and then storing into another variable
let it be 'a'. and then we are comparing them if they are equal then they are plindrom
else they are not. 
*/


string a;

void palindrome(string stk, int n)
{ 
    int count=0;
    //Base case
    if (n == -1)
    {
        return;
    }
    else
    {
        //task 
        a = a + stk[n];
        //recursive
        palindrome(stk, n - 1);
        
    }
}

int main()
{
    string var = "RACECAR";
    int str_len;
    str_len = var.length();
   
    palindrome(var, str_len - 1);
   
    if (a == var)
    {
        cout<<var<<" is a palindrome";
    }
    else
    {
        cout<<var<<" is not a palindrome";
    }
    
    
    
    return 0;
}