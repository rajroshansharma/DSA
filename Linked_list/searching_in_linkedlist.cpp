#include <iostream>
using namespace std;

/*IDEA
we are taking the data from the node and comparing it from the key.
if it is matched then search succesfull else search unsuccessful.
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

// search function
void search_for(int key)
{
    struct node *ad;
    ad = head;
    while (ad != NULL)
    {
        // cout << ad->data;
        if (key == ad->data)
        {
            cout << key << " found Succesfully.";
            return;
        }

        // cout << "->";
        ad = ad->next;
    }
    cout << key << " not found in list.";
}

int main()
{
    // inserting node first
    insert_node_last(52);
    insert_node_last(12);
    insert_node_last(20);
    insert_node_last(91);
    insert_node_last(14);

    // calling searching function
    search_for(9);

    return 0;
}

/*OUTPUT
91 found Succesfully.

9 not found in list.
*/