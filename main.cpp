#include <iostream>
#include "MyMatrix.h"
#include "ExpMatrix.h"
using namespace std;

int main()
{
    double x;
    ExpMatrix::sizeP = 5;
    cout << "Enter N, Dimension matrix: " ;
    cin>>MyMatrix::sizeN;
    cout << "Enter X, double: " ;
    cin>>x;
    //MyMatrix::sizeN = 4;
    MyMatrix E, E1;
    MyMatrix A1(E), A2(A1);
    ExpMatrix obj1(x);
    cout << "Taylor series exp(double x="<<x<<") = "<< obj1<<endl;
    ExpMatrix obj2(A1);
    cout << "Taylor series exp(matrix) = "<< obj2<<endl;

    return 0;
}
