#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

//Inserting node at last.
void insert_node_last()
{
    struct node *temp;
    struct node *head_ref;
    head_ref = head;
    int num;
    cout << "Enter data : ";
    cin >> num;
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

//inserting node at first.
void insert_node_first()
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
}

//insert node after a  given postion.
void insert_in_middle(int n)
{
    struct node *temp, *head_ref;
    int num, pos;
    head_ref = head;
    //taking input
    cout << "Enter the position";
    cin >> pos;
    if (pos >= n) //checking if user is providing wrong index.
    {
        cout << "Invalid index.";
    }
    else
    {
        cout << "Enter data : ";
        cin >> num;
        //allocating memory

        temp = (struct node*)malloc(sizeof(struct node));
        temp ->next = NULL;
        temp->data = num;
        for (int i = 1; i < pos; i++)
        {
            head_ref = head_ref->next;
        }
        temp->next = head_ref->next;
        head_ref->next = temp; 
    }

   
}

//counts total number of nodes in a linked list.
int count_nodes()
{
    struct node *head_ref;
    int total = 1;
    head_ref = head;
    while (head_ref->next != NULL)
    {
        head_ref = head_ref->next;
        total++;
    }
    // cout<<"Total nodes :"<<total;
    return total;
}

//deletes the last node
void delete_last_node(){
    struct node *head_ref,*head_ref2;
    int num;
    head_ref = head->next;
    head_ref2 = head;
    while (head_ref->next!=NULL)
    {
        head_ref = head_ref->next; //pointing last data
        head_ref2 = head_ref2->next; //pointing last second data
    }
    //we can also for loop by counter.

    num = head_ref->data;

    head_ref2->next = NULL;
    free(head_ref);
    cout<<num<<" Deleted successfully"<<endl;
    
}

//deletes the node present at the first
void delete_first_node(){
    struct node *temp;
    int num;
    temp = head;
    head = head->next;
    //taking data for printing
    num = temp->data;
    free(temp);
    cout<<num<<" Deleted successfully"<<endl;

}

//deletes in the middle
void delete_mid_node(){
    struct node *head_ref,*head_ref2;
    int index,num;
    head_ref = head->next;
    head_ref2 = head;
    cout<<"Enter the index to be deleted : ";
    cin>>index;
    for (int i = 1; i <= index-1; i++)
    {
        head_ref = head_ref->next; //pointing after first data
        head_ref2 = head_ref2->next; //pointing first data
    }
    // cout<<head_ref->data<<endl<<head_ref2->data<<endl;
    num = head_ref2->data;
    head = head_ref;
    free(head_ref2);
    cout<<num<<" Deleted successfully"<<endl;
    
    
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
    int rel;
    //inserting node at last
    insert_node_last();
    insert_node_last();
    insert_node_last();

    //inserting node at first
    insert_node_first();
    insert_node_first();
    
    //inserting node at middle
    rel = count_nodes();  // count_nodes();
    insert_in_middle(rel);
    insert_in_middle(rel);

    //deleting first node 
    delete_first_node();

    //deleting specified node
    delete_mid_node();

    //printing the node's data
    show_list();
    
    //printing total number of nodes
    rel = count_nodes();
    cout<<endl<<"Total number of nodes are : "<<rel;
    
    return 0;
}


/*
Mark all check, we done
1. Insertion node at last
2. Insertion node at first
3. Insertion node at specified
4. Deletion node at first
5. Deletion node at last
6. Deletion node at specified
7. Printing all nodes
9. Counting total number of nodes
10. Traversing each and every node
*/
