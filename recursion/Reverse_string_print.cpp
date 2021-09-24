#include<iostream>
using namespace std;

void reverse_str(string str,int n)
{
    //base case
    if (n == -1)
    {
        return;
    }

    //task
    cout<<str[n];

    //recursive
    reverse_str(str,n-1);
    
}

int main(){
    string var = "RACE";
    int str_len;
    str_len = var.length();
   
    reverse_str(var, str_len - 1);

    return 0;
}