
    //single chaining: linked lists 
    //ways to solve collisions 
   
    #include<iostream> 
    using namespace std; 
   
    class Bucket{
        private: 
            int store; 
            Bucket *next;//next node 
        public: 
            Bucket(){ //will be helpful to use if the lists are empty
                store= -1; 
                next= NULL;
            }  
            Bucket(int key){ //will be helpful to use if the lists are empty
                store = key; 
                next= NULL;
            }   
            void setV(int key){
                store = key; 
            }  
            int getV(){
                return(store);
            }    
            void setNext(Bucket *n){
                next = n;
            }  
            Bucket* getNext(){
                return(next);
            } 

    }; 

    class HashTable{
        private: 
            Bucket **root; 
            int size; // m in main
            int hashFunc(int key){
                return(key % size);
            } 
        public:  
            HashTable(int m){
                size = m;
                root = new Bucket*[m]; 
                //init the table 
                for(int i = 0; i< size; i++){
                    root[i]= NULL;
                }
            }     
           void insertItem(int key){
               int idx = hashFunc(key);
               Bucket *slot = root[idx];
               if(slot == NULL){
                   root[idx] = new Bucket(key);
                   }else{
                while(slot -> getNext()!= NULL){//if not empty
                    slot = slot -> getNext();
                }//use setterfor insert operation
                slot -> setNext(new Bucket(key));
                }    
            }               
            void searchItem(int key){
                bool found = false; 
                int idx = hashFunc(key); 
                Bucket *slot = root[idx];
                while(slot!=NULL){
                    if(slot -> getV() == key){ 
                        found = true;
                        break;
                    }
                    slot = slot -> getNext(); 
                }
            }   

            bool deleteItem(int key){ 
                bool found = false; 
                int idx = hashFunc(key); 
                Bucket *slot = root[idx]; 

                if(slot -> getV() != key){
                    root[idx] = NULL; 
                    found = true; 
                }else{
                    while(slot -> getNext() != NULL){
                        if(slot -> getNext()->getV() == key){ 
                            slot -> setNext(slot -> getNext() -> getNext());
                            found = true;
                            break; 
                        }
                        slot = slot -> getNext();    
                    }
                }     
                return found;
            }
            void printHashTable(){ 
                for(int i = 0; i < size; i++){
                    cout<< i<<" : "; 
                    Bucket *slot = root[i];

                    while(slot != NULL){
                        cout<<slot->getV()<<" "; 
                        slot = slot-> getNext();
                    } 
                    cout<<endl;
                } 
                cout<<"++++++++++++++++++++\n";
            }
    };
    int main(){
        int m = 0;
        cin>>m;
        HashTable *hash_table = new HashTable(m); 
        while(true){
            char c;
            cin>>c;
            if(c == 'e'){
                break;
            }else if(c == 'o'){
                hash_table -> printHashTable();
            }else if(c == 'i'){
                int key;
                cin>>key;
                //hash_table -> insertItem(key); 
            }else if(c == 'd'){
                int key;
                cin>>key; 
                //hash_table -> deleteItem(key);
            } else if(c == 's'){ 
                int key;
                cin>>key;
                hash_table -> searchItem(key);
                // if(found == true){
                //     cout<<"FOUND AT "; 
                // }else{
                //     cout<<"NOT FOUND "; 
                // }    
            }   
       } 
       return 0;
    }
        //Iterators are like pointers in a sense, except they are used on collections and there are several types of them. They allow you to iterate over a collection and, in some cases (non-const iterators), modify the contents of that collection.
    