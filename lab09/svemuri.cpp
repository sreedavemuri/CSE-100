#include<iostream>
#include <list>

using namespace std;

// Skeleton provided by TA Arman. 
// I had some help from Arnold Khampaseut for this lab. Becaause I was confused whether we have to use Linked Lists or not. 

int hash_function(int key, int n){
    return key % n; 
}

void insertKey(list<int> *hashTable, int key,int n){
    int idx = hash_function(key, n);
    hashTable[idx].push_front(key);
}
  
bool deleteKey(list<int> *hashTable, int key,int n){
    int idx = hash_function(key, n);
    list<int> l = hashTable[idx];
    list<int>::iterator iterator = l.begin(); // repeat
        
    if(l.empty()){
        return false; 
    }
    else{
        for (iterator = l.begin(); iterator != l.end(); iterator++){
            if(*iterator == key){
                l.erase(iterator); 
                hashTable[idx] = l;
                return true ;
            }
        }
        return false;
    }
}
bool searchKey(list<int> *hashTable, int key,int n){
    int idx = hash_function(key, n);
    list<int>::iterator iterator; // repeat
    int i = 0;
    list<int> l = hashTable[idx];

    if(l.empty()){
        return false;
    }
    else{
        for (iterator = l.begin(); iterator != l.end(); iterator++){
            if(*iterator == key){
                cout<<key<<" : FOUND AT "<< idx <<","<< i <<""<<"\n";
                return true;
            }
            i++;
        }
    return false;
    }
}

bool printHash(list<int> *hashTable, int n){
    list<int> l;
    list<int>::iterator iterator; // repeat
    for(int i = 0 ; i < n; i++){
        l = hashTable[i];
         
        if(l.empty()){  
            cout<<i<<" : ";  
        }
        else{
            cout<<i<<" : ";  
            // print list here
            for (iterator = l.begin(); iterator != l.end(); iterator++){
                if (iterator != l.begin()){
                    cout<< "->" << *iterator;
                }
                else {
                    cout << *iterator;
                }
            }
        }   
        cout<<"\n";
    }   
    return true; 
}

int main(){
    int n, key;
    cin >> n;
    char chh;
    list<int> *hashTable = new list<int>[n];
   
    cin >> chh;
    
    while(chh != 'e'){
        if(chh == 'i'){
            cin >> key;
            insertKey(hashTable, key,n);
        }
        else if(chh == 'd'){
            cin >> key;
            if(deleteKey(hashTable, key,n) == true){
                cout << key <<" : DELETED" << "\n";
                cout << "++++++++++++++++++++" << "\n";
            }
            else{
                cout << key <<" : DELETE FAILED"<<"\n";
                cout << "++++++++++++++++++++" << "\n";
            }
        }
        else if(chh =='s'){
            cin >> key;
            if (searchKey(hashTable, key,n) == false){
                cout<< key<<" : NOT FOUND"<<"\n";
                cout << "++++++++++++++++++++" << "\n";

            }
            else{
                cout << "++++++++++++++++++++" << "\n";
            }
        }
        else if(chh =='o'){
            if(printHash(hashTable, n) == true){
                cout << "++++++++++++++++++++" << "\n";
            }            
        }
        cin>>chh;
    }
}