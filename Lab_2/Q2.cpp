#include <iostream>

using namespace std;

void display(int arr[],const size_t size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void sorted_array(int arr[],const size_t size){
    cout<<"Cheacking if array is sorted or not: ";
    for(int i=1;i<size;i++){
        if(arr[i]<arr[i-1]){
            cout<<"Not Sorted"<<endl;
            return;
        }
    }

    cout<<"Sorted"<<endl;
    return;
}

int* merge_array(int* arr1,int* arr2,const size_t size1,const size_t size2){
    cout<<"Merging array"<<endl;
    int* arr3 = new int[size1+size2];

    for(int i=0;i<size1;i++){
        arr3[i] = arr1[i];
    }

    for(int j=0;j<size2;j++){
        arr3[j+size1] = arr2[j];
    }

    display(arr3,size1+size2);

    return arr3;
}

void op_UI(int arr1[],int arr2[],const size_t size1,const size_t size2){
    int l1=0,l2=0;
    cout<<"Intersection of sets: ";
    for(int i=0;i<size1 && i<size2 ; i++){
        if(arr1[l1]<arr2[l2]){
            l1++;
        }else if(arr1[l1]>arr2[l2]){
            l2++;
        }else{
            cout<<arr1[i]<<" ";
        }
    }
    l1=0,l2=0;
    cout<<endl<<"Union of sets: ";
    for(int i=0;i<size1 && i<size2 ; i++){
        if(arr1[l1]<arr2[l2]){
            cout<<arr1[l1]<<" ";
            l1++;
        }else if(arr1[l1]>arr2[l2]){
            cout<<arr1[l2]<<" ";
            l2++;
        }else{
            cout<<arr1[l1]<<" ";
            l1++;
            l2++;
        }
    }
    if(l1<size1){
        for(int i=l1;i<size1;i++){
            cout<<arr1[i]<<" ";
        }
    }else if(l2<size2){
        for(int i=l2;i<size2;i++){
            cout<<arr2[i]<<" ";
        }
    }
    return;
}

int main(){
    int arr[] = {1,2,3};
    size_t size = sizeof(arr)/sizeof(arr[0]);

    sorted_array(arr,size);

    int arr2[] = {3,4,5};
    size_t size2 = sizeof(arr2)/sizeof(arr2[0]);

    size_t size3 = size+size2;
    int* arr3 = merge_array(arr,arr2,size,size2);
    
    display(arr3,size3);

    op_UI(arr,arr2,size,size2);

    free(arr3);
    return 0;
}