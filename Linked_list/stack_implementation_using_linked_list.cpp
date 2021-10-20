#include <iostream>
using namespace std;

/*
In stack we add element from top(first) and delete from top(first).
*/

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

//inserting node at first.
void push()
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
    cout << num << " Pushed successfully" << endl;
}

//deletes the node present at the first
void pop()
{
    struct node *temp;
    int num;
    temp = head;
    head = head->next;
    //taking data for printing
    num = temp->data;
    free(temp);
    cout << num << " Poped successfully" << endl;
}

void peep()
{
    cout << head->data;
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
    cout << "NULL";
}

int main()
{
    push();
    push();
    push();
    push();
    pop();
    push();
    pop();
    pop();
    show_list();

    return 0;
}

/*
OUTPUT

Enter data : 1
1 Pushed successfully
Enter data : 2
2 Pushed successfully
Enter data : 3
3 Pushed successfully
Enter data : 4
4 Pushed successfully
4 Poped successfully
Enter data : 5
5 Pushed successfully
5 Poped successfully
3 Poped successfully
2->1->NULL

*/