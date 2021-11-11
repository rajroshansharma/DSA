#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *new_node(int num)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->left = NULL;
    temp->right = NULL;
    temp->data = num;
    return temp;
}

struct node *insert(struct node *root, int num)
{
    if (root == NULL)
    {
        root = new_node(num);
    }
    else if (root->data <= num)
    {
        root->left = insert(root->left, num);
    }
    else
    {
        root->right = insert(root->right, num);
    }
    return root;
}

/*
IDEA
if there is no list given then return NULL
if there is element and is equal to the key then return that node(which is conting that key).
if there is element but not equal to the key then compare it to the present node data,
    if root data is less than key then move to left node and recurse.
    else move to right node and recurse (because root data is greater than the key)
*/

struct node *Search_in_tree(struct node *root, int key)
{
    if (root == NULL)
    {
        return NULL; // Search UnSuccesfull
    }
    else if (root->data == key)
    {
        return root; // Search succesfull
    }
    else if (root->data <= key)
    {
        return Search_in_tree(root->left, key); // move to left node
    }
    else
    {
        return Search_in_tree(root->right, key); // move to right node
    }
}

int main()
{
    struct node *root = NULL;
    struct node *temp = NULL;
    // Insertion
    root = insert(root, 8);
    root = insert(root, 3);
    root = insert(root, 10);
    root = insert(root, 1);
    root = insert(root, 14);
    root = insert(root, 4);
    root = insert(root, 7);

    // Searching

    temp = Search_in_tree(root, 1);
    if (temp == NULL)
    {
        cout << "Search Unsucesful! " << endl
             << "Element Not found";
    }
    else
    {
        cout << "Search Succesfull" << endl
             << "Element Found it";
    }

    return 0;
}

/*OUTPUT
INPUT - 9
OUTPUT
Search Unsucesful!
Element Not found

INPUT - 1
Search Succesfull
Element Found it
*/