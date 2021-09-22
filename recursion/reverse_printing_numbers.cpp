#include<iostream>
using namespace std;

void reverse_print_number(int n){
    //base case
    if (n == 0)
    {
        return;
    }
    //task
    cout<<" "<<n;

    //recursion
    reverse_print_number(n-1);

    
    
}

int main(){
    reverse_print_number(5);
    return 0;
}