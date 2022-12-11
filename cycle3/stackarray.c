#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 10
int stack[MAX_SIZE],top=-1;
void push(int data)
{
    if(top==MAX_SIZE-1)
    printf("Stack overflow\n");
    else
    stack[++top]=data;
}
void pop()
{
    int d;
    if(top==-1)
    printf("Stack underflow\n");
    else
    {
      d=stack[top--];
      printf("Deleted element is %d\n",d);
    }
}
void print()
{
    for(int i=0;i<top;i++)
    printf("%d\n",stack[i]);
}

int main()
{
    int data,choice;
   do
   {
    printf("MENU\n");
    printf("1.Push\n");
    printf("2.Pop\n");
    printf("3.Display\n");
    printf("4.Exit\n");
    printf("Enter your choice\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
        {
            printf("Enter data to be pushed\n");
            scanf("%d",&data);
            push(data);
            break;
        }
        case 2:
        {
           pop();
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
        printf("Invalid input\n");
    }
   }while(choice<5);
}