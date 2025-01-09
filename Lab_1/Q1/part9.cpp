#include<iostream>

using namespace std;

void sort(int array[],int size){

}

void duplicate(int array[],int size){
    sort(array,size);

}

int main(){
    int array[] = {3,4,53,5,3,2,5,7,8,4};
    int size = sizeof(array)/sizeof(array[0]);
    duplicate(array,size);
    return 0;
}