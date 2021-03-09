#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;
// I used the texbook as told by the TA, TA Arman did not give Skeleton Code this time around, but did give us some pointers as to where to start. 
// I discussed code with an Upper Classman who helped me understand the general huffman code structure - Enrique Florencio
// I also used the structs from lab 11. 

struct Min_Heap_Node {
    char arr;
    int freq;
    Min_Heap_Node *left, *right; 

    Min_Heap_Node(char arr, unsigned freq){
        this -> left = this -> right = NULL;
        this->arr = arr;
        this->freq = freq;
    }
};

struct compare {
    bool operator()(Min_Heap_Node* l, Min_Heap_Node* r){
        return (l->freq > r->freq);
    }
};

void printCodes(struct Min_Heap_Node* root, vector<char> arr , int size, string str){
    if (!root)
        return;
    if(root->arr == arr[size])
        cout << str << endl;
    if(root->left)
        printCodes(root->left, arr, size, str + "0");
    if (root-> right)
        printCodes(root->right, arr, size,  str + "1");
}

void HuffmanCodes(vector <char> arr, vector <int> freq, int size){
    
    struct Min_Heap_Node *x, *y, *z;
    priority_queue<Min_Heap_Node*, vector<Min_Heap_Node*>, compare> minHeap;

    for (int i = 0; i < size; i++){
        minHeap.push(new Min_Heap_Node(arr[i], freq[i]));
    }
    for(int i = 0; i < size - 1; i++){
        x = minHeap.top(); minHeap.pop();
        y = minHeap.top(); minHeap.pop();
        z = new Min_Heap_Node('$', x->freq + y->freq);
        z->left = x; z->right = y;
        minHeap.push(z);
    }
    for(int i = 0;i < size;++i){
        printCodes(minHeap.top(), arr, i, "");
    }
}

int main(){
    int size; 
    cin >> size; 
    vector <char> arr;
    vector<int> freq ;
    for(int i = 0; i < size;i++){
        int n; 
        cin >> n; 
        arr.push_back('A' + i); 
        freq.push_back(n);
    }
    HuffmanCodes(arr, freq, size);
    
    return 0;
}