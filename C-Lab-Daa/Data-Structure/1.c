// create a linked list
#include<stdio.h>

struct node{
    int data;
    struct node *next;
};

void node (struct node *head){
    struct node *ptr;
    ptr = head;
    while(ptr != NULL){
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }
}
