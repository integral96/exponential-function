#include <iostream>
#include <ctime>
#include <cmath>
#include <iomanip>
#include "MyMatrix.h"
using namespace std;

int MyMatrix::sizeN;
int MyMatrix::num_matx = 0;
MyMatrix::MyMatrix(): arr(nullptr)
{
    if((sizeN<0)){cout<< "size error!!"; exit(0);}
    arr = new double* [sizeN];
    for(int i = 0; i<sizeN;i++){
        arr[i] = new double [sizeN];    }

    for(int i = 0; i<sizeN;i++){
        for(int j = 0; j<sizeN;j++){
            arr[i][j] = 0;
            if(j==i) arr[i][j] = 1;
        }
    }
    num_matx++;
}
MyMatrix::MyMatrix(const MyMatrix &M): arr(nullptr){
    srand(time(0));
    if((sizeN<0)){cout<< "size error!!"; exit(0);}
    arr = new double* [sizeN];
    for(int i = 0; i<sizeN;i++){
        arr[i] = new double [sizeN];
    }
    for(int i = 0; i<sizeN;i++){
        for(int j = 0; j<sizeN;j++){
            arr[i][j] = M.arr[i][j]+(rand()%109-37)/10;
        }
    }
    num_matx++;
}
std::ostream & operator << (std::ostream & os, const MyMatrix & mx){
    for(int i = 0; i<MyMatrix::sizeN;++i){
        for(int j = 0; j<MyMatrix::sizeN;++j){
            os << setw(8)<<setprecision(4)<<mx.arr[i][j]<<" ";
            if(j==MyMatrix::sizeN-1) os<<endl;
        }
    }
    return os;
}
MyMatrix &MyMatrix::operator=(const MyMatrix &mx){
    if(this==&mx) return *this;

    for(int i = 0; i<sizeN;++i){
        for(int j = 0; j<sizeN;++j){
            arr[i][j] = mx.arr[i][j];
        }
    }
    return *this;
}
MyMatrix &MyMatrix::operator+(const MyMatrix &mx){
    for(int i = 0; i<sizeN;++i){
        for(int j = 0; j<sizeN;++j){
            arr[i][j] += mx.arr[i][j];
        }
    }
    return *this;
}
MyMatrix &MyMatrix::operator+(int a){
    for(int i = 0; i<sizeN;++i){
        for(int j = 0; j<sizeN;++j){
            arr[i][j] += a;
        }
    }
    return *this;
}
MyMatrix &MyMatrix::operator-(const MyMatrix &mx){
    for(int i = 0; i<sizeN;++i){
        for(int j = 0; j<sizeN;++j){
            arr[i][j] -= mx.arr[i][j];
        }
    }
    return *this;
}
MyMatrix &MyMatrix::operator*(const MyMatrix &mx){
    tmp = new double* [sizeN];
        for(int i = 0; i<sizeN;i++)
        tmp[i] = new double [sizeN];
        for (int i = 0; i<sizeN; i++)
            for (int j = 0; j<sizeN; j++)
                arr[i][j] = mx.arr[i][j];

        for (int i = 0; i<sizeN; i++)
            for (int j = 0; j<sizeN; j++)
                for (int k = 0; k<sizeN; k++)
                    tmp[i][j] += mx.arr[i][k] * arr[k][j];

        for (int i = 0; i<sizeN; i++)
            for (int j = 0; j<sizeN; j++)
            {   mx.arr[i][j] = tmp[i][j];
                tmp[i][j] = 0;
            }
            for(int i = 0; i<sizeN; i++) delete [] tmp[i];
        delete [] tmp;
    return *this;
}

MyMatrix &MyMatrix::PowArray (const int N)
{   int m, n, k, p = 1;
    tmp = new double* [sizeN];
    for(m = 0; m<sizeN;m++)
        tmp[m] = new double [sizeN];
    for (m = 0; m<sizeN; m++)
            for (n = 0; n<sizeN; n++)
                this->arr[m][n] = arr[m][n];

    while (p++ <= N)
    {   for (m = 0; m<sizeN; m++)
            for (n = 0; n<sizeN; n++)
                for (k = 0; k<sizeN; k++)
                    tmp[m][n] += this->arr[m][k] * arr[k][n];

        for (m = 0; m<sizeN; m++)
            for (n = 0; n<sizeN; n++)
            {   this->arr[m][n] = tmp[m][n];
                tmp[m][n] = 0;
            }
    }
            for(int i = 0; i<sizeN; i++) delete [] tmp[i];
        delete [] tmp;
    return *this;
}
MyMatrix &MyMatrix::operator*(double b){
    for (int i = 0; i<sizeN; i++)
            for (int j = 0; j<sizeN; j++)
                arr[i][j] = this->arr[i][j];
    for(int i = 0; i<sizeN;i++){
        for(int j = 0; j<sizeN;j++){
            arr[i][j]*=b;
        }
    }
    return *this;
}
MyMatrix &MyMatrix::operator/(double b){
    for(int i = 0; i<sizeN;i++){
        for(int j = 0; j<sizeN;j++){
            arr[i][j]/=b;
        }
    }
    return *this;
}
MyMatrix::~MyMatrix()
{
    num_matx--;
    //cout<<"DELETE ARR: "<<num_matx<<endl;
    for(int i = 0; i<sizeN; i++) delete [] arr[i];
    delete [] arr;
}
