#include <iostream>
#include <vector>

using namespace std; 

// I went to Arman's Lab because I found his labs more convienient for my schedule. I had preiviously, managed to implement Radix sort using a single vector.
// But going to Arman's lab helped me figure out the double vector implementation without using pointers. 
// I got the code for the main from the TA, with a few tweaks. 

 vector<vector<int>> countingSort(vector<vector <int>> A, int d , int n ){
//using double vector int instead of regular int, because of the instructions
    
    vector<vector<int>> B = A;
    // output would also need to be a vector 
   
    int C[10];

    for (int i = 0; i < 10; i++){
        C[i] = 0;
    }
     // Arman sugessted a double for-loop to create 0 arrays, but that was unecessary for me
     // Since the code it self is running through the columns in Radix Sort, it would not be necessary
    for(int i = 0; i < n ; i++){
        C[A[i][d]]++;
    }
    
    for (int i = 1; i < 10; i++ ){
        C[i] = C[i] + C[i - 1];
    }

    for (int i = n - 1; i >= 0; i--){
        // for(int j = 0; j < 10; j++){
            B[C[A[i][d]]- 1] =  A[i];  
            C[A[i][d]] = C[A[i][d]] - 1;
        // }
    }
    // Arman sugessted a double for-loop, but that was unecessary for me

    // for-loop above directly from textbook

    // for(int i= 0; i < d; i++){
    //     for(int j = 0; j < 10; j++){
    //         A[i][j] = B[i][j];
    //     }
    // }
    
    return B;
    // sorted array to output array
}

vector<vector<int>> radixSort(vector<vector<int>> arr, int d){
    for (int v = 9; v >= 0 ; v--){
        arr = countingSort(arr, v, d);
    }
    
    return arr;
}

int main(){
    int arrSize;
    cin >> arrSize;

    vector<vector<int>> Sequence;

    for (int i = 0; i < arrSize; i++){
        vector<int> row;
        for (int j = 0; j < 10; j++){
            int value;
            cin >> value;
            row.push_back(value);
        }
        Sequence.push_back(row);
    }

    vector<vector<int>> sorted = radixSort(Sequence, arrSize);

    for (int i = 0; i < arrSize; i++){
        for (int j = 0; j <= 9; j++){
            cout << sorted[i][j] << ";";
        }
        cout << endl;
    }
    return 0;
}

