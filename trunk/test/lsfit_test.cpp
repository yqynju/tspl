/*****************************************************************************
 *                               lsfit_test.cpp
 *
 * Least square fitting testing.
 *
 * Zhang Ming, 2010-04
 *****************************************************************************/


#define BOUNDS_CHECK

#include <iostream>
#include <lsfitting.h>
#include <utilities.h>


using namespace std;
using namespace itlab;


int main()
{
    double  A = 4.0,
            alpha = 1.0,
            beta = -2.0,
            gamma = -4.0,
            tmp = 0.0;

    int M = 100;
    Vector<double> x = linspace( 0.01, 0.5*PI, M );
    Vector<double> y(M);
    for( int i=0; i<M; ++i )
    {
        tmp = A * pow(x[i],alpha) * exp(beta*x[i]+gamma*x[i]*x[i]);
        y[i] = log(max(tmp,EPS));
    }

    Funcs<double> phi;
    LSFitting<double> lsf( x, y, phi );
    lsf.calcCoefs();
    Vector<double> parms = lsf.getCoefs();
    parms(1) = exp(parms(1));

    cout << parms << endl;
    return 0;
}
