#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *prev_link;
    struct node *next_link;
};

struct node *head = NULL;

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
         << "In Reversed order." << endl;
    while (head_ref != NULL)
    {
        cout << head_ref->data;
        cout << "->";
        head_ref = head_ref->prev_link;
    }
    cout << "NULL";
}

int main()
{
    insert_last();
    insert_last();
    insert_last();
    insert_last();
    show_list();
    show_rev_list();
    return 0;
}

/*OUTPUT
Enter the data :1Enter the data :2
Enter the data :3Enter the data :4
1->2->3->4->NULL
In Reversed order.
4->3->2->1->NULL
*/