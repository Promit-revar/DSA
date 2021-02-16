#include<iostream>
#include<vector>

using namespace std;
template<typename T>
class priority_q{
    vector<T> pq;
public:
    bool isempty(){
    return pq.size()==0;
    }
    int len(){
    return pq.size();
    }
    void insert(T data){
        pq.push_back(data);
        int insIn=pq.size()-1;
        int pin=0;
        if(insIn%2==0){
           pin=(insIn-2)/2;
        }
        else{
           pin =(insIn-1)/2;
        }

        while(pin>=0){
            if(pq.at(insIn)<pq.at(pin)){
               pq.at(insIn)=pq.at(pin);
               pq.at(pin)=data;
               insIn=pin;
               if(insIn%2==0) pin=(insIn-2)/2;
              else pin =(insIn-1)/2;
            }
            else
                break;
        }
    }
    T removeMin(){
        if(isempty()){
            return -1;
        }
        T temp=pq.at(0);
        pq.at(0)=pq.at(pq.size()-1);
        pq.pop_back();
        int rtinx=0;
        T k;
        while(pq.at(2*rtinx+1)<pq.at(rtinx) || pq.at(2*rtinx+2)<pq.at(rtinx)){
                if(pq.at(2*rtinx+1)<pq.at(2*rtinx+2)){
                    k=pq.at(2*rtinx+1);
                    pq.at(2*rtinx+1)=pq.at(rtinx);
                    pq.at(rtinx)=k;
                }
                else{
                    k=pq.at(2*rtinx+2);
                    pq.at(2*rtinx+2)=pq.at(rtinx);
                    pq.at(rtinx)=k;
                }

        }
        return temp;

    }
    void display(){
        int i=0;
        while(i<len()){

           cout<< pq.at(i)<<" ";
           i++;
        }
        cout<<endl;
    }

};
int main(){
    priority_q<int> *q=new priority_q<int>();
    q->insert(10);
    q->insert(100);
    q->insert(12);

    q->insert(200);
    q->insert(400);
    q->insert(18);
    q->insert(15);
    q->display();
    cout<<q->removeMin()<<endl;
    //cout<<q->removeMin()<<endl;
    //cout<<q->removeMin()<<endl;
    q->display();
  return 0;
}
