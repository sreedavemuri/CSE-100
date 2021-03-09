#include <iostream>
#include <vector>
#include <list>
#include <math.h>
#include <algorithm>

using namespace std; 

//make a helper function
void CompareExchange(vector<float> bi, float i, float j){
    if (bi[i] > bi[j]){
        swap(bi[i], bi[j]);
    }
}

//implement the new insertion sort made in the textbook
void insertionSort(vector<float> bi){
    for(float j = 1; j < (bi.size()); j++){
        for(float i = j - 1; i > 1; i--){
            CompareExchange(bi, i, i + 1);
        }
    }
    // printing here instead of main
    for (int j = 0; j < bi.size(); j++){  
        cout << bi[j]<<"\n";  
    }
    // return bi;
}

// TA gave this code
void bucketSort(float arr[], int n){
    
    vector<float>* B = new vector<float>[n];
    for(int i = 0; i < n; i++){
        int f = floor(n * arr[i]);
        B[f].push_back(arr[i]);
    }
    for(int i = 0; i < n; i++){
        insertionSort(B[i]);
    }
}

int main(){
    int n;
    cin >>  n;
    float *arr = new float [n];
    for(int i = 0; i < n; i++){
        cin >> *(arr + i);
    }
    
    bucketSort(arr, n);

    // we could use the print here too.. 
    // for(int i = 0; i < n ; i++){  
    //     cout <<*(arr+ i)<<"\n";  
    // }  

    return 0;
}