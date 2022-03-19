#include <iostream>
using namespace std;

/*
Linear search - it is a searching technique, where we take a key wcich to be searched then we compare every element with the key untill they become
equal. at this state we can conclude that we have succesfully find the element.
I have implemented using for & while loop for better understanding and broade vision.
Time complexity.
best case - bigO(1)
avrage case - theth(n/1)
worst case - bigO(n)
*/

int main()
{
    int arr[10] = {1, 4, 3, 78, 34, 90, 45, 66, 99, 87};
    int key = 5;
    int i = 0;
    int count = 0;
    for (int i = 0; i < 10; i++)
    {
        if (arr[i] == key)
        {
            cout << "Search succesfull " << key << " is found on index " << i; // if we will be finding any element then we will be increase the counter.
            count++;
        }
    }
    if (count == 0) // if the counter is 0 meanes no element have been matched yet.
    {
        cout << "Element not found !";
    }

    // while (i != -1)
    // {
    //     if (arr[i] == key)
    //     {
    //         cout << "Search succesfull " << key << " found on index " << i;
    //         i = -1;
    //         break;
    //     }
    //     i++;
    // }

    return 0;
}
