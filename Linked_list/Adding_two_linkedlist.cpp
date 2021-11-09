
#include <iostream>
using namespace std;

/*adding two linked list and storing it into another linked list
list 1 = 10, 20, 30
list 2 = 40, 50, 60
Expected output = 50, 70, 90
Expalnation 10+40 = 50, 20+50 = 70, 30+60 = 90
*/

struct node
{
    int num;
    struct node *next;
};

struct node *head_l1, *head_l2, *head_l3;
void insert_node_last(int data);

// function for adding two linked list
void add_two_list()
{
    int m;
    struct node *ad, *ad2;
    ad = head_l1;
    ad2 = head_l2;
    while (ad != NULL || ad2 != NULL)
    {
        m = ad->num + ad2->num;
        insert_node_last(m);
        ad = ad->next;
        ad2 = ad2->next;
    }
}

// Inserting node at last.
void insert_node_last(int data)
{
    struct node *temp;
    struct node *head_ref;
    head_ref = head_l3;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->next = NULL;
    temp->num = data;
    if (head_l3 == NULL)
    {
        head_l3 = temp; // checking if there is not a single element.
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

// prints the data present in the list
void show_list()
{
    struct node *ad;
    ad = head_l3;

    while (ad != NULL)
    {
        cout << ad->num;
        ad = ad->next;
        cout << " ";
    }
}

int main()
{
    //--------------------------First list---------------------
    struct node *first_a;
    struct node *second_a;
    struct node *third_a;

    first_a = (struct node *)malloc(sizeof(struct node));
    second_a = (struct node *)malloc(sizeof(struct node));
    third_a = (struct node *)malloc(sizeof(struct node));

    first_a->num = 10;
    second_a->num = 20;
    third_a->num = 30;

    first_a->next = second_a;
    second_a->next = third_a;
    third_a->next = NULL;

    head_l1 = first_a;

    //--------------------------Second list---------------------

    struct node *first_b;
    struct node *second_b;
    struct node *third_b;

    first_b = (struct node *)malloc(sizeof(struct node));
    second_b = (struct node *)malloc(sizeof(struct node));
    third_b = (struct node *)malloc(sizeof(struct node));

    first_b->num = 40;
    second_b->num = 50;
    third_b->num = 60;

    first_b->next = second_b;
    second_b->next = third_b;
    third_b->next = NULL;

    head_l2 = first_b;
    add_two_list();
    show_list();
    return 0;
}

/*
OUTPUT
50 70 90
*/