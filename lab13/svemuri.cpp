#include <iostream>
#include <limits.h>
using namespace std;

// I used textbook code and modified it because I personally did not understand how to implement TA Armaan's Skeleton Code. 
// I felt that all the pushback stuff was unecessary so i implemented the text book code. 

void print_optimal_paranthesis(int i, int j, int bracket, int *name){
   
    if (i == j){
        cout <<"A"<<(i - 1);
        return;
    }
    else{
        cout << "(";
        print_optimal_paranthesis(i, *((name+i*bracket)+j), bracket, name);
        print_optimal_paranthesis(*((name+i*bracket)+j) + 1, j, bracket, name);
        cout << ")";
    }
}

void matrix_chain_order(int p[], int n){
    //n =  p.length() - 1; 
    int m[n][n];
    int s[n][n];
    
    for (int i = 1; i < n; i++){
        m[i][i] = 0;
    }
    //l is the chain length
    for (int l = 2; l < n; l++){
        for (int i = 1; i < (n - l + 1); i++){
            int j = i + l - 1;
            //end index for chain of length l
            
            m[i][j] = INT_MAX;
            for (int k = i; k <= j - 1; k++){
                
                int q = m[i][k] + m[k+1][j] + ((p[i-1]) * (p[k]) * (p[j]));
                
                if (q < m[i][j]){
                    m[i][j] = q;                    
                    s[i][j] = k;
                }
            }
        }
    }
    // return (m,s); 
    cout << m[1][n-1]<< endl;
    print_optimal_paranthesis(1, n-1, n, *s);
    cout<< endl;
}


int main(){
    int n;
    cin >> n;
    int *arr = new int[n+1];
    for (int i = 0; i <= n; i++){
        cin >> arr[i];
    }
    matrix_chain_order(arr, n + 1);
    return 0;
}