#include <iostream>
using namespace std;

//we will add,multiply and substract a series from 0 to n.

int do_sum(int n)
{
    int num = 0;
    //Base case
    if (n == 0)
    {
        return 0;
    }
    //recursive
    num = n + do_sum(n - 1);

    return num;
}

//Multiplying
int do_product(int n)
{
    int num=0;
    //Base case
    if (n == 0)
    {
        return 1;
    }
    //recursive
    return n * do_product(n-1);
    
}

int do_substraction(int n)
{
    int num=0;
    //Base case
    if (n == 0)
    {
        return 1;
    }
    //recursive
    return n - do_product(n-1);
    
}

int main()
{
    cout<<do_sum(3)<<endl;
    cout<<do_product(4)<<endl;
    cout<<do_substraction(4)<<endl;
    return 0;
}