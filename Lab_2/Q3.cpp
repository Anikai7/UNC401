#include <iostream>
#include <climits>

using namespace std;

void findingElements(int arr[],int size){
    int n;
    cout<<"Enter Number of elements you want to find: ";
    cin>>n;

    for(int i=0;i<n;i++){
        int num;
        cout<<"Enter "<<i+1<<" number: ";
        cin>>num;
        for(int i=0;i<size;i++){
            if(arr[i]==num){
                cout<<"Number found at "<<i<<"th index"<<endl;
                break;
            }
        }
    }

    return;
}

void findSortedDuplicate(int arr[],int size){
    for(int i=1;i<size;i++){
        if(arr[i] == arr[i-1]){
            cout<<"Duplicate Array"<<endl;
        }
    }
}

void findDuplicate(int arr[],int size){
    int l1=0;

    while(l1<size){
        for(int i=1;i<size;i++){
            if(arr[l1] == arr[i]){
                cout<<"duplicate found"<<endl;
                return;
            }
        }
        l1++;
    }
}

void sumSortedK(int arr[],int size,int key){
    int l1=0,l2=size-1,sum;

    while(l1<l2){
        sum = arr[l1]+arr[l2];
        if(sum>key){
            l2--;
        }else if(sum<key){
            l1++;
        }else{
            cout<<"Element at "<<l1<<" and "<<l2<<endl;
            break;
        }
    }
}

void sumK(int arr[],int size,int key){
    int sum;

    for(int i=0;i<size;i++){
        for(int j=i+1;j<size;j++){
            if(arr[i]+arr[j]==key){
                cout<<"Element at "<<i<<" and "<<j<<endl;
            }
        }
    }
}

void minMax(int arr[],int size){
    int big = INT_MIN,sml=INT_MAX;

    for(int i=0;i<size;i++){
        if(arr[i]<sml){
            sml = arr[i];
        }
        
        if(arr[i]>big){
            big = arr[i];
        }
    }

    cout<<"min number: "<<sml<<endl;
    cout<<"max numebr: "<<big<<endl;
}

int main(){
    int arr[] = {1,2,3,4,5,6};
    size_t size = sizeof(arr)/sizeof(arr[0]);
    findingElements(arr,size);
    findDuplicate(arr,size);
    findSortedDuplicate(arr,size);
    sumK(arr,size,4);
    sumSortedK(arr,size,4);
    minMax(arr,size);
}