#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the linked list
struct Node {
  int data;
  struct Node *next;
};

// Structure to represent the queue
struct Queue {
  struct Node *front;
  struct Node *rear;
};

// Function prototypes
void enqueue(struct Queue *queue, int value);
int dequeue(struct Queue *queue);
int frontElement(struct Queue *queue);
void printQueue(struct Queue *queue);

int main(void) {
  struct Queue queue;
  queue.front = NULL;
  queue.rear = NULL;
  int choice, value;

  while (1) {
    printf("\nQueue Operations\n");
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Print Queue\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        printf("Enter the value to enqueue: ");
        scanf("%d", &value);
        enqueue(&queue, value);
        break;
      case 2:
        value = dequeue(&queue);
        if (value != -1) {
          printf("Dequeued element: %d\n", value);
        }
        break;
      case 3:
        printQueue(&queue);
        break;
      case 4:
        printf("Exiting...\n");
        return 0;
      default:
        printf("Invalid choice\n");
    }
  }

  return 0;
}

// Function
void enqueue(struct Queue *queue, int value) {
  struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
  newNode->data = value;
  newNode->next = NULL;

  if (queue->rear == NULL) {
    queue->front = queue->rear = newNode;
    return;
  }

  queue->rear->next = newNode;
  queue->rear = newNode;
}

int dequeue(struct Queue *queue) {
  if (queue->front == NULL) {
    printf("Error: Queue is empty\n");
    return -1;
  }

  struct Node *temp = queue->front;
  int value = temp->data;
  queue->front = queue->front->next;

  if (queue->front == NULL) {
    queue->rear = NULL;
  }

  free(temp);

  return value;
}

void printQueue(struct Queue *queue) {
  if (queue->front == NULL) {
    printf("Queue is empty\n");
    return;
  }

  printf("Queue: ");
  struct Node *current = queue->front;
  while (current != NULL) {
    printf("%d ", current->data);
    current = current->next;
  }
  printf("\n");
}
