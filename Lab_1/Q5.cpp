#include<iostream>

using namespace std;

void linearSearch(int array[],int size,int key){

    for(int i=0;i<size;i++){
        if(array[i]== key){
            cout<<"Element at index: "<<i<<endl;
            return;
        }
    }
    cout<<"Element not found"<<endl;
    return;
}

int main(){
    int array[] = {1,2,3,4,5,6,7,8,9};
    int size = sizeof(array)/sizeof(array[0]);
    linearSearch(array,size,5);
}