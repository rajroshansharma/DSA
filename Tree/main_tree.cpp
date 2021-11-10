#include <iostream>
using namespace std;

/*
Binary Search Tree in short(BST) also called n ordered or sorted binary tree.
where small numbers goes to the left subtree and largest number goes to right subtree.
Given [13,8,3,15,11] #Drawing with pen and paper
step 1: consider the first element as a root node.
        13
step 2: take another element and compare to the number from the root and then come to bootom
        if less then place at left (or move to left node & then compare to it)
        else place at right        (or move to right node & then compare to it)
        13
       /
      8           Since 8<13 then goese to left
step 3: repeat step 2 untill all numbers takes it's position
        13            3<13 move to left node
       /              3<8 move to left node
      8               if null place at left
     /
    3

        13           15>13 move to right node
       /  \          if null place at right
      8    15
     /
    3

        13           11<13 move to left node
       /  \          11>8 move to right node
      8    15        if null place at right
     / \
    3   11


*/

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

// Function which returns the address of newly created node
struct node *new_node(int num)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = num;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

// Function for inserting into the tree.
struct node *insert(struct node *root, int num)
{
    if (root == NULL)
    {                         // empty tree
        root = new_node(num); // base case
    }
    // if data to be inserted is lesser, insert in left subtree.
    else if (num <= root->data)
    {
        root->left = insert(root->left, num);
    }
    // else, insert in right subtree.
    else
    {
        root->right = insert(root->right, num);
    }
    return root;
}

// Prints all the data present in the list
void preorder(struct node *root) // algorithm for traversing to the tree
{
    if (root != NULL)
    {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

// Driver Code
int main()
{
    struct node *root = NULL;
    root = insert(root, 8);
    root = insert(root, 3);
    root = insert(root, 10);
    root = insert(root, 1);
    root = insert(root, 14);
    root = insert(root, 4);
    root = insert(root, 7);

    cout << "Prepared tree is : " << endl;
    preorder(root);
    return 0;
}

/*
OUTPUT
Prepared tree is :
8 3 1 4 7 10 14
*/

/*
FOR OWNER ONLY!!!
1. when new node is created then root is a new variable and a tree is created which consists
   only one node , then we insert into the tree.
   it is destoryed when that call is poped out from the stack ,Since it is tempory variable
   but at last it returns the original root variable
2. we want to take action on the left or right part of the node ,thats why
   we are inserting into root's left or right.
*/