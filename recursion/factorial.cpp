#include<iostream>
using namespace std;

int factorial(int n){
    int num;
    //base case
    if (n == 1)
    {
        return 1;
    }
    //recursive
    num = n * factorial(n-1);
    //task
    return num;
    
}

int main(){
    cout<<factorial(5);
    return 0;
}