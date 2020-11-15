#include<string>
using namespace std;
class data{
    public:
    string desgn;
    int age,salary;
    char sex;
    bool marital_status;
    public:
    void filler();
    void display();

};
class mdata : public data{
    public:
     void change();
};