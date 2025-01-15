#include<iostream>

using namespace std;

void linearSearch(int array[],int size,int key){
    for(int i = 0;i<size;i++){
        if(array[i]==key){
            cout<<"Element found at index: "<<i<<endl;
            return;
        }
    }
    cout<<"Element not found"<<endl;
}

int main(){
    int array[] = {1,3,2,4,7,8,9,6,5};
    int size = sizeof(array)/sizeof(array[0]);
    int key;
    cout<<"Enter key: ";
    cin>>key;
    linearSearch(array,size,key);
    return 0;
}