#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;          
    struct node *next; 
}*head;

void insertNodeAtBeginning(int data);

