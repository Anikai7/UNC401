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
    
}