#ifndef EXPMATRIX_H
#define EXPMATRIX_H
#include "MyMatrix.h"

class ExpMatrix : public MyMatrix
{
    public:
        enum Mode {DOUB, MATR};
        static bool la;
        static int sizeP;
        ExpMatrix();
        ExpMatrix(double x, Mode form = DOUB);
        ExpMatrix(MyMatrix &mx, Mode form = MATR);
        virtual ~ExpMatrix();
        //void reset();
        void doub_mode();
        void matr_mode();
        friend double fact(int);
        friend std::ostream & operator << (std::ostream & os, const ExpMatrix & px);

        //friend operator += ()
    protected:

    private:
        Mode mode;
        double *parr;
        MyMatrix *marr;
        double SummDoub;
        MyMatrix SummExp;
        static int num_map;

};

#endif // EXPMATRIX_H
