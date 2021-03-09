#include <iostream>
#include <limits.h>

using namespace std;

int MaxCrossSub(int *arr, int low, int mid, int high){

    int leftsum = INT_MIN;
    int sum = 0; 
    
    for(int i = mid; i >= low; i--){
        sum = sum + arr[i];
        if (sum > leftsum) {
            leftsum = sum; 
        }
    }

    int rightsum = INT_MIN; 
    sum = 0;
 
    for(int j = mid + 1; j <= high; j++){
        sum = sum + arr[j];
        if (sum > rightsum){
            rightsum = sum; 
        }
    }
return (leftsum, rightsum, leftsum + rightsum);
}

int MaxSub(int *arr, int low, int high){
    if (high == low){
        return (arr[low]);
    }
    else{
        int mid = (low + high)/2 ;
        int left_sum = MaxSub(arr, low, mid);
        int right_sum = MaxSub(arr, mid + 1, high);
        int max_sum = MaxCrossSub(arr, low, mid, high);

        if ((left_sum >= right_sum) && (left_sum >= max_sum)){
            return left_sum;
        }
        else if ((right_sum >= left_sum) && (right_sum >= max_sum)){
            return right_sum;
        }
        else{
            return max_sum;
        }
    }
}

int main(){
    int n; 
    cin >> n; 
    int *arr = new int[n];

    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int max_sum = MaxSub(arr, 0 , n-1);
    cout << max_sum;
}