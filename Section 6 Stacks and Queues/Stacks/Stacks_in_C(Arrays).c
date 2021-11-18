#include <stdio.h>
#include<stdlib.h>
#define MAX 20

void push(int *p,int top){
  int x;
  printf("Enter a value to be pushed: ");
  scanf("%d",&x);
  p[top] = x;
}

void pop(int *p,int top){
  printf("\n%d is popped from stack",p[top-1]);
}

void peek(int *p,int top){
  printf("\nStack Order:\n");
  for(int i=top-1; i>=0; i--){
    printf("%d ",p[i]);
  }
  printf("\n");
}

int main(void) {
  int choice,*p,size;
  int top = 0;

  p = (int *)malloc(MAX*2);

  int isWorking = 1;

  while(isWorking){
    printf("\n1.Push Element\n2.Pop Element\n3.Display Stack\n4.Exit\nEnter Your Choice: ");
    scanf("%d",&choice);

    switch(choice){
      case 1:
        push(p, top);
        top++;
        break;

      case 2:
        pop(p, top);
        top--;
        break;

      case 3:
        peek(p, top);
        break;
      
      case 4:
        isWorking = 0;
        break;

      default:
      printf("Invalid Choice!!\n");
    }
  }

  printf("\nYour Final Stack is : ");
  peek(p, top);
  return 0;
}
