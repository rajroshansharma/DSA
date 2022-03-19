#include <iostream>
using namespace std;

/*
Thoery
step 1 : if h is grater than l then proceed further or else terminate.
step 1:a : mid = h+l/2
step 1:b : if key is equal to mid element then ok
            else if key > mid element then function_call(m+1, h)
            else function_call(l,m+1)
*/

/*
we are first finding the mid and then comparing it with the key if find then ok,
or divide the array then see if the key is greater then mid then move with right array or else
move with the left array.
*/

// we have used return because at the moment we find the element then terminate the program return the value.

int binary_search(int a[], int l, int h, int key)
{
    int m;
    if (h > l)
    {
        m = (h + l) / 2;
        if (key == a[m])
        {
            return m;
        }
        else if (key > a[m])
        {
            return binary_search(a, m + 1, h, key);
        }
        else
        {
            return binary_search(a, l, m + 1, key);
        }
    }
}

int main()
{
    int arr[10] = {11, 24, 39, 40, 51, 69, 71, 89, 99, 100};
    int key = 89;
    int result;
    result = binary_search(arr, 0, 9, 89);
    cout << result;
    return 0;
}

/*
Recursive method

binarySearch(arr, x, low, high)
    if low > high
        return False
    else
        mid = (low + high) / 2
        if x == arr[mid]
            return mid
        else if x > arr[mid]        // x is on the right side
            return binarySearch(arr, x, mid + 1, high)
        else                               // x is on the right side
            return binarySearch(arr, x, low, mid - 1)
__________________________________________________________________________

Iteration method

do until the pointers low and high meet each other.
    mid = (low + high)/2
    if (x == arr[mid])
        return mid
    else if (x > arr[mid]) // x is on the right side
        low = mid + 1
    else                       // x is on the left side
        high = mid - 1
*/