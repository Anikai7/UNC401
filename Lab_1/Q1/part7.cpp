#include<iostream>
#include <climits>

using namespace std;

void largest(int array[],int size){
    int largest=INT_MIN,idx;

    for(int i=0;i<size;i++){
        if(array[i]>largest){
            largest = max(array[i],largest);
            idx = i;
        }
    }

    cout<<"Largest number at index: "<<idx<<endl;
}

int main(){
    int array[]= {1,2,3,4,5};
    int size = sizeof(array)/sizeof(array[0]);
    largest(array,size);
    return 0;
}