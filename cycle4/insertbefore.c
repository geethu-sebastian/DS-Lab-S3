#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *next;
};

struct node *head = NULL;


void insertNode(int data, int before) {
  
  struct node *newNode = malloc(sizeof(struct node));

 
  newNode->data = data;
  newNode->next = NULL;

  
  if (head == NULL) {
    head = newNode;
  } 
  else if(head->data==before){
    
        newNode->next=head;
        head=newNode;
    
  }
    else {
    struct node *temp = head;
    while (temp->next != NULL && temp->next->data != before) {
      temp = temp->next;
    }

    
    if (temp->next == NULL) {
      printf("Node not found\n");
    } else {
      
      newNode->next = temp->next;
      temp->next = newNode;
    }
  }
}

int main() {
  int choice, data, before;

  while (1) {
    
    printf("1. Insert node\n");
    printf("2. Print linked list\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1: 
        printf("Enter the data for the new node: ");
        scanf("%d", &data);
        printf("Enter the data of the node before which the new node will be inserted: ");
        scanf("%d", &before);
        insertNode(data, before);
        break;

      case 2: 
        if (head == NULL) {
          printf("Linked list is empty\n");
        } else {
          
          struct node *temp = head;
          while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
          }
          printf("\n");
        }
        break;

      case 3: 
        return 0;

      default:
        printf("Invalid choice\n");
        break;
    }
  }

  return 0;
}
