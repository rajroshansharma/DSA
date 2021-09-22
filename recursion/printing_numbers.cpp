#include<iostream>
using namespace std;

void print_number(int n){
    //base case
    if (n == 0)
    {
        return;
    }
    //recursion
    print_number(n-1);
    //task
    cout<<" "<<n;
    
}

int main(){
    print_number(5);
    return 0;
}