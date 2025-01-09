#include<iostream>

using namespace std;

void shiftRight(int array[],int size){
    int tem = array[size-1];
    for(int i=size-1;i>=0;i--){
        if(i!=0){
            array[i] = array[i-1];
        }else{
            array[i] = tem;
        }
    }


    for(int i=0;i<size;i++){
        cout<<array[i]<<endl;
    }
}

int main(){
    int array[]= {1,2,3,4,5};
    int size = sizeof(array)/sizeof(array[0]);
    shiftRight(array,size);
}