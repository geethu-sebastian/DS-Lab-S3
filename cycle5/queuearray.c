#include <stdio.h>

#define MAX_SIZE 10

void enqueue(int queue[], int *front, int *rear, int value);
int dequeue(int queue[], int *front, int *rear);
int frontElement(int queue[], int front, int rear);
void printQueue(int queue[], int front, int rear);

int main(void) {
  int queue[MAX_SIZE];
  int front = -1, rear = -1;
  int choice, value;

  while (1) {
    printf("\nQueue Operations\n");
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Front Element\n");
    printf("4. Print Queue\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        printf("Enter the value to enqueue: ");
        scanf("%d", &value);
        enqueue(queue, &front, &rear, value);
        break;
      case 2:
        value = dequeue(queue, &front, &rear);
        if (value != -1) {
          printf("Dequeued element: %d\n", value);
        }
        break;
      case 3:
        value = frontElement(queue, front, rear);
        if (value != -1) {
          printf("Front element: %d\n", value);
        }
        break;
      case 4:
        printQueue(queue, front, rear);
        break;
      case 5:
        printf("Exiting...\n");
        return 0;
      default:
        printf("Invalid choice\n");
    }
  }

  return 0;
}

// Function to add an element to the queue
void enqueue(int queue[], int *front, int *rear, int value) {
  if (*rear == MAX_SIZE - 1) {
    printf("Error: Queue is full\n");
    return;
  }

  *rear = *rear + 1;
  queue[*rear] = value;
}

// Function to remove an element from the queue
int dequeue(int queue[], int *front, int *rear) {
  if (*front == *rear) {
    printf("Error: Queue is empty\n");
    return -1;
  }

  *front = *front + 1;
  return queue[*front];
}

// Function to get the front element of the queue
int frontElement(int queue[], int front, int rear) {
  if (front == rear) {
    printf("Error: Queue is empty\n");
    return -1;
  }

  return queue[front + 1];
}

// Function to print the elements of the queue
void printQueue(int queue[], int front, int rear) {
  if (front == rear) {
    printf("Queue is empty\n");
    return;
  }

  printf("Queue: ");
  for (int i = front + 1; i <= rear; i++) {
    printf("%d ", queue[i]);
  }
  printf("\n");
}

