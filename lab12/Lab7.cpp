#include<iostream>
#include<climits>
using namespace std;
/* calculate the best obtainable price for a rod of length rod_length and
price[] as prices of different pieces */
void cutRod(int *price, int rod_length){
    int *value=new int[rod_length+1];//store the price of intermediate cutting rod
    int *lastRodLength=new int[rod_length+1];//store the length of last rod piece
    value[0] = 0;
    int i, j;

    // Build the table value[] in bottom up manner and result is the last entry of the table
    for (i = 1; i<=rod_length; i++){
        int max_value = INT_MIN;
        int bestRodLength=-1;
        for (j = 1; j <= i; j++){
            if(max_value < price[j]+value[i-j]){
                max_value = price[j] + value[i-j];
                bestRodLength = j;
            }
        }
        value[i] = max_value;
        lastRodLength[i]=bestRodLength;
    }

    //optimal price of cutting rod
    cout<<value[rod_length]<<endl;
    i=rod_length;
    //display the rod length
    while(i>0){
        cout<<lastRodLength[i]<<" ";
        i=i-lastRodLength[i];
    }
    cout<<"-1\n";
    delete value;
    delete lastRodLength;
}

int main(int argc,char**argv){
    int rod_length;
    cin>>rod_length;
    int *price=new int[rod_length+1];
    price[0]=0;
    for(int i=1;i<=rod_length;i++)
        cin>>price[i];
        cutRod(price,rod_length);
    return 0;
}