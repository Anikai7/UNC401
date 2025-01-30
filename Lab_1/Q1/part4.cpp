#include<iostream>
#include <climits>

using namespace std;

void prime(){
    int x;
    cout<<"Enter number: ";
    cin>>x;

    for(int i=2;i<x;i++){
        if(x%i == 0){
            cout<<"Not prime"<<endl;
            return;
        }
    }

    cout<<"Prime"<<endl;
}

int main(){
    prime();
    return 0;
}