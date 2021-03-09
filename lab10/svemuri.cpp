#include <iostream>
#include <list>
using namespace std;

//skeleton provided by TA Arman

const int m = 13;

int hashFunction(int key, int i){
    int h1 = key % 13 ;
    int h2 = 1 + (key % 11);
    int h = (h1 + (i * h2)) % 13;

    return h;
}

void printTable(int Table[m]){
    cout << "++++table printout++++"<<endl;
    for(int i = 0; i < m; i++){
        if(Table[i] >= 0){
            cout<<Table[i]<<endl;
        }
        else{
            cout<<endl;
        }
    }
}

void insertKey(int Table[m],int key){
    cin >> key;
    while(key != -1) {        
        for (int i = 0; i < m; i++){
        // 1. calculate hash function
            int h = hashFunction(key, i);
        // 2. put it into your hash table
            if (Table[h] == -1){
                Table[h] = key;
                break;
            }
        }
        cin >> key;
    }
}

void searchKey(int Table[m], int key){
    cout << "++++searching++++"<<endl;
    cin >> key;
    while(key != -2) {        
        for (int i = 0; i < m; i ++){
            // 1. calculate hash function
            int h = hashFunction(key, i);
            // 2. search that key in your hash table, print either index or a message "NOT FOUND"
            if (Table[i] == key){
                cout << i << endl;
                break; 
            }
            else if (i == 12 && Table[i] != key){
                cout << "NOT_FOUND" << endl;
            }        
        }
        cin >> key;
    }
}

void deleteKey(int Table[m], int key){
    cout << "++++deleting++++"<<endl;
    cin >> key;
    while(key != -3) {
        // 1. calculate hash function
        for (int i = 0; i < m; i++){
        // 2. delete a key from your hash table
            if (Table[i] == key){
                Table[i] = -1; 
                break;
            }
        }
        cin >> key;
    }
}

int main() {
    int key;

    // Create Hash Table
    int Table[m];

    // Initialize Hash Table
    for(int i = 0; i < m; i++) {
        Table[i] = -1;
    }

    // KEY INSERTION    
    insertKey(Table, key);

    // ++++table printout++++
    printTable(Table);

    // KEY SEARCHING    
    searchKey(Table, key);

    // KEY DELETING    
    deleteKey(Table, key);
    
    // ++++table printout++++
    printTable(Table);

    return 0;

}