#include<iostream>
#include <climits>

using namespace std;

void smallestN(){
    int goal,sum=0;
    cout<<"Enter goal: "<<endl;
    cin>>goal;

    for(int i=0;i<=goal;i++){
        sum+=i;
        if(sum>=goal){
            cout<<"smallest N: "<<i<<endl;
            return;
        }
    }
}

int main(){
    smallestN();
    return 0;
}