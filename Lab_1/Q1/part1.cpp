#include<iostream>

using namespace std;

void sumofintegers(){
    int first,last,sum=0;
    cout<<"Enetr first: ";
    cin>>first;
    cout<<"Enetr last: ";
    cin>>last;
    for(int i =first;i<=last;i++){
        sum+=i;
    }

    cout<<"Sum of numbers: "<<sum<<endl;
}

int main(){
    sumofintegers();
    return 0;
}