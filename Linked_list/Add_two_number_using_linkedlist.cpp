#include <iostream>
using namespace std;
/*
You are given two non-empty linked lists representing two non-negative integers.
The digits are stored in reverse order, and each of their nodes contains a single digit.
Add the two numbers and return the sum as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.


Sample test case
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.



IDEA
we are creating 2 non empty lists assigning a single digit to every node.
we are joing every digit to make a whole digit(doing from both list).
example from list 1 -> 2,4,3 = 243, list 2 -> 4,6,5 = 465;
we add them and save it's result in a variable let it's name be var1
then we are spliting the digit into single digit and storing it into the linked list.
*/

struct node
{
    int num;
    struct node *next;
};

struct node *head_l1, *head_l2, *head_l3;

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
    cout << "[";
    while (ad != NULL)
    {
        cout << ad->num;
        ad = ad->next;

        if (ad != NULL)
        {
            cout << ",";
        }
    }
    cout << "]";
}

/*function which returns the whole number
it merges the numbers we are calling by address*/
void merge_number(int *res, int *res2)
{
    struct node *ad, *ad2;
    ad = head_l1;
    ad2 = head_l2;
    // int res = 0, res2 = 0;
    while (ad != NULL || ad2 != NULL)
    {
        *res = (*res * 10) + ad->num;
        *res2 = (*res2 * 10) + ad2->num;
        ad = ad->next;
        ad2 = ad2->next;
    }
}

int count_digit(int num)
{
    int i = 0;
    while (num != 0)
    {
        num = num / 10;
        i++;
    }
    return i;
}

int main()
{
    int num1 = 0, num2 = 0, num3 = 0;

    //--------------------------First list---------------------
    struct node *first_a;
    struct node *second_a;
    struct node *third_a;

    first_a = (struct node *)malloc(sizeof(struct node));
    second_a = (struct node *)malloc(sizeof(struct node));
    third_a = (struct node *)malloc(sizeof(struct node));

    first_a->num = 2;
    second_a->num = 4;
    third_a->num = 3;

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

    first_b->num = 5;
    second_b->num = 6;
    third_b->num = 4;

    first_b->next = second_b;
    second_b->next = third_b;
    third_b->next = NULL;

    head_l2 = first_b;

    //----------------------------getting whole number--------------------
    merge_number(&num1, &num2);

    num3 = num1 + num2;
    int n, m;
    n = count_digit(num3);
    for (int i = 0; i < n; i++)
    {
        m = num3 % 10;
        num3 = num3 / 10;
        insert_node_last(m);
    }
    show_list();
    return 0;
}

/*OUTPUT
7  0  8

note->it will note all test cases, because ,the code has limit of storing 3 digit only, but insertion has
no limit it calculates the number of digits and allocate and insert according to that.
*/