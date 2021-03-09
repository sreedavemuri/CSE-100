#include <iostream>
using namespace std; 

// I used the textbook for reference for the functions, and I took help from StackOverflow for figuring out the swap. I didnt quite know the command. 
// I also used GeeksforGeeks for help, with the parts I didnt understand in maxHeapify, and buildMaxHeap

void maxHeapify(int arr[], int n, int i){

    int l = 2 * i + 1;
    int r = 2 * i + 2;

    int largest = i; 
    // if left child is greater than the root
    if (l < n && arr[l] > arr[largest] ){
        largest = l;
    }
    // if right child is greater than the root
    if (r < n && arr[r] > arr[largest] ){
        largest = r;
    }
    // neithre is the largest
    if (largest != i){
        //swap
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        maxHeapify(arr, n, largest);
    }
}
// rearrange the array (buildheap)
void buildMaxHeap(int arr[], int n){
        for(int i = (n / 2) - 1; i >= 0; i--){
            maxHeapify(arr, n, i);
    }
}

void heapSort (int arr[], int n){
    buildMaxHeap(arr, n);
    for(int i = n - 1; i >= 0; i--){
       // swap
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        maxHeapify(arr, i, 0);
     }
}

int main(){
    int n; 
    cin >> n; 
    int *arr = new int[n];

    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    heapSort(arr, n);
    
}