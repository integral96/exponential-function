#include <iostream>
#include <ctime>
#include <cmath>
#include "MyMatrix.h"
#include "ExpMatrix.h"
using namespace std;
int ExpMatrix::sizeP;
int ExpMatrix::num_map;
bool ExpMatrix::la =true;
double fact(int N)
{
    if(N<0) return 0;
    if(N==0) return 1;
    else return N*fact(N-1);
}
ExpMatrix::ExpMatrix(): mode(MATR)
{
        num_map++;
}
ExpMatrix::ExpMatrix(double x, Mode form):parr(nullptr)
{
    mode = form;
    if((sizeP<0)){cout<< "size error!!"; exit(0);}
    parr = new double[sizeP];
    if(form==DOUB){
    for(int i=0;i<sizeP;i++){
        parr[i]=pow(x,i)/fact(i);
        SummDoub+=parr[i];
        }
    }

    num_map++;
}

ExpMatrix::ExpMatrix(MyMatrix &mx, Mode form):marr(nullptr){
    mode = form;
    if((sizeP<0)){cout<< "size error!!"; exit(0);}
    marr = new MyMatrix[sizeP];
    if(form==MATR){
        MyMatrix ED;
        marr[0] = ED;
        for(int i=1;i<sizeP;i++){
            marr[i]=mx.PowArray(i-1)/fact(i-1);
            SummExp=SummExp+marr[i];
            }
    }
    num_map++;
}
void ExpMatrix::doub_mode(){mode = DOUB;}
void ExpMatrix::matr_mode(){mode = MATR;}
std::ostream & operator << (std::ostream & os, const ExpMatrix & px){
    if(px.mode==ExpMatrix::DOUB){
    for(int i = 0; i<ExpMatrix::sizeP;++i){
           if(px.parr[i]<0) os <<px.parr[i];
           else if(i==0) os <<px.parr[i];
           else os <<"+"<<px.parr[i];
    }
    os <<"\nSumm exp(double x) = "<<px.SummDoub<<endl;
    }
    else if (px.mode==ExpMatrix::MATR){
    for(int i = 0; i<ExpMatrix::sizeP;i++){

            if(i==0) os <<"\n"<<px.marr[i];
            else os <<"+\n"<<px.marr[i];
    }
    os <<"\nSumm exp(matrix A) = \n"<<px.SummExp<<endl;
    }
    else os <<"Matrix object mode is invalid";
    return os;

}
ExpMatrix::~ExpMatrix()
{
    //cout<<"DELETE PARR: "<<num_map--<<endl;
    //cout<<"DELETE MARR: "<<num_map--<<endl;
    delete [] parr;
    delete [] marr;
}
