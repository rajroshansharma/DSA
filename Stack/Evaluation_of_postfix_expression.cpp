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

/*
OUTPUT
input : 32+
ouptput : 5

Explantion
push(3)
push(2)
a = pop()
b = pop()
c = a + b
push(c)
output print c

Algorithm 
1. If symbol is digit then push. 
2. Else pop 2 times and store them in two variables. 
3. perform operations on two variables and store in variable 3 
4. push variable 3 

Notes
1. In line number 63 we can see that there is a range of digits which are in character data type. the function is returning 0 for false and 1 for true. 
2. To change character from int data type we can write like character_variable - '0' 
3. In C++ there is no functions four strings we need to access those things by using the class method. for example postfix.length() 



upcoming alogrthm
drawback -> can only calculate for single digits
sulution add space in that string.
refrence -> https://algorithms.tutorialhorizon.com/evaluation-of-postfix-expressions-polish-postfix-notation-set-2/#:~:text=Postfix%20notation%20is%20a%20notation,operands%20appear%20before%20their%20operators.&text=Operands%20are%20real%20numbers%20(could%20be%20multiple%20digits).&text=Blanks%20are%20used%20as%20a%20separator%20in%20expression.




*/
