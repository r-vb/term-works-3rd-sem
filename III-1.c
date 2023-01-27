//header files
#include<stdio.h>
#include<stdlib.h>

#define SIZE 5

int items[SIZE];
int front = -1, rear = -1;

//check overflow condition for queue
int overflow() {
  if ((front == rear + 1) || (front == 0 && rear == SIZE - 1)) return 1;
  return 0;
}

//check empty condition for queue
int empty() {
  if (front == -1) return 1;
  return 0;
}

//inserting an element
void insert(int element) {
  if (overflow())
    printf("Queue is full!!\n");
  else {
    if (front == -1) front = 0;
    rear = (rear + 1) % SIZE;
    items[rear] = element;
    printf("\n Inserted -> %d", element);
  }
}

//deleting an element
int delete() {
  int element;
  if (empty()) {
    printf("Queue is empty!!\n");
    return (-1);
  } else {
    element = items[front];
    if (front == rear) {
      front = -1;
      rear = -1;
    } 
//queue has only one element, so we can reset the queue after dequeing it.
    else {
      front = (front + 1) % SIZE;
    }
    printf("Deleted element:-- (%d)\n", element);
    return (element);
  }
}

// Display of the queue
void display() {
  int i;
  if (empty())
    printf("Empty Queue\n");
  else {
    printf("Front index: %d ", front);
    printf("Items -) ");
    for (i = front; i != rear; i = (i + 1) % SIZE) {
      printf("%d ", items[i]);
    }
    printf("%d ", items[i]);
    printf("\n Rear index: %d \n", rear);
  }
}

//driver code
int main() 
{
        int choice, data;
    for ( ; ; )
    {
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Overflow\n5. Empty\n6. Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch (choice) {
            case 1: printf("Enter data: ");
                    scanf("%d",&data);
                    insert(data);
                    break;
            case 2: delete();
                    break;
            case 3: display();
                    break;
            case 4: if (overflow()) {
                            printf("CircularQueue is in Overflow state!\n");}
                    else {
                            printf("Overflow state -- NEGATIVE!\n");}
                        break;
            case 5: if (empty()) {
                            printf("CircularQueue is in Underflow state!\n");}
                    else {
                            printf("Underflow state -- NEGATIVE!\n");}
                        break;
            case 6: exit(-1);
            default: printf("Invalid Input!!\n");
                    break;
        }
    }
return 0;
}