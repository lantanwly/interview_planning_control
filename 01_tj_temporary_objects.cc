#include<iostream>
#include<vector>
using namespace std;

//新建一个Class
class Person{
public:
    int age=18;
    
    int getAge(void){
        return age;
    }
};

int main(){

    Person p;
    int a=p.getAge();
    // p.getAge()=16;
    cout<<a<<endl;
    cout<<p.getAge()<<endl;
    return 0;
}