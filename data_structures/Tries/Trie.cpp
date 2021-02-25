#include<iostream>
#include<cstdio>

using namespace std;
class Trie{
    public:
    char data;
    Trie ** children;      //Since we want to store address of children we need to have data type of this arr as "Trie *" and "*children"
                         // is the pointer storing address of first index of type Trie * hence Trie**children is used...

    bool endpt;
    Trie(char data){
        this->data=data;
        children=new Trie *[26];
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
        endpt=false;
    }

};
