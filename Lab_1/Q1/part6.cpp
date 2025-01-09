#include<iostream>

using namespace std;

void reverse(int array[],int size){

    for(int i=0;i<size/2;i++){
        int tem=array[size-i-1];
        array[size-i-1] = array[i];
        array[i] = tem;
        
    }
}

int main(){
    int array[]= {1,2,3,4,5};
    int size = sizeof(array)/sizeof(array[0]);
    reverse(array,size);

    for(int i=0;i<size;i++){
        cout<<i<<": "<<array[i]<<endl;
    }
    return 0;
}