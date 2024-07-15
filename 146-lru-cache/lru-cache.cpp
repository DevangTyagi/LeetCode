class LRUCache {
public:
   class node{
   public:
       int key_;
       int val_;
       node* next;
       node* prev;
       node(int key , int val){
        key_ = key;
        val_ = val;
      }
   };
   node* head = new node(-1,-1);
   node* tail = new node(-1,-1);
   int cap;
   unordered_map<int,node*>mp;

   void addnode(node* addingnode){
    node*temp=head->next;
    addingnode->next=temp;
    addingnode->prev=head;
    head->next=addingnode;
    temp->prev=addingnode;  
   }

   void deletenode(node* delnode){
     node*delprev=delnode->prev;
     node*delnext=delnode->next;
     delprev->next=delnext;
     delnext->prev=delprev;
   }

    LRUCache(int capacity) {
        cap = capacity;
        head->next=tail;
        tail->prev=head;
    }
    
    int get(int key) {
       if(mp.find(key)!=mp.end()) {
         node* tempnode = mp[key]; //Use to get the reference address of the  node
         int res = tempnode->val_;
         mp.erase(key);
         deletenode(tempnode);
         addnode(tempnode);
         mp[key]=head->next;
         return res;
       }
       return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            node* existingnode = mp[key];
            mp.erase(key);
            deletenode(existingnode);
        }
        if(mp.size()==cap){
            mp.erase(tail->prev->key_);
            deletenode(tail->prev);
        }
        addnode(new node(key,value));
        mp[key]=head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */