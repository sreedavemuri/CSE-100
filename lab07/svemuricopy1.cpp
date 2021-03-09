#include <iostream>
#include <vector>
using namespace std; 


void countingSort(vector <int> *A, int d, int v){
    //using vector int instead of regular int, because of the instructions
    
    vector<int> *B = new vector<int>[d];
    // output would also need to be a vector 

    int C[10] = {0};
    
    for(int i = 0; i < d; i++){
        C[A[i][v]%10]++;
    }

    // %10 added because you want the vectors to considered as a whole number together

    for (int i = 1; i < 10; i++ ){
        C[i] = C[i] + C[i-1];
    }

    for (int i = d-1; i >= 0; i--){
        B[C[A[i][v]%10]-1] =  A[i];
        C[A[i][v]%10] = C[A[i][v]] - 1;
    }
    // for-loop above directly from textbook

    for(int i = 0; i < d; i++){
        *(A + i) = *( B + i);
    }
    // sorted array to output array
}

void radixSort(vector <int> *arr, int d){
    for (int v = 9; v >= 0 ; v--){
        countingSort(arr, d, v);
    }
}

int main(){
   
    int d;
    cin >>  d;
    vector <int>  *arr = new vector <int> [d];
    
    for(int i = 0; i < d; i++){
        for(int j=0; j< 10; j++){
            int n; 
            cin >> n; 
            arr[i].push_back(n);
        }
    }
    
    radixSort(arr, d);

    for (int i = 0; i < d; i++){
        for(vector<int>::iterator output = arr[i].begin(); output != arr[i].end(); output++){
            cout << *output << ";";
        }
        cout<<endl;
    }  

}

//  int main(){
//     int arrSize;
//     cin >> arrSize;

//     vector<vector<int>> *Sequence;

//     for (int i = 0; i < arrSize; i++){
//         vector<int>row;
//         for (int j = 0; j < 10; j++){
//             int value;
//             cin >> value;
//             row.push_back(value);
//         }
//         Sequence[i].push_back(row);
//     }

//     vector<vector<int>> sorted = radixSort(Sequence, arrSize);

//     for (int i = 0; i < arrSize; i++){
//         for (int j = 0; j <= 9; j++){
//             cout << sorted[i][j] << ";";
//         }
//         cout << endl;
//     }
//     return 0;
// }