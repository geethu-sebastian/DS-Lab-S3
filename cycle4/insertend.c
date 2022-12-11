#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node*next;
};
struct Node *head=NULL;
void addnode(int data)
{   
    struct Node*newNode=malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->next=NULL;
    if(head==NULL)
    head=newNode;
    else
    {
      struct Node*temp=head;
      while(temp->next!=NULL)
      {
        temp=temp->next;
      }
      temp->next=newNode;
    }
}
int printlist()
{
    if(head==NULL)
    {
        printf("List empty");
    }
    struct Node*temp=head;
    while(temp!=NULL)
    {
        printf("%d\n",temp->data);
        temp=temp->next;
    }
}
int main()
{
    int choice,data;
    while(1)
    {
        printf("1.Add node\n");
        printf("2.Print list\n");
        printf("3.Exit\n");
        printf("Add your choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
        {
            printf("Enter data \n");
            scanf("%d",&data);
            addnode(data);
            break;
        }
        case 2:
        {
            printlist();
            break;
        }
        case 3:
        {
            return 0;
        }
        default:
        {
            printf("Invalid choice\n");
        }
        }
    }
}