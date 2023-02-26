//header files.
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

//new Node creation module.
struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtFront(struct node** headRef, int data) {
    struct node* newNode = createNode(data);
    newNode->next = *headRef;
    *headRef = newNode;
}

void insertBefore(struct node** headRef, int key, int data) {
    struct node* newNode = createNode(data);
    struct node* current = *headRef;
    struct node* prev = NULL;

    while (current != NULL && current->data != key) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Key not found\n");
        free(newNode);
        return;
    }

    if (prev == NULL) {
        newNode->next = *headRef;
        *headRef = newNode;
    } else {
        prev->next = newNode;
        newNode->next = current;
    }
}

void deleteAtRear(struct node** headRef) {
    if (*headRef == NULL) {
        printf("List is empty\n");
        return;
    }

    struct node* current = *headRef;
    struct node* prev = NULL;

    while (current->next != NULL) {
        prev = current;
        current = current->next;
    }

    if (prev == NULL) {
        *headRef = NULL;
    } else {
        prev->next = NULL;
    }

    free(current);
}

//display module.
void displayList(struct node* head) {
    struct node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

//driver code.
int main() {
    struct node* head = NULL;
    int choice, data, key;

    for ( ; ; )
    {
        printf("\nChoose an operation--\n");
        printf("1. Insert@front\n");
        printf("2. Insert before a key element\n");
        printf("3. Delete@rear\n");
        printf("4. Display the list\n");
        printf("5. Exit\n");
        printf("Your choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                printf("Enter the data to insert: ");
                scanf("%d", &data);
                insertAtFront(&head, data);
                printf("Inserted %d at front.\n", data);
                break;

            case 2:
                printf("Enter the key element: ");
                scanf("%d", &key);
                printf("Enter the data to insert: ");
                scanf("%d", &data);
                insertBefore(&head, key, data);
                printf("Inserted %d before %d.\n", data, key);
                break;

            case 3:
                deleteAtRear(&head);
                printf("Deleted the rear element.\n");
                break;

            case 4:
                printf("The list is: ");
                displayList(head);
                break;

            case 5:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    }
return 0;
}
