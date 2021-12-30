#include <stdio.h>
#include<stdlib.h>

typedef struct node{
  int data;
  struct node *next;
}node;

typedef struct Q{
  node *front, *rear;
}Q;

Q q;

void EnqueueStart(Q *q, int value){
  node *ptr = (node *)malloc(sizeof(node));
  ptr->data = value;
  if(q->front == NULL){
    ptr->next = NULL;
    q->front = q->rear = ptr;
  }
  ptr->next = q->front;
  q->front = ptr;
}

void EnqueueEnd(Q *q, int value){
  node *ptr = (node *)malloc(sizeof(node));
  ptr->data = value;
  if(q->front == NULL){
    q->front = q->rear =  ptr;
  }
  else{
    q->rear->next = ptr;
    q->rear = ptr;
  }
}

int DequeueStart(Q *q){
  node *ptr;
  int x;
  if(q->front == NULL){
    printf("Underflow\n");
    return -1;
  }
  ptr = q->front;
  x = ptr->data;
  if(ptr->next != NULL){
    ptr->next = q->front->next;
    q->front = ptr->next;
    free(ptr);
    printf("%d is removed from Queue Start\n", x);
    return x;
  }
  else{
    free(ptr);
    q->front = q->rear = NULL;
    printf("%d is removed from Queue Start\n", x);
    return x;
  }
}

int DequeueEnd(Q *q){
  node *ptr = (node *)malloc(sizeof(node));
  int x;
  ptr = q->front;
  if(q->front == NULL){
    printf("Underflow\n");
    return -1;
  }
  if(q->front == q->rear){
    ptr = q->front;
    x = ptr->data;
    q->front = q->rear = NULL;
    free(ptr);
    printf("%d is removed from Queue End\n", x);
    return x;
  }
  else{
    while(ptr->next->next != NULL){
      ptr = ptr->next;
    }
    x = ptr->next->data;
    q->rear = ptr;
    ptr = ptr->next;
    free(ptr);
    printf("%d is removed from Queue End\n", x);
    return x;
  }  
}

void displayQueue(Q *q){
  node *ptr = q->front;
  if(q->front==NULL){
    printf("Empty Queue");
  }
  else{
    while(ptr!=NULL){
      printf("%d " , ptr->data);
      ptr=ptr->next;
    }
  }
  printf("\n");
}

int main(void) {
  int isWorking = 1;
  int input, value;
  printf("Welcome to Menu Driven Queue Program:\n");
  while(isWorking){
    printf("\n1)Enqueue Start\n2)Enqueue End\n3)Dequeue Start\n4)Dequeue End\n5)Display Queue\n6)Exit\n");
    printf("\nEnter your Choice: ");
    scanf("%d", &input);
    switch(input){
      case 1:
        printf("Enter Value: ");
        scanf("%d", &value);
        EnqueueStart(&q, value);
        break;
      case 2:
        printf("Enter Value: ");
        scanf("%d", &value);
        EnqueueEnd(&q, value);
        break;
      case 3:
        DequeueStart(&q);        
        break;
      case 4:
        DequeueEnd(&q);        
        break;
      case 5:
        displayQueue(&q);
        break;
      case 6:
        isWorking = 0;
        break;
      default:
        printf("\nEnter Valid Option\n");
    }
  }
  return 0;
}
