#include <iostream>
#include <climits>

using namespace std; 

// I got the code from the textbook, used the ext-bottom-up-cut-rod function and the print-cut-rod-solution

int* extended_bottom_up_cut_rod(int *price, int length){
    int *r = new int[length + 1];
    int *s = new int [length + 1] ;
    r[0] = 0;
    int q;
    for (int j = 1; j <= length; j++){
        q = INT_MIN;
        int bestRodLength = -1;
        for (int i = 1; i <= j; i++){
            if ( q < price[i] + r [j - i]){
                q = price[i] + r [j - i]; 
                bestRodLength = i; 
            }
        }
        r[j] = q;
        s[j] = bestRodLength;
    }
    cout<< r[length] << endl;
    return (r, s);     
}

void print_cut_rod_solution(int *price, int length){
    int *r = new int[length + 1];
    int *s = new int[length + 1];
    (r, s) = extended_bottom_up_cut_rod(price, length);

    while(length > 0){        
        cout << s[length]<< " ";
        length = length - s[length];
    }
    cout<<"-1\n";
}

int main(){
    int length; 
    cin >> length; 
    int *price = new int[length + 1];
    price[0] = 0;
    for(int i = 1; i <= length; i++){
        cin >> price[i];        
    }
    print_cut_rod_solution(price, length);
    return 0;
}