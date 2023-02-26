//header files
#include<stdio.h>
#include<stdlib.h>

// Define the structure of a node in doubly linked list
struct Node {
   int data;
   struct Node* prev;
   struct Node* next;
};

// Function to create a new node in doubly linked list
struct Node* createNode(int data) {
   struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
   newNode->data = data;
   newNode->prev = NULL;
   newNode->next = NULL;
   return newNode;
}

// Function to insert a new node at the end of the doubly linked list
struct Node* insertAtEnd(struct Node* head, int data) 
{
   struct Node* newNode = createNode(data);
   if(head == NULL) {
      head = newNode;
   } else {
      struct Node* temp = head;
      while(temp->next != NULL) {
         temp = temp->next;
      }
      temp->next = newNode;
      newNode->prev = temp;
   }
   return head;
}

// Function to search for a key element in the doubly linked list
void searchAndAppend(struct Node* head, int key) 
{
   int pos = 0;
   struct Node* temp = head;
   while(temp != NULL) {
      pos++;
      if(temp->data == key) {
         printf("Key element found at position %d\n", pos);
         // Append the key element at the end of the list
         head = insertAtEnd(head, key);
         printf("Key element appended at the end of the list\n");
         return;
      }
      temp = temp->next;
   }
   printf("Key element not found in the list\n");
}

// Function to display the contents of the doubly linked list
void display(struct Node* head) 
{
   struct Node* temp = head;
   printf("Doubly linked list: ");
   while(temp != NULL) {
      printf("%d ", temp->data);
      temp = temp->next;
   }
   printf("\n");
}

//driver code
int main() 
{
   struct Node* head = NULL;
   int n, data, key;
   
   // Create the doubly linked list
   printf("Enter the number of nodes: ");
   scanf("%d", &n);
   printf("Enter the data for each node:\n");
   for(int i = 0; i < n; i++) {
      scanf("%d", &data);
      head = insertAtEnd(head, data);
   }
   
   // Search for a key element and append it at the end of the list if found
   printf("Enter the key element to be searched: ");
   scanf("%d", &key);
   searchAndAppend(head, key);
   
   // Display the contents of the doubly linked list
   display(head);
return 0;
}