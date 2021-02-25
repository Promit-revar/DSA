#include "Trie.cpp";
#include<iostream>
#include<string>
using namespace std;
class trieNode{
    Trie * root;
public:
    trieNode(){
        root=new Trie('\0');
    }
    void insertin(Trie * root,string s){
        //Base condition
         if(s.size()==0){
            root->endpt=true;
            return;
         }
         //Small calculation
         int index=s[0]-'a';
         Trie * child;
         if(root->children[index]!=NULL){
            child= root->children[index];
         }
         else{
            child=new Trie(s[0]);
            root->children[index]=child;
         }
         //Recursive call
         insertin(child,s.substr(1));
    }
     void insertin(string word){
     insertin(root,word);
     }
     bool searchin(Trie * root,string word){
         if(word.size()==0)
            return root->endpt;
         int index=word[0]-'a';
         if(root->children[index]!=NULL){
            searchin(root->children[index],word.substr(1));
         }
         else{
            return false;
         }
     }
     bool searchin(string word){
          return searchin(root,word);
     }
     void remove(Trie * root,string word){
          if(word.size()==0){
            root->endpt=false;
          }
          int index=word[0]-'a';
          if(root->children[index]!=NULL){
            remove(root->children[index],word.substr(1));
            if(!root->children[index]){
                for(int i=0;i<26;i++){
                    if(root->children[index]->children[i]!=NULL){
                        return;
                    }
                }
                delete root->children[index];
                root->children[index]=NULL;
            }
          }
          else{
                // Word not found...
            return ;
          }
     }
     void remove(string word){
        remove(word);
     }
};
int main(){
    trieNode t;
    t.insertin("and");
    t.insertin("are");
    t.insertin("dot");
    cout<<t.searchin("ann")<<endl;
    //t.remove("and");
    //cout<<t.searchin("and");
return 0;
}
