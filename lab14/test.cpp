#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <climits>

using namespace std; 

struct Node{
  int key;
  int* freq;
  int* Q; 
  Node* left;
  Node* right;
  Node* parent;

  Node(int key){
        this->key = key;
        this->freq  = freq; 
        this-> Q = Q; 
        this->left = NULL;
        this->right = NULL;
        this->parent = NULL;
    }
  };

class MinHeap{
  public:
    
    Node *root;
    MinHeap(){
        this->root = NULL;
    }

    Node* extract_min(Node* Q){
        
        while(Q->left != NULL){
            Q = Q->left;         
        }
         return Q; 
    }   
    void insert(Node* Q, Node* z){
        Node* y = NULL;
        Node* x = this->root;
        
        while(x != NULL){
            y = x;
            if((z -> key) <( x -> key)){
                x = x->left;
            } 
            else{
                x = x->right;
            }
        }
        //z->key = key;
        z->parent = y;
        if(y == NULL){
            root = z;
        } 
        else if((z -> key) < ( y -> key)){
            y->left = z;
        } 
        else{
            y->right = z;
        }
    }
    Node* HuffmanCodes(Node *Q, Node *freq, int n){
        for(int i = 1; i < n - 1; i++){
            Node * z, *x, *y;
            z->left = x = extract_min(Q);
            z->right = y = extract_min(Q);
            z->freq = x->freq + y->freq;
            insert(Q,z);
        }
        return extract_min(Q);
    }
};
int main() { 
  MinHeap* tree = new MinHeap();
   int n; 
    cin >> n; 
    int arr[] = { 'A', 'B', 'C', 'D', 'E', 'F'};
    // int freq[n];
    Node*freq = new Node(n);
    for(int i = 0; i < n;i++)
        cin >> freq[i];
    tree->HuffmanCodes(arr, freq, n);
    return 0;
}