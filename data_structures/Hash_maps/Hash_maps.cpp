#include<iostream>
#include<string>
using namespace std;
template <typename V>;
class MapNode{                       // Class for linked list
    V value;
    string key;
    MapNode * next;
    MapNode(V value,string key){
        this->value=value;
        this->key=key;
        next=NULL;
    }
      ~MapNode(){
         delete next;
      }
};
template <typename V>;
class Ourmap{
      MapNode<V> ** buckets;            // array with buckets having those many linked list head address at each index...
      int siz;
      int numBuckets;
  public:
    Ourmap(){
       siz=0;
       numBuckets=5;
       Buckets=new MapNode<V> * [numBuckets];
       for(int i=0;i<numBuckets;i++){
        numBuckets[i]=NULL;
       }
    }
    ~Ourmap(){
      for(int i=0;i<numBuckets;i++){
        delete Buckets[i];
      }
      delete [] Buckets;
    }
    int size(){
       return siz;
    }
  private:
     int bucketindex(string key){
        int hashCode=0;
        int currCoeff=1;
        for(int i=key.length()-1;i>=0;i--){
            hashCode+=key[i]*currCoeff;
            currCoeff*=37;
            currCoeff=currCoeff%numBuckets;
            hashCode=hashCode%numBuckets;
        }
        return hashCode%numBuckets;
    }
    void rehash(string key, V value){
        MapNode<V> ** temp = buckets;
        buckets=new MapNode<V> *[2*numBuckets];
        int oldNumBuckets=numBuckets;
        numBuckets*=2;
        siz=0;
        for(int i=0;i<oldNumBuckets;i++){              //This work is necessary as value of numbuckets is changing ... hence hashCOde%Numbuckets will return a different
            MapNode<V> * head=temp[i];                 //BucketIndex...
            while(head!=NULL){
                insert(head->key,head->value);
                head=head->next;
            }
            for(int i=0;i<oldNumBuckets;i++){
                MapNode<V> * head=temp[i];
                delete head;
            }
            delete [] temp;
        }
    }
  public:
    void insert(string key,V value){
        int bucketIndex = bucketindex(key);
        MapNode<V> * head=buckets[bucketIndex];
        while(head!=NULL){
            if(head->key==key){
                head->value=value;
                return;
            }
            head=head->next;
        }
        head=buckets[bucketIndex];
        MapNode<V> * node=new MapNode<V>(value,key);
        node->next=head;
        buckets[bucketIndex]=node;
        siz++;
        double loadFactor=(1.0 * siz)/numBuckets;
        if(loadFactor>0.7){
            rehash();
        }
    }
    V remove(string key){
         int bucketIndex=bucketindex(key);
         MapNode<V> * head=buckets[bucketIndex];
         MapNode<V> * prev=NUll;
         while(head!=NULL){
            if(head->key==key){
                if(prev==NULL){
                    buckets[bucketIndex]=head->next;

                }else{
                prev->next=head->next;


                }
                head->next=NULL;
                V val=head->value;
                delete head;
                siz--;
                return val;
            }
            prev=head;
            head=head->next;
         }
         return NULL;
    }
    V getValue(string key){
    int bucketIndex=bucketindex(key);
    MapNode<V> * head=buckets[bucketIndex];
    while(head!=NULL){
            if(head->key==key){
                return head->value;
            }
        head=head->next;
    }
    return NULL;
    }
};
// Time complexity is nearly O(1) for insert, remove and getValue functions since we ignore length of the key when number of total key value pairs in all buckets is large enough...
