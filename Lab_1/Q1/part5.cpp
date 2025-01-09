#include<iostream>

using namespace std;

void englishCvt(int x){

    switch (x)
    {
    case 1:
        cout<<"One"<<endl;
        /* code */
        break;
    case 2:
        cout<<"Two"<<endl;
        /* code */
        break;
    case 3:
        cout<<"Three"<<endl;
        /* code */
        break;
    case 4:
        cout<<"Four"<<endl;
        /* code */
        break;
    case 5:
        cout<<"Five"<<endl;
        /* code */
        break;
    case 6:
        cout<<"Six"<<endl;
        /* code */
        break;
    case 7:
        cout<<"Seven"<<endl;
        /* code */
        break;
    case 8:
        cout<<"Eight"<<endl;
        /* code */
        break;
    case 9:
        cout<<"Nine"<<endl;
        /* code */
        break;
    
    default:
        cout<<"Enter a valid number"<<endl;
        break;
    }
}

int main(){
    englishCvt(5);
    return 0;
}