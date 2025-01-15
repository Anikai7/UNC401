#include<iostream>

using namespace std;

void append(int array1[],int array2[],int size1,int size2){
    int array3[size1+size2];

    for(int i=0;i<size1;i++){
        array3[i] = array1[i];
    }
    for(int i=0;i<size2;i++){
        array3[size1+i] = array2[i];
    }
    for(int i = 0;i<size1+size2;i++){
        cout<<array3[i]<<endl;
    }
}

int main(){
    int array1[] = {1,2,3,4,5};
    int array2[] = {6,7,8,9,10};
    int size1 = sizeof(array1)/sizeof(array1[0]);
    int size2 = sizeof(array2)/sizeof(array2[0]);
    append(array1,array2,size1,size2);
}