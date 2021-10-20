#include <iostream>
using namespace std;

/*Queue-> queue is a data struchure in which we insert data from first and delete it from last (FIFO). */

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

//inserting node at first.
void enqueue()
{
    struct node *temp;
    int num;
    //taking input
    cout << "Enter data : ";
    cin >> num;
    //allocating memory
    temp = (struct node *)malloc(sizeof(struct node));
    temp->next = NULL;
    temp->data = num;
    if (head == NULL)
    {
        head = temp; // checking if there is not a single element.
    }
    else
    {
        temp->next = head;
        head = temp;
    }
    cout << num << " enqueued successfully" << endl;
}

//deletes the last node
void dequeue()
{
    struct node *head_ref, *head_ref2;
    int num;
    head_ref = head->next;
    head_ref2 = head;
    if (head == NULL)
    {
        cout << "Queue Underflow" << endl;
    }
    else
    {
        while (head_ref->next != NULL)
        {
            head_ref = head_ref->next;   //pointing last data
            head_ref2 = head_ref2->next; //pointing last second data
        }
        //we can also for loop by counter.

        num = head_ref->data;

        head_ref2->next = NULL;
        free(head_ref);
        cout << num << " Dequeued successfully" << endl;
    }
}

//Printing all the data
void show_list()
{
    struct node *ad;
    ad = head;
    while (ad != NULL)
    {
        cout << ad->data;
        cout << "->";
        ad = ad->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    enqueue();
    enqueue();
    enqueue();
    enqueue();
    dequeue();
    enqueue();
    dequeue();
    show_list();
    return 0;
}

/*
Enter data : 2
2 enqueued successfully
Enter data : 33 enqueued successfully
Enter data : 4
4 enqueued successfully
1 Dequeued successfully
Enter data : 5
5 enqueued successfully
2 Dequeued successfully
5->4->3->NULL
*/
