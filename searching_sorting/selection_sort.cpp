#include <iostream>
using namespace std;

int small_index(int a[], int start, int end)
{
    int small_in = a[start];
    int index;
    for (int i = start; i < end; i++)
    {
        if (small_in > a[i])
        {
            small_in = a[i];
            index = i;
        }
    }
    return index;
}

int main()
{
    int arr[5] = {23, 6, 33, 21, 9};
    int temp, recived_index;
    for (int i = 0; i < 5; i++)
    {
        recived_index = small_index(arr, i, 5);
        temp = arr[i];
        arr[i] = arr[recived_index];
        arr[recived_index] = temp;
    }
    for (int j = 0; j < 5; j++)
    {
        cout << arr[j] << " ";
    }
    return 0;
}