// I used some of the steps on geeksforgeeks.org to able to call the function to main properly. 


#include <iostream>
#include <stdio.h> 
#include <stdlib.h>

using namespace std;


int binarysearch(int *arr, int top, int bot, int b){
    
    while (top <= bot){
    int mid = (top + bot)/2;  
        if (arr[mid] == b){
            return mid; 
        }
        else if (arr[mid] < b){
            top = mid + 1; // dont mess with the bottom
        }
        else{
            bot = mid - 1;
        }
    }
    return -1; 
}

int main(){
    int a;
    cin >> a;
    int b;
    cin >> b; 
    
    int *arr = new int [a];
    
    for(int i = 0; i < a; i++){
        cin >> arr[i];
    }
     
    int result = binarysearch(arr, 0, a - 1, b);
    if (result == -1){
        cout << -1; 
    }
    else {
        cout << result;
    }
}

