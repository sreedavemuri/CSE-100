#include <iostream>
using namespace std; 

int partition(int *arr, int top, int bot){
    int x =  *(arr+ bot);
    int i = top - 1; 
    for (int j = top; j <= bot - 1; j++){
        if(*(arr+ j) < x){
            i = i + 1; 
            int temp = *(arr+ i);
            *(arr + i) = *(arr+ j);
            *(arr + j) = temp;
            // swap(*(arr+ i), *(arr+ j));
        }
    }
    int temp = *(arr+ (i + 1)); 
    *(arr + (i + 1)) = *(arr+ bot); 
    *(arr+ bot) = temp; 
    // swap(*(arr+ (i + 1)), *(arr+ bot));
    return (i+1); 
}

int quickSort(int *arr, int top, int bot){
    if (top < bot){
        int q = partition (arr,top, bot);
        quickSort(arr, top, q - 1);
        quickSort(arr, q + 1, bot);
    }
}

// copied from my old labs
int main(){
   
    int n;
    cin >>  n;
    int *arr = new int [n];
    for(int i = 0; i < n; i++){
        cin >> *(arr+ i);
    }
    quickSort(arr, 0, n - 1);

    for(int i = 0; i < n ; i++){  
        cout <<*(arr+ i)<<";";  
    }  
}
