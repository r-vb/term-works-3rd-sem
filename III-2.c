#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10

int front[3] = {-1, -1, -1};
int rear[3] = {-1, -1, -1};
int queue[MAX_SIZE];

void insert(int element, int priority) {
    if (rear[priority] == MAX_SIZE - 1) {
        printf("Overflow\n");
        return;
    }
    if (front[priority] == -1) {
        front[priority] = 0;
    }
    rear[priority]++;
    queue[rear[priority]] = element;
}

void delete() {
    if (front[0] == -1 && front[1] == -1 && front[2] == -1) {
        printf("Underflow\n");
        return;
    }
    if (front[0] != -1) {
        printf("Deleted element is %d\n", queue[front[0]]);
        front[0]++;
        if (front[0] > rear[0]) {
            front[0] = rear[0] = -1;
        }
    } else if (front[1] != -1) {
        printf("Deleted element is %d\n", queue[front[1]]);
        front[1]++;
        if (front[1] > rear[1]) {
            front[1] = rear[1] = -1;
        }
    } else {
        printf("Deleted element is %d\n", queue[front[2]]);
        front[2]++;
        if (front[2] > rear[2]) {
            front[2] = rear[2] = -1;
        }
    }
}

void display() {
    if (front[0] == -1 && front[1] == -1 && front[2] == -1) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements are:\n");
    for (int i = 2; i >= 0; i--) {
        printf("Priority %d: ", i+1);
        for (int j = front[i]; j <= rear[i]; j++) {
            printf("%d ", queue[j]);
        }
        printf("\n");
    }
}

int empty() {
    if (front[0] == -1 && front[1] == -1 && front[2] == -1) {
        return 1;
    }
    return 0;
}

int overflow() {
    if (rear[0] == MAX_SIZE - 1 && rear[1] == MAX_SIZE - 1 && rear[2] == MAX_SIZE - 1) {
        return 1;
    }
    return 0;
}

int main() {
    int choice, element, priority;

    for ( ; ; ) {
        printf("1.Insert\n2.Delete\n3.Display\n4.Empty\n5.Overflow\n6.Exit\n");
        printf("Enter your choice:");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to insert:");
                scanf("%d", &element);
                printf("Enter the priority:");
                scanf("%d", &priority);
                insert(element, priority-1);
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