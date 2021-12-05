#include <stdio.h>
#include <stdlib.h>

typedef struct node{
  int data;
  struct node *next;
}node;



node *create(){
  int val;
  node *start;
  printf("Enter a Value to Intialize your LL: ");
  scanf("%d", &val);
  start = (node *)malloc(sizeof(node));
  start->data = val;
  start->next = NULL;
  return start;
}

node *insertBeg(node *start, int value){
  node *ptr = (node *)malloc(sizeof(node));
  ptr -> next = start;
  ptr -> data = value;
  return ptr;
}

node *insertEnd(node *start, int value){
  node *ptr = (node *)malloc(sizeof(node));
  ptr -> data = value;
  node *p = start;
  while(p->next != NULL){
    p = p->next;
  }
  p->next = ptr;
  ptr->next = NULL;
  return start;
}

node *insertPosi(node *start,int value,int posi){
  int pos = 1;
  if(posi == 1){
    insertBeg(start,value);
  }
  node *ptr = (node *)malloc(sizeof(node));
  ptr->data = value;
  node *p = start;
  while(pos < posi-1){
    p = p->next;
    pos++;
  }
  ptr->next = p->next;
  p->next = ptr;
  return start;
}

node *deleteBeg(node *start){
  node *p = start;
  start = start->next;
  free(p);
  return start;
}

node *deleteEnd(node *start){
  node *p = start;
  node *p1 = start;
  while(p->next != NULL){
    p1 = p;
    p = p->next;
  }
  free(p);
  p1->next = NULL;
  return start;
}

node *deletePosi(node *start,int posi){
  node *p = start;
  int pos=1;
  while(pos < posi-2){
    p = p->next;
  }
  node *p1 = p->next;
  p->next = p1->next;
  free(p1);
  return start;
}

int count(node *start){
  int counter = 0;
  node *p = start;
  while(p != NULL){
    counter++;
    p = p->next;
  }
  printf("Linked List has %d elements.\n",counter);
  return counter;
}

node *SortLinkedList(node *start){
  int n,i,j,temp;
  node *p=start;
  node *q=start;
  n = count(start);
  for(i=0; i<n; i++){
    p=q=start;
    for(j=0; j<n-1; j++){
      q = q->next;
      if(p->data > q->data){
        temp = p->data;
        p->data = q->data;
        q->data = temp;
      }
      p = q;
    }
  }
  return start;
}

void DisplayLinkedList(node *p){
  printf("\nList is as follows:\n");
  if (p == NULL)
        printf("\nList is empty\n");
  else{
     while(p != NULL){
       printf("%d\t",p->data);
       p = p->next;
     }
     printf("\n");
    }
  }

void MeanofLL(node *start){
  float mean = 0;
  int n = count(start);
  node *p = start;
  while(p != NULL){
    mean = mean + p->data;
    p = p->next;
  }
  mean = (float)mean/n;
  printf("Mean of all elements of Linked List = %.4f", mean);
}

int main() {
  printf("Linked List Program\n");
  
  node *start = create();

  int isWorking = 1;
  while(isWorking){
    
    printf("\n1)Insert at Beginning\n2)Insert at End\n3)Insert at a Position\n4)Delete from Start\n5)Delete from End\n6)Delete from a Position\n7)Count\n8)Sort Linked List\n9)Display List\n10)Mean of all elements of LL\n11)Exit\n");
    printf("Enter your choice: ");
    int choice, value, position;
    scanf("%d", &choice);
    switch(choice){
      case 1:
        printf("Enter Value: ");
        scanf("%d", &value);
        start = insertBeg(start, value);
        break;
      case 2:
        printf("Enter Value: ");
        scanf("%d", &value);
        start = insertEnd(start, value);
        break;
      case 3:
        printf("Enter Value: ");
        scanf("%d", &value);
        printf("Enter Position: ");
        scanf("%d", &position);
        start = insertPosi(start,value, position);
        break;
      case 4:
        start = deleteBeg(start);
        break;
      case 5:
        start = deleteEnd(start);
        break;
      case 6:
        printf("Enter Position: ");
        scanf("%d", &position);
        start = deletePosi(start, position);
        break;
      case 7:
        count(start);
        break;
      case 8:
        start = SortLinkedList(start);
        break;
      case 9:
        DisplayLinkedList(start);
        break;
      case 10:
        MeanofLL(start);
        break;
      case 11:
        isWorking = 0;
        break;
      default:
        printf("\nEnter Correct Number\n");
        break;
    }
  }
  return 0;
}

