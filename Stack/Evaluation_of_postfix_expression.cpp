#include <iostream>
using namespace std;
#include <bits/stdc++.h>
#include <string>

#define max 10
int stk[max];
int p = -1;

void push(int data)
{
    if (p == max - 1) // condition 1. full k ly
    {
        cout << endl
             << "STACK OVERFLOW" << endl;
    }
    else
    {
        p++;
        stk[p] = data;
    }
}

int pop()
{
    int num;
    if (p == -1)
    {
        cout << endl
             << "STACK UNDERFLOW" << endl;
        return -1;
    }
    else
    {
        num = stk[p];
        p--;
        return num;
    }
}

int do_operation(char symbol, int op1, int op2)
{
    switch (symbol)
    {
    case '+':
        return op1 + op2;
    case '-':
        return op1 - op2;
    case '*':
        return op1 * op2;
    case '/':
        return op1 / op2;
    case '^':
        return pow(op1, op2);
    default:
        cout << "Invalid operator";
        exit(0);
    }
}

int is_digit(char symbol)
{
    return (symbol >= '0' && symbol <= '9');
}

void show_data()
{
    for (int i = 0; i <= p; i++)
    {
        cout << " " << stk[i];
    }
    cout << endl;
}

int main()
{
    string postfix;
    int a, b, result;
    postfix = "32+";
    char symbol;
    for (int i = 0; i < postfix.length(); i++)
    {
        symbol = postfix[i];
        if (is_digit(symbol))
        {
            push(symbol - '0');
        }
        else
        {
            a = pop();
            b = pop();
            result = do_operation(symbol, a, b);
            push(result);
        }
    }
    result = pop();
    cout << result;

    return 0;
}