#include<iostream>
using namespace std;

class rectangle{
    private:
        int length;
        int breath;
    public:
        rectangle(int l,int b){
            length = l;
            breath = b;
        }
        void area(){
            cout<<"Area: "<<length*breath<<endl;
        }
        void perimeter(){
            cout<<"Perimeter:"<<2*(length+breath)<<endl;
        }
};

int main(){
    rectangle r1(10,5);
    r1.area();
    r1.perimeter();
    return 0;
}