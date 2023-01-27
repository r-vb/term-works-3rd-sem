//header file
#include <stdio.h>

#define MAX 5

int queue[MAX], front = -1, rear = -1;

//fn. to insert an element into the queue
void insert(int data) {
    if((front == 0 && rear == MAX-1) || (front == rear+1)) {
        printf("Queue is overflow\n");
        return;
    }
    if(front == -1) {
        front = rear = 0;
    } else {
        if(rear == MAX-1) {
            rear = 0;
        } else {
            rear++;
        }
    }
    queue[rear] = data;
    printf("Inserted element: %d\n", data);
}

//fn. to delete an element from the queue
void delete() {
    if(front == -1) {
        printf("Queue is empty\n");
        return;
    }
    int data = queue[front];
    if(front == rear) {
        front = rear = -1;
    } else {
        if(front == MAX-1) {
            front = 0;
        } else {
            front++;
        }
    }
    printf("Deleted element: %d\n", data);
}

//f. to display the elements in the queue
void display() {
    if(front == -1) {
        printf("Queue is empty\n");
        return;
    }
    if(rear >= front) {
        for(int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
    } else {
        for(int i = front; i < MAX; i++) {
            printf("%d ", queue[i]);
        }
        for(int i = 0; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
    }
    printf("\n");
}

//fn. to check for empty condition of queue
int is_empty() {
    if(front == -1) {
        return 1;
    } else {
        return 0;
    }
}

//fn. to check for overflow condition of queue
int is_overflow() {
    if((front == 0 && rear == MAX-1) || (front == rear+1)) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    insert(1);
    insert(2);
    insert(3);
    insert(4);
    insert(5);
    insert(6);
    printf("Is overflow: %d\n", is_overflow());
    printf("Is empty: %d\n", is_empty());
    display();
    delete();
    delete();
    printf("Is overflow: %d\n", is_overflow());
    printf("Is empty: %d\n", is_empty());
    display();
    return 0;
}
