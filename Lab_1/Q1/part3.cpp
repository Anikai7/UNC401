#include<iostream>
#include <climits>

using namespace std;

void gcd(int x,int y){
    int gcd = 0;
    if(x>=y){
        for(int i=1;i<=x;i++){
            if(x%i == 0 && y%i == 0){
                gcd = max(gcd,i);
            }
        }

        cout<<"gcd: "<<gcd<<endl;
    }else{
        for(int i=1;i<=y;i++){
            if(x%i == 0 && y%i == 0){
                gcd = max(gcd,i);
            }
        }

        cout<<"gcd: "<<gcd<<endl;
    }
}

int main(){
    gcd(5,10);
    return 0;
}