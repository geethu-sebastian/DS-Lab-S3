#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 10
int front=-1, rear=-1, queue[MAX_SIZE];
void enqueue(int data)
{
  if(rear==MAX_SIZE-1)
  printf("queue full\n");
  else
  {
   if(front==-1)
   {
    front=0;
   }
  rear=rear+1;
  queue[rear]=data;
  }
}
  

void dequeue()
{
  int d;
  if(front==-1)
  printf("Queue empty\n");
  else
  {
   d=queue[front];
   front=front+1;
   
   printf("Element deleted is %d\n",d);
   if(front>rear)
   front=rear=-1;
  }
}
void print()
{
  for(int i=front;i<=rear;i++)
  printf("%d\n",queue[i]);
}
int main()
{
  int choice,data;
  do
  {
    printf("MENU\n");
    printf("1.Enqueue\n");
    printf("2.Dequeue\n");
    printf("3.Display\n");
    printf("Enter your choice\n");
    scanf("%d",&choice);
    switch(choice)
    {
      case 1:
      {
        printf("Enter element to be inserted\n");
        scanf("%d",&data);
        enqueue(data);
        break;
      }
      case 2:
      {
        dequeue();
        break;
      }
      case 3:
      {
        print();
        break;
      }
      case 4:
      return 0;
      default:
      printf("Invalid choice");
    }
  }while(choice<5);
}