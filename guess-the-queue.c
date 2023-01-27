//header files
#include<stdio.h>
#include<stdlib.h>

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
        printf("Queue is empty.\n");
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
        printf("Queue is empty.\n");
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

//driver code
int main() 
{
        int choice, data;
    for ( ; ; )
    {
        printf("1. Insert\n2. Delete\n3. Display\n4. Empty\n5. Overflow\n6. Exit");
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
            case 4: if (is_overflow()) {
                            printf("Queue is in Overflow state!\n");}
                    else {
                            printf("Overflow state -- NEGATIVE!\n");}
                        break;
            case 5: if (is_empty()) {
                            printf("Queue is in Underflow state!\n");}
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
