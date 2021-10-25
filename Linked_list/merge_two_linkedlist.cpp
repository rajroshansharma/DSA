#include <iostream>
using namespace std;

/*
Idea
Firstly we are creating two linked list manually just to understand the merging concept.
then we are using two pointers which are pointing to the two lists and using loop it
is returning the data present in the node and then handing it over to insert_node_last()
function for allocating a memory and assigning the element.
*/

struct merge_two_linkedlist
{
    int num;
    struct merge_two_linkedlist *next;
};

struct list_one
{
    int num;
    struct list_one *next;
};

struct list_two
{
    int num;
    struct list_two *next;
};

// Head
struct merge_two_linkedlist *head_res = NULL;
struct list_one *head_a = NULL;
struct list_two *head_b = NULL;

// Printing all the data
void show_list()
{
    struct merge_two_linkedlist *ad;
    ad = head_res;
    while (ad != NULL)
    {
        cout << ad->num;
        cout << "->";
        ad = ad->next;
    }
    cout << "NULL";
}

void insert_node_last(int data)
{
    struct merge_two_linkedlist *temp;
    struct merge_two_linkedlist *head_ref;
    head_ref = head_res;
    temp = (struct merge_two_linkedlist *)malloc(sizeof(struct merge_two_linkedlist));
    temp->next = NULL;
    temp->num = data;
    if (head_res == NULL)
    {
        head_res = temp; // checking if there is not a single element.
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

int main()
{
    struct list_one *var_one;
    struct list_two *var_two;
    struct merge_two_linkedlist *temp;
    struct merge_two_linkedlist *head_ref;

    int temp_data;
    // creating 3 node list
    struct list_one *first_a;
    struct list_one *second_a;
    struct list_one *third_a;

    first_a = (struct list_one *)malloc(sizeof(struct list_one));
    second_a = (struct list_one *)malloc(sizeof(struct list_one));
    third_a = (struct list_one *)malloc(sizeof(struct list_one));

    first_a->num = 10;
    second_a->num = 20;
    third_a->num = 30;

    first_a->next = second_a;
    second_a->next = third_a;
    third_a->next = NULL;

    head_a = first_a;

    // creating 3 node list
    struct list_two *first_b;
    struct list_two *second_b;
    struct list_two *third_b;

    first_b = (struct list_two *)malloc(sizeof(struct list_two));
    second_b = (struct list_two *)malloc(sizeof(struct list_two));
    third_b = (struct list_two *)malloc(sizeof(struct list_two));

    first_b->num = 40;
    second_b->num = 50;
    third_b->num = 60;

    first_b->next = second_b;
    second_b->next = third_b;
    third_b->next = NULL;

    head_b = first_b;

    // merging part
    var_one = head_a;
    var_two = head_b;
    do
    {
        temp_data = var_one->num;
        insert_node_last(temp_data);
        var_one = var_one->next;
    } while (var_one != NULL);

    // merging second list.

    do
    {
        temp_data = var_two->num;
        insert_node_last(temp_data);
        var_two = var_two->next;
    } while (var_two != NULL);

    show_list();

    return 0;
}

/*
OUTPUT
10->20->30->40->50->60->NULL
*/