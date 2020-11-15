#include<iostream>

class polynomial{
    int *data;
    int  size;
    public:
    polynomial(){
        data=new int[5];
        size=5;
        initialize(5,data);
    }
    void initialize(int size,int *data){
        for(int i=0;i<size;i++){
            data[i]=0;
        }
    }
    void fit(int coeff,int deg=0){
        if(deg>=size){
            if(deg<size*2){
            int *newData=new int[size*2];
            initialize(size*2,newData);
            for(int i=0;i<size;i++){
                newData[i]=data[i];
            }
            size*=2;
            delete [] data;
            data=newData;
            data[deg]=coeff;
            }
            else{
                size=deg+1;
                fit(coeff,deg);
            }
            
        }
        else{
            data[deg]=coeff;
        }
    }
    void display();
    polynomial operator+(polynomial const &p2){
        polynomial p3;
        initialize(p3.size,p3.data);
        if(p2.size>size){
          for(int i=0;i<size;i++){
        if(i>=p3.size)
            p3.fit(data[i]+p2.data[i],i);
        else 
            p3.data[i]=data[i]+p2.data[i];
    }
    for(int i=size;i<p2.size;i++){
        if(i>=p3.size)
            p3.fit(p2.data[i],i);
        else 
            p3.data[i]=p2.data[i];
    }
        }
        else{
    for(int i=0;i<p2.size;i++){
        if(i>=p3.size)
            p3.fit(data[i]+p2.data[i],i);
        else 
            p3.data[i]=data[i]+p2.data[i];
    }
    for(int i=p2.size;i<size;i++){
        if(i>=p3.size)
            p3.fit(data[i],i);
        else 
            p3.data[i]=data[i];
    }
        }
    return p3;
    }
    polynomial operator*(polynomial const &p2){
        polynomial c3;
       
        initialize(c3.size,c3.data);
        for(int i=0;i<size;i++){
            for(int j=0;j<p2.size;j++){
                if(data[i]!=0 && p2.data[j]!=0){
                    if(i+j>=c3.size){
                        c3.fit(data[i]*p2.data[j],i+j);
                    
                    }
                    else{
                        c3.data[i+j]+=data[i]*p2.data[j];
                    }
                }
            }
        }
        return c3;
    }
   
};
void polynomial :: display(){
    for(int i=0;i<size;i++){
        if(data[i]!=0){
            if(i==0){
                
                std::cout<<data[i]<<" ";
            }
            else{
                if(data[i]>0){
            std::cout<<"+ "<<data[i]<<"X"<<i<<" ";
            }
            else{
                std::cout<<data[i]<<"X"<<i<<" ";
            }
        }
    }
    }
    std::cout<<std::endl;
}

int main(){
    polynomial p1;
    polynomial p2;
    p1.fit(-3);
    p1.fit(1,1);
    p1.fit(1,2);
    p2.fit(1,1);
    p1.fit(-2,3);
    p2.fit(-3);
    p2.fit(-3,6);
    polynomial p3=p1 + p2;
    p1.display();
    p2.display();
    p3.display();
    //polynomial c3=p1*p2;
    //c3.display();
    return 0;
}