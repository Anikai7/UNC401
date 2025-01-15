#include <iostream>

using namespace std;

void multiply(int matrix1[10][10],int matrix2[10][10]){
    int tem[10][10];
    for (int i=0;i<10;i++){
        for (int j=0;j<10;j++){
            tem[i][j]=0;
            for (int k=0;k<10;k++){
                tem[i][j]+=matrix1[i][k]*matrix2[k][j];
            }
        }
    }

    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            cout<<tem[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int matrix1[10][10],matrix2[10][10];

    multiply(matrix1,matrix2);

    return 0;
}