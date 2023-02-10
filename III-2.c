#include <stdio.h>
#include <stdlib.h>

#define MAX 10

struct Queue {
  int front, rear;
  int items[MAX];
};

struct PriorityQueue {
  struct Queue q1, q2, q3;
};

void init(struct Queue *q) {
  q->front = q->rear = -1;
}

int isEmpty(struct Queue q) {
  return q.front == -1;
}

int isFull(struct Queue q) {
  return q.rear == MAX - 1;
}

void enqueue(struct Queue *q, int item) {
  if (isFull(*q)) {
    printf("Queue Overflow\n");
    return;
  }
  q->items[++q->rear] = item;
  if (q->front == -1)
    q->front = q->rear;
}

int dequeue(struct Queue *q) {
  int item;
  if (isEmpty(*q)) {
    printf("Queue Underflow\n");
    return -1;
  }
  item = q->items[q->front++];
  if (q->front > q->rear) {
    q->front = q->rear = -1;
  }
  return item;
}

void insert(struct PriorityQueue *pq, int item, int priority) {
  switch (priority) {
    case 1:
      enqueue(&pq->q1, item);
      break;
    case 2:
      enqueue(&pq->q2, item);
      break;
    case 3:
      enqueue(&pq->q3, item);
      break;
    default:
      printf("Invalid priority\n");
  }
}

int delete(struct PriorityQueue *pq) {
  if (!isEmpty(pq->q1))
    return dequeue(&pq->q1);
  else if (!isEmpty(pq->q2))
    return dequeue(&pq->q2);
  else if (!isEmpty(pq->q3))
    return dequeue(&pq->q3);
  else {
    printf("Queue is Empty\n");
    return -1;
  }
}

void display(struct PriorityQueue pq) {
  int i;
  if (isEmpty(pq.q1))
    printf("Queue 1 is Empty\n");
  else {
    printf("Queue 1: ");
    for (i = pq.q1.front; i <= pq.q1.rear; i++)
      printf("%d ", pq.q1.items[i]);
    printf("\n");
  }
  if (isEmpty(pq.q2))
    printf("Queue 2 is Empty\n");
  else {
    printf("Queue 2: ");
    for (i = pq.q2.front; i <= pq.q2.rear; i++)
      printf("%d ", pq.q2.items[i]);
    printf("\n");
  }
  if (isEmpty(pq.q3))
    printf("Queue 3 is Empty\n");
  else {
    printf("Queue 3: ");
    for (i = pq.q3.front; i <= pq.q3.rear; i++)
      printf("%d ", pq.q3.items[i]);
    printf("\n");
  }
}
