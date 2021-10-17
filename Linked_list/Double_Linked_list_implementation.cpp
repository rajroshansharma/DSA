#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *prev_link;
    struct node *next_link;
};

struct node *head = NULL;

//insert at last
void insert_last()
{
    int num;
    cout << "Enter the data :";
    cin >> num;
    struct node *temp, *head_ref;
    head_ref = head;
    //crating node
    temp = (struct node *)malloc(sizeof(struct node));
    temp->prev_link = NULL;
    temp->next_link = NULL;
    temp->data = num;
    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        while (head_ref->next_link != NULL)
        {
            head_ref = head_ref->next_link;
        }
        head_ref->next_link = temp;
        temp->prev_link = head_ref;
    }
}

//insert at begning
void insert_beg()
{
    struct node *temp, *head_ref;
    head_ref = head;
    int num;
    cout << "Enter the data : ";
    cin >> num;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->prev_link = NULL;
    temp->next_link = NULL;
    temp->data = num;
    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        head = temp;
        head->next_link = head_ref;
        head_ref->prev_link = temp;
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
        ad = ad->next_link;
    }
    cout << "NULL";
}

//Printing list from reverse
void show_rev_list()
{
    struct node *head_ref;
    head_ref = head;
    while (head_ref->next_link != NULL)
    {
        head_ref = head_ref->next_link;
    }
    cout << endl
         << "In Reversed order.";
    while (head_ref != NULL)
    {
        cout << head_ref->data;
        cout << "->";
        head_ref = head_ref->prev_link;
    }
    cout << "NULL";
}

void insert_mid()
{
    int num, pos;
    struct node *ad, *ad2, *temp;
    ad = head;
    cout << "Enter postion : ";
    cin >> pos;
    cout << endl;
    cout << "Enter the data : ";
    cin >> num;
    //allocating memory
    temp = (struct node *)malloc(sizeof(struct node));
    temp->next_link = NULL;
    temp->prev_link = NULL;
    temp->data = num;
    for (int i = 1; i < pos; i++)
    {
        ad = ad->next_link;
    }
    temp->next_link = ad->next_link;
    ad->next_link = temp;
    temp->prev_link = ad;
    ad2 = temp->next_link;
    ad2->prev_link = temp;
}

//Delete node at first
void del_first_node()
{
    struct node *temp, *temp2;
    int num;
    if (head == NULL)
    {
        cout << "Nothing to delete.";
    }
    temp = head->next_link;
    temp2 = head;
    head = temp;
    temp->prev_link = NULL;
    num = temp2->data;
    free(temp2);
    cout << num << "Deleted succesfully." << endl;
}

//Delete node at last node
void del_last_node()
{
    struct node *ad, *ad2;
    int num;
    ad = head;
    while (ad->next_link != NULL)
    {
        ad = ad->next_link;
    }
    num = ad->data;
    ad2 = ad->prev_link;
    ad2->next_link = NULL;
    free(ad);
    cout << num << " Deleted Succesfull" << endl;
}

//Deletion in middle
void del_mid_node()
{
    int pos, num;
    struct node *ad, *ad2, *ad3;
    ad = head;
    cout << "Enter postion : ";
    cin >> pos;
    for (int i = 1; i < pos; i++)
    {
        ad = ad->next_link;
    }
    ad2 = ad->prev_link;
    ad3 = ad->next_link;
    ad2->next_link = ad->next_link;
    ad3->prev_link = ad2;
    num = ad->data;
    free(ad);
    cout << num << " Deleted Succesfull" << endl;
}

int main()
{
    insert_last();
    insert_last();
    insert_last();
    insert_last();
    // insert_beg();
    // insert_beg();
    // insert_beg();
    // insert_mid();
    del_mid_node();
    show_list();
    show_rev_list();
    return 0;
}

/*
OUTPUT

Deletion in first node
Enter the data :1
Enter the data :2
Enter the data :3
Enter the data :4
1 Deleted succesfully.
2->3->4->NULL

Deletion in last node
Enter the data :1
Enter the data :2
Enter the data :3
Enter the data :4
4 Deleted Succesfull
1->2->3->NULL

Deletion in given position
Enter the data :1
Enter the data :2
Enter the data :3
Enter the data :4
Enter postion : 2
2 Deleted Succesfull

*/