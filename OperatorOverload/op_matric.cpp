#include <iostream>
using namespace std;
class Matrix{
    int row[5]; 
    int col[5];
    public:
        void setMatrix(int row1[5] , int col1[5]);
        void display();
        Matrix operator+(Matrix m);
};
void Matrix::setMatrix(int row1[],int col1[]){
    for(int i = 0 ; i<5 ; i++){
        row[i] = row1[i];
    }
}