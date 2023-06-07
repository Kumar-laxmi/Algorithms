#include <cmath>
#include <iostream>
#include <fstream>
#include <gmpxx.h>

using namespace std;

struct PQT
{
    mpz_class P, Q, T;
};

class Chudnovsky
{
    mpz_class A, B, C, D, E, C3_24;  
    int DIGITS, PREC, N;             
    double DIGITS_PER_TERM;       
    clock_t t0, t1, t2;             
    PQT compPQT(int n1, int n2);   

public:
    Chudnovsky();                   
    void compPi();                   
};

Chudnovsky::Chudnovsky()
{
    DIGITS = 100;
    A      = 13591409;
    B      = 545140134;
    C      = 640320;
    D      = 426880;
    E      = 10005;
    DIGITS_PER_TERM = 14.1816474627254776555; 
    C3_24  = C * C * C / 24;
    N      = DIGITS / DIGITS_PER_TERM;
    PREC   = DIGITS * log2(10);
}

PQT Chudnovsky::compPQT(int n1, int n2)
{
    int m;
    PQT res;

    if (n1 + 1 == n2) {
        res.P  = (2 * n2 - 1);
        res.P *= (6 * n2 - 1);
        res.P *= (6 * n2 - 5);
        res.Q  = C3_24 * n2 * n2 * n2;
        res.T  = (A + B * n2) * res.P;
        if ((n2 & 1) == 1) res.T = - res.T;
    } else {
        m = (n1 + n2) / 2;
        PQT res1 = compPQT(n1, m);
        PQT res2 = compPQT(m, n2);
        res.P = res1.P * res2.P;
        res.Q = res1.Q * res2.Q;
        res.T = res1.T * res2.Q + res1.P * res2.T;
    }

    return res;
}

void Chudnovsky::compPi()
{
    cout << "**** PI Computation ( " << DIGITS << " digits )" << endl;

    // Time (start)
    t0 = clock();

    // Compute Pi
    PQT PQT = compPQT(0, N);
    mpf_class pi(0, PREC);
    pi  = D * sqrt((mpf_class)E) * PQT.Q;
    pi /= (A * PQT.Q + PQT.T);

    t1 = clock();
    cout << "TIME (COMPUTE): "
         << (double)(t1 - t0) / CLOCKS_PER_SEC
         << " seconds." << endl;

    ofstream ofs ("pi.txt");
    ofs.precision(DIGITS + 1);
    ofs << pi << endl;

    t2 = clock();
    cout << "TIME (WRITE)  : "
         << (double)(t2 - t1) / CLOCKS_PER_SEC
         << " seconds." << endl;
}

int main()
{
    try
    {
        Chudnovsky objMain;

        objMain.compPi();
    }
    catch (...) {
        cout << "ERROR!" << endl;
        return -1;
    }

    return 0;
}
