#include<iostream>

using namespace std;

void sumElements(int array[],int size){
    int sum = 0;
    for(int i = 0;i<size;i++){
        sum+=array[i];
    }
    cout<<"Sum of elements: "<<sum<<endl;
}

int main(){
    int array[] = {3,4,53,5,3,2,5,7,8,4};
    int size = sizeof(array)/sizeof(array[0]);
    sumElements(array,size);
    return 0;
}