#include <iostream>
using namespace std;
#define max 10
int front = -1, rear = -1;
int arr[max];

// Queue -> is a linear data stucture.

// elements are inserted from the one end process name is enqueue
/*
1. if the the array will be full then no elements can be inserted.
2. if there is not a single element then front & rear must be at -1 position,
   then bring them in 0 position so that we can insert a element from 0 index.
3. otherwise increase the rear and store the data in the rear index.
*/
void enqueue(int data)
{
    if (rear == max - 1)
    {
        cout << "Queue overflow";
        return;
    }
    else if (front == -1 && rear == -1)
    {
        front = 0;
        rear = 0;
    }
    else
    {
        rear++;
    }
    arr[rear] = data;
}

/*
dequeue -> we delete the data from that end where we have inserted the data.
1. First we will check if there will be not a singe element to delete then queue will
   be underflow.
2. otherwise increase the front and check if while deleting the element if crossed the rear,
    meanes we have also deleted last elemet , if front becomes greater than rear then it means that
    we have run out of space, then we have to replace front & rear at -1.
*/

void dequeue()
{
    int a;
    if (front == -1 || front > rear)
    {
        cout << "Queue underflow";
        return;
    }
    else
    {
        a = arr[front];
        front++;
        if (rear < front)
        {
            rear = -1;
            front = -1;
        }
    }
    cout << "Dequeued element is : " << a << endl;
}

void show_data(int arr[])
{
    for (int i = front; i <= rear; i++)
    {
        cout << endl;
        cout << arr[i] << " ";
    }
}

int main()
{
    // enqueue(10);
    // enqueue(20);
    // enqueue(30);
    // enqueue(40);
    // enqueue(50);
    // enqueue(60);
    // // show_data(arr);
    // // cout << endl;
    // // dequeue();
    // // dequeue();
    // enqueue(70);
    // enqueue(80);
    // enqueue(90);
    // enqueue(100);
    // enqueue(110);
    // show_data(arr);
    dequeue();
    return 0;
}