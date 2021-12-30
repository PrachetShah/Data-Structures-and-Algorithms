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

void Enqueue(Q *q, int value){
  node *ptr = (node *)malloc(sizeof(node));
  ptr->data = value;
  ptr->next = NULL;
  if(q->rear == NULL){
    q->front = q->rear =  ptr;
  }
  q->rear -> next = ptr;
  q->rear = ptr;
}

void Dequeue(Q *q){
  node *ptr;
  int x;
  if(q->front == NULL){
    printf("Underflow\n");
  }
  else{
    ptr = q->front;
    q->front = q->front->next;
    x = ptr->data;
    free(ptr);
    printf("%d is removed from Queue\n",x);
  }  
}

void displayQueue(Q *q){
  node *temp = q->front;
  while(temp != NULL){
    if(!temp->next)
      printf("%d", temp->data);
    else
      printf("%d -> ",temp->data);
    temp = temp->next;
  }
  printf("\n");
}

int main(void) {
  int isWorking = 1;
  int input, value;
  printf("Welcome to Menu Driven Queue Program:\n");
  while(isWorking){
    printf("\n1)Enqueue\n2)Dequeue\n3)Display Queue\n4)Exit\n");
    printf("\nEnter your Choice: ");
    scanf("%d", &input);
    switch(input){
      case 1:
        printf("Enter Value: ");
        scanf("%d", &value);
        Enqueue(&q, value);
        break;
      case 2:
        Dequeue(&q);        
        break;
      case 3:
        displayQueue(&q);
        break;
      case 4:
        isWorking = 0;
        break;
      default:
        printf("\nEnter Valid Option\n");
    }
  }
  return 0;
}
