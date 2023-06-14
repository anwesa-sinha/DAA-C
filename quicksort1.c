#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high){
    int pivot = arr[high]; // choosing last element as pivot
    int i = low - 1;
    
    for(int j = low; j <= high - 1; j++){
        if(arr[j] < pivot){
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1], &arr[high]); // placing pivot element at its correct position
    return i + 1;
}

void quickSort(int arr[], int low, int high){
    if(low < high){
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi-1);
        quickSort(arr, pi+1, high);
    }
}

int main(){
    int arr[] = {5,2,0,9,8,7,1,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    printf("Before Sorting: ");
    for(int i=0; i<n; i++)
        printf("%d ", arr[i]);
        
    quickSort(arr, 0, n-1);
    
    printf("\nAfter Sorting: ");
    for(int i=0; i<n; i++)
        printf("%d ", arr[i]);
        
    return 0;
}
