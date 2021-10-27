#include <iostream>
#include <algorithm>
using namespace std;
#define max 10
int stk[max] = {10, 20, 45, 29, 50, 77, 87, 90, 35, 81};

void show_data(int stk[])
{
    for (int i = 0; i < max; i++)
    {
        cout << stk[i] << " ";
    }
}

void binary_search(int key)
{
    int low = 0, high = max - 1, mid;
    sort(stk, stk + 10); // sorting the array. it is mandotory to perform binary search.
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (stk[mid] == key)
        {
            cout << key << " found Succesfully at Position : " << mid; // it will give the position from the sorted array.
            return;
        }
        else if (stk[mid] < key)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    cout << key << " Not Found";
}

int main()
{
    binary_search(3);
    cout << endl;
    show_data(stk); // this is showing the sorted array.
    return 0;
}

/*OUTPUT
45 found Succesfully at Position : 4
10 20 29 35 45 50 77 81 87 90

21 Not Found
10 20 29 35 45 50 77 81 87 90
*/