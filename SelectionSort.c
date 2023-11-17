#include <stdio.h>
#include <stdlib.h>

// Selection sort = search through an array and keep track of the minimum value during
//     each iteration. At the end of each iteration, we swap variables.

//     Quadratic time O(n^2)
//     small data set = okay
//     large data set = BAD

void swap(int *x, int*y){
    int temp = *x;
    *x = *y;
    *y = temp;
}
void selectionSort(int *arr,int n){
    int i,j,minIndex;

    for(i =0; i<n-1; i++){
        minIndex = i;
        for(j = i; j<n; j++){
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }
        swap(&arr[minIndex],&arr[i]);
    }
}
void printArray(int *arr, int size){
    for(int i=0; i<size; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
int main(){
    int *arr;
    int n;

    printf("Enter the size of array: \n");
    scanf("%d",&n);

    arr = (int*)malloc(n * sizeof(int));

    printf("Enter the elements of the array: \n");
    for(int i =0; i<n; i++){
        scanf("%d",&arr[i]);
    }

    printf("Unsorted Array: \n");
    printArray(arr,n);

    selectionSort(arr,n);

    printf("\nArray Sorted with Selection Sort \n");
    printArray(arr,n);
}