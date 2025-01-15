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
    int array[] = {3,4,53,5,3,2,5,7,8,4};
    int size = sizeof(array)/sizeof(array[0]);
    int key;
    cout<<"Enter key: ";
    cin>>key;
    linearSearch(array,size,key);
    return 0;
}