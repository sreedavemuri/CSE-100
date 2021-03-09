#include <iostream>
#include <sstream>

using namespace std;

// TA Arman gave the skeleton, but i had to change the main, in the way i saw fit, because there were errors in output type.
// the functions were found from the textbook
struct Node{
  int key;
  Node* left;
  Node* right;
  Node* parent;

  Node(int key){
        this->key = key;
        this->left = NULL;
        this->right = NULL;
        this->parent = NULL;
    }
};

class BST{
  public:
    
    Node *root;
    BST(){
        this->root = NULL;
    }
    Node* treeMin(Node* x){
        while(x->left != NULL){
            x = x->left;         
        }
         return x; 
    }   

    Node* search( Node* k){
       Node* x = root;
            
        while(x != NULL && k->key != x->key){
            if(k->key < x->key){
                x = x->left;
            }
            else{
                x = x->right;
            }
        }        
        return x;
    }
    void Transplant (Node* u, Node* v){
    
        if((u-> parent) == NULL){
            this->root = v;
        }
        else if(u == (u->parent->left)){
            u->parent->left = v;
        }
        else{
            u->parent->right = v;
        }
        if (v != NULL){
            v->parent = u->parent;
        }
    }
    void insert(Node* z){
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

    void deletekey(Node *z){       
        
        z = search(z);
        Node* y;
        if (z==NULL){
            return;
        }
        else{
            if (z-> left == NULL){
                Transplant(z, z->right);
            }
            else if (z-> right == NULL){
                Transplant(z , z->left);
            }
            else{
                y = treeMin(z->right);
                if (y->parent != z){
                    Transplant(y, y->right);
                    y->right = z->right;
                    y->right->parent = y; 
                }
                else {
                    Transplant(z, y);
                    y->left = z->left;
                    y->left->parent = y; 
                }
            }
        }
    
    }

    void preorder(Node *n){
      if(n != NULL){
        cout<<n->key<<endl;
        this->preorder(n->left);
        this->preorder(n->right);
      }
    }

    void inorder(Node *n){
        if(n != NULL){
        this->inorder(n->left);
        cout<<n->key<<endl;
        this->inorder(n->right);
      }
    }

    void postorder(Node *n){
         if(n != NULL){
        this->postorder(n->left);
        this->postorder(n->right);
        cout<<n->key<<endl;
      }
    }
};

int main() {
    //char inp[100];
    
    BST* tree = new BST();
    string s; 
    int n; 

    while(true){

        cin >> s; 

        if(s == "e"){
            break;
        } 
        else if(s == "pre"){
            tree->preorder(tree->root);
            cout<<"++++++++++++++++++++"<<endl;
        }
        else if(s == "in"){
            tree->inorder(tree->root);
            cout<<"++++++++++++++++++++"<<endl;
        } 
        
        else if(s == "post"){
            tree->postorder(tree->root);
            cout<<"++++++++++++++++++++"<<endl;
        } 
        
        else if(s == "i"){
            cin >>  n;
            Node* key = new Node(n);
            tree->insert(key);
        } 
        else if(s == "d"){
            cin >> n;
            Node* key = new Node(n);
            tree->deletekey(key);
        }

    }

    return 0;
}
