
#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <deque>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

// A Huffman tree node struct

struct Min_Heap_Node {

    unsigned freq;

    // Left and right child

    Min_Heap_Node *left, *right;

    Min_Heap_Node(unsigned freq){

        left = right = NULL;

        this->freq = freq;

    }

};

// For comparison of two heap nodes

struct compare {

    bool operator()(Min_Heap_Node* l, Min_Heap_Node* r){

        return (l->freq > r->freq);

    }

};

// Prints huffman codes from root

void printCodes(struct Min_Heap_Node* root, string str){

    if (!root)

        return;

        printCodes(root->left, str + "0");

        printCodes(root->right, str + "1");

}

// The main function that builds a Huffman Tree and

// print codes by traversing the built Huffman Tree

void HuffmanCodes(int freq[], int size){

    struct Min_Heap_Node *left, *right, *top;

    // Create a min heap & inserts all characters of data[]

    priority_queue<Min_Heap_Node*, vector<Min_Heap_Node*>, compare> minHeap;

    for (int i = 0; i < size; ++i){
        minHeap.push(new Min_Heap_Node(freq[i]));
    }
    // Iterate while size of heap doesn't become 1

    while (minHeap.size() != 1) {

    // Extract the two minimum freq items from min heap

        left = minHeap.top();
        minHeap.pop();
        right = minHeap.top();
        minHeap.pop();
        top = new Min_Heap_Node( left->freq + right->freq);
        top->left = left;
        top->right = right;
        minHeap.push(top);

    }

    // Print Huffman codes using the Huffman tree built above

    for(int i=0;i<size;++i){
        printCodes(minHeap.top(),0);
    }
}

// driver function

int main(){

    int n;
    cin >> n;
    int freq[n] ;
    for(int i=0;i<n;i++){

        cin>>freq[i];
    }
    HuffmanCodes(freq, n);

    return 0;

}