#include <iostream>

using namespace std;

void largest(int array[],int size){
    int max = array[0];
    for(int i = 1;i<size;i++){
        if(array[i]>max){
            max = array[i];
        }
    }
    cout<<"Largest element: "<<max<<endl;
}

int main(){
    int array[] = {3,4,53,5,3,2,5,7,8,4};
    int size = sizeof(array)/sizeof(array[0]);
    largest(array,size);
    return 0;
}