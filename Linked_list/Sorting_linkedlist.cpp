#include <iostream>
using namespace std;

/*IDEA
we are performing bubble sort on the list.we are taking two pointers one is taking address of head and another is taking it's next address.
two loops are used first element is searched from the entire list , then second element is compared and this process is gone ,untill they become null.

you can implement diffrent sorting algorithm in this, you can also do like this : create a empty linked list and insert element according to its 
size if it is big then place at last , if small place it at first and middle like this.
*/

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

// Inserting node at last.
void insert_node_last(int num)
{
    struct node *temp;
    struct node *head_ref;
    head_ref = head;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->next = NULL;
    temp->data = num;
    if (head == NULL)
    {
        head = temp; // checking if there is not a single element.
    }
    else
    {
        while (head_ref->next != NULL)
        {
            head_ref = head_ref->next;
        }
        head_ref->next = temp;
    }
}

// sorting alogithm
void sort_for()
{
    struct node *ad, *ad2;
    int temp_num;
    ad = head;
    ad2 = NULL;
    if (head == NULL)
    {
        return;
    }
    else
    {
        while (ad != NULL)
        {
            ad2 = ad->next;
            while (ad2 != NULL)
            {
                if (ad->data > ad2->data)
                {
                    temp_num = ad->data;
                    ad->data = ad2->data;
                    ad2->data = temp_num;
                }
                ad2 = ad2->next;
            }
            ad = ad->next;
        }
    }
}

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
    cout << "NULL";
}

int main()
{
    // inserting node first
    insert_node_last(52);
    insert_node_last(12);
    insert_node_last(20);
    insert_node_last(91);
    insert_node_last(14);
    cout << "Given list" << endl;
    show_list();
    cout << endl
         << "Sorted list" << endl;
    // calling sorting function
    sort_for();
    show_list();

    return 0;
}

/*OUTPUT
Given list52->12->20->91->14->NULL
Sorted list
12->14->20->52->91->NULL
*/
