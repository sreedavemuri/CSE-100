#include <iostream>
#include <vector>
#include <list>
#include <math.h>
#include <algorithm>
using namespace std; 

// I got help from the TA Arman for the code, the insertion sort was not working for some reason, it was having small errors, such as 0.59 and 0.58 were not sorting in order. 
// Ultimately I used the built-in algorithm for sorting which Arman recomended. 

void insertionSort (vector<float> bi, int n){
    //insertion sort doesnt work for some reason. 

    for(int i = 1; i < n; i++){
        int key = bi[i];
        int j = i - 1 ;

        while( j>= 0 && bi[j] > key ){
            bi[j+1] = bi[j];
            j--;
        }

        bi[j + 1] = key;
    } 

    sort(bi.begin(), bi.end());
    // print here
    for (int j = 0; j < bi.size() ; j++){  
        cout << bi[j]<<"\n";  
    }
}

void bucketSort(float arr[], int n) {
 
    //vector<float> B[n];

    vector<float>* B = new vector<float>[n];
    for(int i = 0; i < n; i++){
        int f = floor(n * arr[i]);
        B[f].push_back(arr[i]);
    }

    for(int i = 0; i < n; i++){
        insertionSort(B[i],B[i].size());
    }  
}

int main(){
    int n;
    cin >>  n;
    float *arr = new float [n];
    for(int i = 0; i < n; i++){
        cin >> *(arr+ i);
    }
    bucketSort(arr, n);

    // for(int i = 0; i < n ; i++){  
    //     cout <<*(arr+ i)<<"\n";  
    // }  

    return 0;
}