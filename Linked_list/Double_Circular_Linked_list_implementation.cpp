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
        temp->next_link = head; //self loop
    }
    else
    {
        while (head_ref->next_link != head)
        {
            head_ref = head_ref->next_link;
        }
        head_ref->next_link = temp;
        temp->prev_link = head_ref;
        temp->next_link = head;
    }
}

//insert at begning
void insert_beg()
{
    struct node *temp, *head_ref, *ad;
    head_ref = head;
    ad = head;
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
        temp->next_link = head; //self loop
    }
    else
    {
        while (ad->next_link != head)
        {
            ad = ad->next_link;
        }
        head_ref->prev_link = temp;
        temp->next_link = head_ref;
        head = temp;
        ad->next_link = temp;
    }
}
//Printing all the data
void show_list()
{
    struct node *ad;
    ad = head;
    do
    {
        cout << ad->data;
        cout << "->";
        ad = ad->next_link;
    } while (ad != head);
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
    ad2 = ad->next_link;
    ad->next_link = temp;
    temp->next_link = ad2;
    temp->prev_link = ad;
    ad2->prev_link = temp;
}

//Delete node at first
void del_first_node()
{
    struct node *temp, *temp2, *ad;
    int num;
    ad = head;
    temp = head;
    if (head == NULL)
    {
        cout << "Nothing to delete.";
    }
    else
    {
        while (ad->next_link != head)
        {
            ad = ad->next_link;
        }
        num = temp->data;
        ad->next_link = temp->next_link;
        head = head->next_link;
        head->prev_link = NULL;
        free(temp);
        cout << num << " Deleted Succesfull" << endl;
    }
}

//Delete node at last node
void del_last_node()
{
    struct node *ad, *ad2;
    int num;
    ad = head;
    while (ad->next_link != head)
    {
        ad = ad->next_link;
    }
    num = ad->data;
    ad2 = ad->prev_link;
    ad2->next_link = head;
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
    ad2->next_link = ad3;
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
    // del_mid_node();
    // del_last_node();
    del_first_node();
    show_list();

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