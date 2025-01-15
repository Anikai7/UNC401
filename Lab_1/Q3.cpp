#include<iostream>

using namespace std;

void addMatrix(int matrix1[3][3],int matrix2[3][3]){
    int result[3][3];
    for(int i = 0;i<3;i++){
        for(int j = 0;j<3;j++){
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    for(int i = 0;i<3;i++){
        for(int j = 0;j<3;j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
}

void subtractMatrix(int matrix1[3][3],int matrix2[3][3]){
    int result[3][3];
    for(int i = 0;i<3;i++){
        for(int j = 0;j<3;j++){
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
    for(int i = 0;i<3;i++){
        for(int j = 0;j<3;j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int matrix1[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    int matrix2[3][3] = {{9,8,7},{6,5,4},{3,2,1}};
    addMatrix(matrix1,matrix2);
    cout<<endl;
    subtractMatrix(matrix1,matrix2);
    return 0;
}