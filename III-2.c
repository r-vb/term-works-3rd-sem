//header files
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

int queue1[MAX_SIZE], queue2[MAX_SIZE], queue3[MAX_SIZE];
int front1 = -1, rear1 = -1, front2 = -1, rear2 = -1, front3 = -1, rear3 = -1;

//insertion module.
void insert(int item) {
    if (rear1 == MAX_SIZE - 1) {
        printf("Queue Overflow\n");
        return;
    }
    if (front1 == -1) {
        front1 = 0;
    }
    rear1++;
    queue1[rear1] = item;
    printf("%d inserted into Queue 1\n", item);
}

//deletion module.
void delete() {
    if (front1 == -1) {
        printf("Queue Underflow\n");
        return;
    }
    int item = queue1[front1];
    printf("%d deleted from Queue 1\n", item);
    if (front1 == rear1) {
        front1 = rear1 = -1;
    } else {
        front1++;
    }
}

//display() module.
void display() {
    if (front1 == -1) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue 1: ");
    for (int i = front1; i <= rear1; i++) {
        printf("%d ", queue1[i]);
    }
    printf("\n");
    if (front2 == -1) {
        return;
    }
    printf("Queue 2: ");
    for (int i = front2; i <= rear2; i++) {
        printf("%d ", queue2[i]);
    }
    printf("\n");
    if (front3 == -1) {
        return;
    }
    printf("Queue 3: ");
    for (int i = front3; i <= rear3; i++) {
        printf("%d ", queue3[i]);
    }
    printf("\n");
}

//isEmpty checker fn.
int empty() {
    if (front1 == -1) {
        return 1;
    }
    return 0;
}

//isFull checker fn.
int overflow() {
    if (rear1 == MAX_SIZE - 1) {
        return 1;
    }
    return 0;
}

//driver code
int main() {
    int choice, item;
    while (1) {
        printf("\nPriority Queue Menu\n");
        printf("1. Insert\n2. Delete\n3. Display\n4. Check if Empty\n5. Check if Overflow\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) 
        {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &item);
                insert(item);
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                if (empty()) {
                    printf("Queue is empty\n");
                } else {
                    printf("Queue is not empty\n");
                }
                break;
            case 5:
                if (overflow()) {
                    printf("Queue is full\n");
                } else {
                    printf("Queue is not full\n");
                }
                break;
            case 6: exit(0);
            default:
                printf("Invalid choice\n");
                break;
        }
    }
    return 0;
}
