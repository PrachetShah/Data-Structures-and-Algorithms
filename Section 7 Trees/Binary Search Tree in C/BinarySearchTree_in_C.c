#include<stdio.h>
#include<stdlib.h>

typedef struct node{
  struct node *left, *right;
  int data;
}node;

node *createTree(){
  node *p;
  int val;
  printf("Enter Root Value. Enter -1 for NULL : ");
  scanf("%d",&val);
  if(val == -1)
    return NULL;
  p = (node*)malloc(sizeof(node));
  p->data = val;
  printf("Enter left child of %d:\n",val);
  p->left = createTree();

  printf("Enter right child of %d:\n",val);
  p->right = createTree();
  return p;
}

node *insertElement(node *root, int val){
  node *ptr = (node *)malloc(sizeof(node));
  
  if(root == NULL){
    ptr->data = val;
    ptr->right = ptr->left = NULL;
    return ptr;
  }
    
  if(val < root->data)
    root->left = insertElement(root->left, val);
  else if(val > root->data)
    root->right = insertElement(root->right, val);
  
  return root;
}

int findMax(node *root){
  while(root->right != NULL)
      root = root->right;
  return root->data;
}

int findMin(node *root){
  while(root->left != NULL)
    root = root->left;
  return root->data;
}

void inOrderDisplay(node *T){
  if(T != NULL){
    inOrderDisplay(T->left);
    printf("%d\t", T->data);
    inOrderDisplay(T->right);
  }
}

int main() {
  int isWorking = 1;
  int input, output;
  printf("Menu Driven Binary Search Tree Program\n\nLet's Intialise the Tree First\n");

  node *root = createTree();

  while(isWorking){
    printf("\n1)Insert Element\n2)Find Max Element\n3)Find Min Element\n4)In-Order Traversal\n5)Exit\n");
    printf("Enter Choice: ");
    scanf("%d", &input);
    switch(input){
      case 1:
        printf("Enter element to be inserted: ");
        scanf("%d", &input);
        insertElement(root, input);
        printf("In-Order Traversal of Tree: ");
        inOrderDisplay(root);
        printf("\n");
        break;
      case 2:
        output = findMax(root);
        printf("Binary Search Tree has Max Value of %d \n", output);
        break;
      case 3:
        output = findMin(root);
        printf("Binary Search Tree has Min Value of %d \n", output);
        break;
      case 4:
        printf("In-Order Traversal: ");
        inOrderDisplay(root);
        printf("\n");
        break;
      case 5:
        isWorking = 0;
        break;
      default:
        printf("Enter a Valid Option\n");
    }
  }
  return 0;
}
