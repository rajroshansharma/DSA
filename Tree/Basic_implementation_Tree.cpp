#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *root;

// showing the data
void preorder(struct node *root) // algorithm for traversing to the tree
{
    if (root != NULL)
    {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

int main()
{
    struct node *a;
    struct node *b;
    struct node *c;
    struct node *d;
    struct node *e;
    struct node *f;
    struct node *g;

    // allocating memory and assigning the pointers to NULL.
    a = (struct node *)malloc(sizeof(struct node));
    a->left = NULL;
    a->right = NULL;

    b = (struct node *)malloc(sizeof(struct node));
    b->left = NULL;
    b->right = NULL;

    c = (struct node *)malloc(sizeof(struct node));
    c->left = NULL;
    c->right = NULL;

    d = (struct node *)malloc(sizeof(struct node));
    d->left = NULL;
    d->right = NULL;

    e = (struct node *)malloc(sizeof(struct node));
    e->left = NULL;
    e->right = NULL;

    f = (struct node *)malloc(sizeof(struct node));
    f->left = NULL;
    f->right = NULL;

    g = (struct node *)malloc(sizeof(struct node));
    g->left = NULL;
    g->right = NULL;

    // assigning data
    a->data = 10;
    b->data = 20;
    c->data = 30;
    d->data = 40;
    e->data = 50;
    f->data = 60;
    g->data = 70;

    // linking the nodes in the form of tree
    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    c->left = f;
    c->right = g;

    root = a;

    preorder(root);

    return 0;
}