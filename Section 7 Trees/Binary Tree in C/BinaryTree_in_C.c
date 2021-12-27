#include <stdio.h>
#include<stdlib.h>

typedef struct node{
  struct node *left, *right;
  int data;
}node;

int node_counter = 0, leaf_counter = 0, degree1_counter = 0, degree2_counter = 0;


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

int countNodes(node *root){
  if(root == NULL)
    return 0;
  
  node_counter++;
  countNodes(root->left);
  countNodes(root->right);
  return node_counter;
}

int countLeaf(node *root){
  if(root==NULL)
    return 0;

  if(root->left == NULL && root->right == NULL)
    leaf_counter++;
  countLeaf(root->left);
  countLeaf(root->right);
  return leaf_counter;
}

int countDegree1(node *root){
  if(root==NULL)
    return 0;
  
  if((root->left==NULL && root->right) || (root->left && root->right==NULL))
    degree1_counter++;
  
  countDegree1(root->left);
  countDegree1(root->right);
  return degree1_counter;
}

int countDegree2(node *root){
  if(root==NULL)
    return 0;
  
  if(root->left && root->right)
    degree2_counter++;
  
  countDegree2(root->left);
  countDegree2(root->right);
  return degree2_counter;
}

node *copyTree(node *root){
  if(root == NULL)
    return root;
  
  node *temp = (node *)malloc(sizeof(node));
  temp->data = root->data;
  temp->left = copyTree(root->left);
  temp->right = copyTree(root->right);
  return temp;
}

node *mirrorTree(node *root){
  if(root == NULL)
    return root;
  
  node *temp, *mirror=root;
  mirrorTree(mirror->left);
  mirrorTree(mirror->right);
  temp = mirror->left;
  mirror->left = mirror->right;
  mirror->right = temp;
  return mirror;
}

int heightTree(node *root){
  int lheight, rheight;
  if(root == NULL)
    return 0;

  lheight = heightTree(root->left);
  rheight = heightTree(root->right);
  if(lheight > rheight)
    return lheight+1;
  return rheight+1;
}

void preOrderDisplay(node *T){
  if(T == NULL)
    return;  
  printf("%d\t", T->data);
  preOrderDisplay(T->left);
  preOrderDisplay(T->right);
}

void inOrderDisplay(node *T){
  if(T != NULL){
    inOrderDisplay(T->left);
    printf("%d\t", T->data);
    inOrderDisplay(T->right);
  }
}

void postOrderDisplay(node *T){
  if(T != NULL){
    postOrderDisplay(T->left);
    postOrderDisplay(T->right);
    printf("%d\t", T->data);
  }
}

int main() {
  int isWorking = 1;
  int input, output;
  node *copy, *mirror;
  printf("Menu Driven Binary Tree Program\n\nLet's Intialise the Tree First\n");

  node *root = createTree();

  while(isWorking){
    printf("\n1)Count Nodes\n2)Count Leaf\n3)Count Degree 1\n4)Count Degree 2\n5)Copy Tree\n6)Mirror Tree\n7)Height of Tree\n8)Pre-Order Traversal\n9)In-Order Traversal\n10)Post-Order Traversal\n11)Exit\n");
    printf("Enter Choice: ");
    scanf("%d", &input);
    switch(input){
      case 1:
        output = countNodes(root);
        printf("Binary Tree has %d Nodes\n", output);
        break;
      case 2:
        output = countLeaf(root);
        printf("Binary Tree has %d Leaf Nodes\n", output);
        break;
      case 3:
        output = countDegree1(root);
        printf("Binary Tree has %d Degree 1 Nodes\n", output);
        break;
      case 4:
        output = countDegree2(root);
        printf("Binary Tree has %d Degree 2 Nodes\n", output);
        break;
      case 5:
        copy = copyTree(root);
        printf("Tree has been copied. Its Pre-Order Traversal is: \n");
        preOrderDisplay(copy);
        printf("\n");
        break;
      case 6:
        mirror = mirrorTree(root);
        printf("Mirror Tree In-Order Traversal is:\n");
        inOrderDisplay(mirror);
        printf("\n");
        break;
      case 7:
        output = heightTree(root);
        printf("Height of Binary Tree is %d\n", output);
        break;
      case 8:
        printf("Pre-Order Traversal: ");
        preOrderDisplay(root);
        printf("\n");
        break;
      case 9:
        printf("In-Order Traversal: ");
        inOrderDisplay(root);
        printf("\n");
        break;
      case 10:
        printf("Post-Order Traversal: ");
        postOrderDisplay(root);
        printf("\n");
        break;
      case 11:
        isWorking = 0;
        break;
      default:
        printf("Enter a Valid Option\n");
    }
  }
  return 0;
}
