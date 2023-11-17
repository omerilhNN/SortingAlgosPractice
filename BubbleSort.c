#include <stdio.h>
#include <stdlib.h>

// bubble sort = pairs of adjacent elements are compared, and the elements
//                          swapped if they are not in order.

//     Quadratic time O(n^2)
//     small data set = okay-ish
//     large data set = BAD (plz don't)

void swap(int *x,int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}
//Replace the largest number of the array to the end of the array.
void bubbleSort(int *arr, int n){
    for(int i = 0; i< n-1; i++){ //This for loop represents each comparision cycle.
        for(int j =0; j< n -i; j++){
            if(arr[j]> arr[j+1]){
                swap(&arr[j],&arr[j+1]);
            }
        }
    }
}

int main(){
    int n,i;
    printf("Dizinin boyutunu giriniz: ");
    scanf("%d",&n);

    int *arr = (int* )malloc(n*sizeof(int)); //* kullanarak dizinin başlangıç adresini tutarız.

    if(arr == NULL){
        printf("Bellek ayirilamadi.. Program sonlandiriliyor");
        return 1;
    }

    printf("Elemanlari giriniz: \n");
    for(i=0; i<n; i++){
        scanf("%d",&arr[i]);
    }

    bubbleSort(arr,n);

    printf("Siralanmis elemanlar ");
    for(i = 0;i<n; i++){
        printf("%d ",arr[i]);
    }
}