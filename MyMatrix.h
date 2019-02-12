#ifndef MYMATRIX_H
#define MYMATRIX_H


class MyMatrix
{
    public:
        static int sizeN;
        MyMatrix();
        MyMatrix(const MyMatrix &M);
        virtual ~MyMatrix();
        MyMatrix &operator+(const MyMatrix &mx);
        MyMatrix &operator+(int a);
        MyMatrix &operator-(const MyMatrix &mx);
        MyMatrix &operator*(const MyMatrix &mx);
        MyMatrix &operator=(const MyMatrix &mx);
        MyMatrix &operator*(double b);
        MyMatrix &operator/(double b);
        MyMatrix &PowArray (const int N);
        friend std::ostream & operator << (std::ostream & os, const MyMatrix & mx);
    protected:

    private:
        double **arr;
        double **tmp;

        static int num_matx;
        static const int NLIM = 80;

};

#endif // MYMATRIX_H
