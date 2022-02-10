#include <stdio.h>
#include<stdlib.h>

void printArr(int arr[], int n){
  for(int i=0; i<n; i++){
    printf("%d ", arr[i]);
  }
  printf("\n");
}

// function to swap elements
void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

//Time Complexity O(n^2)
void selectionSort(int arr[], int n){
  int i, j, min_index, temp;

  for(i=0; i<n; i++){
    min_index = i;
    for(j=i+1; j<n; j++){
      if(arr[j] < arr[min_index])
        min_index = j;
    }
    swap(&arr[min_index], &arr[i]);
  }
  printArr(arr, n);
}

int partition(int array[], int low, int high) {  
  // select the rightmost element as pivot
  int pivot = array[high];  
  // pointer for greater element
  int i = (low - 1);
  // traverse each element of the array and compare them with pivot
  for (int j = low; j < high; j++) {
    if (array[j] <= pivot) {        
      i++;      
      swap(&array[i], &array[j]);
    }
  }
  swap(&array[i + 1], &array[high]);  
  // return the partition point
  return (i + 1);
}

//Time Complexity O(n^2)
void quickSort(int array[], int low, int high) {
  if (low < high) {   
    int pi = partition(array, low, high);    
    quickSort(array, low, pi - 1);    
    quickSort(array, pi + 1, high);
  }
}

int main(void) {
  int choice, isWorking = 1;

  while(isWorking){
    int i,size,arr[20];
    
    printf("\nMethods:\n1)Create Array\n2)Selection Sort\n3)Quick Sort\n4)Exit\nEnter your choice: ");
    scanf("%d", &choice);
    switch(choice){
      case 1:
        printf("\nTo create a array, Enter size of array: ");
        scanf("%d", &size);
        printf("Enter all elements of array: ");
        for(i = 0; i<size; i++){
          scanf("%d", &arr[i]);
        }
        printf("\n\nGiven array is : ");
        printArr(arr, size);
        break;
      case 2:
        printf("Array After Selection Sort Method: ");
        selectionSort(arr, size);
        break;
      case 3:
        printf("Array After Quick Sort Method: ");
        quickSort(arr, 0, size-1);
        printArr(arr, size);
        break;
      case 4:
        isWorking = 0;
        break;
      default:
        printf("Enter valid option.\n");
    }
  }
}
