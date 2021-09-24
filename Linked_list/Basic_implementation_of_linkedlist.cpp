#include<iostream>
using namespace std;

//defining 
struct node{
    int data;
    struct node *next;
};

int main(){
    //defining node variables
    struct node *first = NULL;
    struct node *second = NULL;
    struct node *third = NULL;
    struct node *forth = NULL;

    //allocating memory
    first = (struct node*)malloc(sizeof(struct node));
    second = (struct node*)malloc(sizeof(struct node));
    third = (struct node*)malloc(sizeof(struct node));
    forth = (struct node*)malloc(sizeof(struct node));

    //assigning data
    first->data = 45;
    second->data = 46;
    third->data = 47;
    forth->data = 48;

    //linking them
    first->next = second;
    second->next = third;
    third->next = forth;
    forth->next = NULL;

    //printing data
    cout<<first->data<<" -> "<<second->data<<" -> "<<third->data<<" -> "<<forth->data<<" -> NULL ";

    return 0;
}

/*
output
45 -> 46 -> 47 -> 48 -> NULL 
*/