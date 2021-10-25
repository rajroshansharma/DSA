#include <iostream>
using namespace std;

// declaring varibles.

#define max 5
int stk[max];
int p = -1;

void push()
{
    int data;
    cout << "Enter the data :";
    cin >> data;

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

void pop()
{
    int num;
    if (p == -1)
    {
        cout << endl
             << "STACK UNDERFLOW" << endl;
    }
    else
    {
        num = stk[p];
        p--;
        cout << num << endl
             << "Poped succesfully" << endl;
    }
}

void show_data()
{
    for (int i = 0; i <= p; i++)
    {
        cout << " " << stk[i];
    }
    cout << endl;
}

// prints the top element
void peep()
{
    if (p == -1)
    {
        cout << endl
             << "Nothing to show" << endl;
    }
    else
    {
        cout << stk[p] << endl;
    }
}

int main()
{
    int choice;
    cout << "welcome to stack implemation" << endl;
    do
    {
        cout << "Enter your choice:" << endl
             << "1. PUSH" << endl
             << "2. POP" << endl
             << "3. Show data" << endl
             << "4. Peep" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            push();
            break;

        case 2:
            pop();
            break;

        case 3:
            show_data();
            break;
        case 4:
            peep();
            break;

        default:
            break;
        }
    } while (choice != 0);
}

/*it is menu based programm you can also extract the pushing and poping functions from here*/

/*OUTPUT

welcome to stack implemation
Enter your choice:
1. PUSH
2. POP
3. Show data
4. Peep
4

Nothing to show
Enter your choice:
1. PUSH
2. POP
3. Show data
4. Peep
1
Enter the data :34
Enter your choice:
1. PUSH
2. POP
3. Show data
4. Peep
1
Enter the data :67
Enter your choice:
1. PUSH
2. POP
3. Show data
4. Peep
1
Enter the data :89
Enter your choice:
1. PUSH
2. POP
3. Show data
4. Peep
3
Enter the data :100
Enter your choice:
1. PUSH
2. POP
3. Show data
4. Peep
3
 34 67 100
Enter your choice:
1. PUSH
2. POP
3. Show data
4. Peep
*/
