#include <iostream>
#include <stdio.h> 
#include <stdlib.h>

using namespace std;

// int search(int *arr, int a, int b){
//     for(int i = 0; i < a; i++ ){
//         if (arr[i] == b){
//            return i;
//         }
//     }
//     return -1; 
// }

int main(){
    int a;
    cin >>  a;
    int b;
    cin >> b; 
    int *arr = new int [a];
    
    int counter = 0; 
    int i;
    for( i = 0; i < a; i++){
        cin >> arr[i];
    }
    
    // int result = search(arr, a, b);
    // if (result == -1){
    //     cout << -1; 
    // }
    // else {
    //     cout << result;
    // }

    for( i = 0; i < a; i++ ){
       if (arr[i] == b){
           counter = 1;
          cout <<  i; 
        }
    }
    if (counter != 1){
    cout << -1;
    }
   return 0;
}

  
    