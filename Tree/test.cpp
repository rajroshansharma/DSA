#include <iostream>
using namespace std;

int a = 0;

int do_sum(int a, int b)
{
    a = a + b;
}

int main()
{
    do_sum(5, 3);
    cout << a;
    return 0;
}
