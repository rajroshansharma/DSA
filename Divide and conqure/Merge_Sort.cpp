#include <iostream>
using namespace std;
/*
IDEA
What we are doing is we are first breaking down the array and then merging them. We are using the concept of
merging states that consider a sitution where i and j are pointing to the first index of the to arrays and k
is pointing to the first index of the resultant array.
next we are comparing left[i] to right[j] whichever is smaller or greater is inserted in the resultant array
then we are increasing the value of the pointers.

NOTE
there is myth that we are actually the array into parts and then merging by using address or something like
that. these things are not happening we are using pointing and refrring only one array and providing its starting
as well as beggning and mid too. and then it is copied into two arrays and then we are merging into the same array
which we have got in the argument(we are overwriting).
These things are going on recursivly.
*/

void show_data(int arr[], int n);
void show_data(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int merge(int stk[], int beg, int mid, int end)
{
    int i, j, k;
    int n1 = mid - beg + 1;          // size od first of array
    int n2 = end - mid;              // size of second array
    int left_arr[n1], right_arr[n2]; // tempoary array
    // copying array
    for (int i = 0; i < n1; i++)
    {
        left_arr[i] = stk[beg + i];
    }
    for (int j = 0; j < n2; j++)
    {
        right_arr[j] = stk[mid + 1 + j];
    }
    // merging
    i = 0;
    j = 0;
    k = beg;
    while (i < n1 && j < n2)
    {
        if (left_arr[i] <= right_arr[j])
        {
            stk[k] = left_arr[i];
            i++;
        }
        else
        {
            stk[k] = right_arr[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        stk[k] = left_arr[i];
        k++, i++;
    }
    while (j < n2)
    {
        stk[k] = right_arr[j];
        k++, j++;
    }
}

void merge_sort(int stk[], int beg, int end)
{
    // base condition
    /*if begging is becoming big then it is oveous that elements in the array is overed and
    we need to stop .*/
    if (beg >= end)
    {
        return;
    }
    int mid = (beg + end) / 2;
    merge_sort(stk, beg, mid);
    merge_sort(stk, mid + 1, end);
    merge(stk, beg, mid, end);
}

int main()
{
    int a[] = {12, 31, 25, 8, 32, 17, 40, 42};
    int n = sizeof(a) / sizeof(a[0]);
    cout << "Before sorting array elements are - " << endl;
    show_data(a, n);
    merge_sort(a, 0, n - 1);
    cout << endl
         << "After sorting array elements are - " << endl;
    show_data(a, n);
    return 0;
}

/*
OUTPUT
Before sorting array elements are -
12 31 25 8 32 17 40 42
After sorting array elements are -
8 12 17 25 31 32 40 42
*/