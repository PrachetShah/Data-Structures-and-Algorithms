#include <stdio.h>
#include<stdlib.h>

void printArr(int arr[], int n){
  for(int i=0; i<n; i++){
    printf("%d ", arr[i]);
  }
}

void selectionSort(int arr[], int n){
  int i, j, min_index, temp;

  for(i=0; i<n; i++){
    min_index = i;
    for(j=i+1; j<n; j++){
      if(arr[j] < arr[min_index])
        min_index = j;
    }
    temp = arr[min_index];
    arr[min_index] = arr[i];
    arr[i] = temp;
  }
  printArr(arr, n);
}

void insertionSort(int arr[], int n){
  int i, key, j;
  for (i = 1; i < n; i++){
    key = arr[i];
    j = i - 1;
    while (j >= 0 && arr[j] > key){
      arr[j + 1] = arr[j];
      j = j - 1;
    }
    arr[j + 1] = key;
  }
  printArr(arr, n);
}

int main(void) {
  int choice, isWorking = 1;

  while(isWorking){
    int i,size,arr[20];
    
    printf("\nMethods:\n1)Create Array\n2)Selection Sort\n3)Insertion Sort\n4)Exit\nEnter your choice: ");
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
        printf("Array After Sorting: ");
        selectionSort(arr, size);
        break;
      case 3:
        printf("Array After Sorting: ");
        insertionSort(arr, size);
        break;
      case 4:
        isWorking = 0;
        break;
      default:
        printf("Enter valid option.\n");
    }
  }
}
