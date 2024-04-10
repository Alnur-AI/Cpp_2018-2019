#include "C:\mexCpp\include\mex.h"
#include <math.h>
#include "C:\mexCpp\include\matrix.h"
#include <complex.h>
#include <complex>
#include <iostream>

using namespace std;
//cpow(z,1/3)

double * csum(double a1, double b1, double a2, double b2)
{
    double * result = (double *)malloc(sizeof(double)*2);
    result[0] = a1+a2;
    result[1] = b1+b2;
    return result;
}

double * cdiff (double a1, double b1, double a2, double b2)
{
double * result = (double *)malloc(sizeof(double)*2);
result[0] = a1 - a2;
result[1] = b1 - b2;
return result;
}

double * cdiv(double a1, double b1, double a2, double b2)
{
    double * result = (double *)malloc(sizeof(double)*2);
    result[0] = (a1*a2+b1*b2)/(a2*a2+b2*b2);
    result[1] = (a2*b1-a1*b2)/(a2*a2+b2*b2);
    return result;
}

double * cmul (double a1, double b1, double a2, double b2)
{
    double * result = (double *)malloc(sizeof(double)*2);
    result[0] = a1 * a2 - b1 * b2;
    result[1] = a1 * b2 + b1 * a2;
    return result;
}

double * croot(double a, double b, int power)
{
    double sum = a*a+b*b;
    //mexPrintf("sum: %f\n", sum);
    double absolute = pow(sum, 0.5);
    double rootpower = 1/(double)power;
    //mexPrintf("rootpower: %f\n", rootpower);
    double rootabs = pow(absolute, rootpower);
    //mexPrintf("absolute: %f\n", absolute);
    //mexPrintf("rootabs: %f\n", rootabs);
    double fi;
    if (a > 0 && b >= 0)
        fi = atan(b / a);
    else if (a > 0 && b < 0)
        fi = 6.2832 + atan(b / a);
    else if (a < 0)
        fi = 3.14159 + atan(b / a);
    else if (a == 0 && b > 0)
        fi = 1.5708;
    else
        fi = -1.5708;
    //mexPrintf("argument: %f\n", fi);
    double * result = (double*)malloc(sizeof(double)*2*power);
    int i;
    for(i = 0; i < power; i++)
    {
       // mexPrintf("!\n");
        result[2*i] = rootabs*cos(fi/power+i*6.2832/power);
        result[2*i+1] = rootabs*sin(fi/power+i*6.2832/power);
    }
    return result;

}

void cubesolvee(mxArray const * A, mxArray const * B, mxArray const * C, mxArray * X1, mxArray * X2, mxArray * X3, mwSize ncols, mwSize nrows)
{
    mwSize i;
    i = 0;
    mxComplexDouble * AA = mxGetComplexDoubles(A);
    mxComplexDouble * BB = mxGetComplexDoubles(B);
    mxComplexDouble * CC = mxGetComplexDoubles(C);
    mexPrintf("MyComplex %f + i%f\n", AA[0].real, AA[0].imag);
    mxComplexDouble * X11 = mxGetComplexDoubles(X1);
    mxComplexDouble * X12 = mxGetComplexDoubles(X2);
    mxComplexDouble * X13 = mxGetComplexDoubles(X3);
    double t1r = 0;
    //mexPrintf("Myt1 %f + i%f\n", &t1.real, &t1.imag);
    double t1i = 0;
    double t2r = 0;
    double t2i = 0;
    double deter = 0;
    double deteri = 0;
    double pr;
    double qr;
    double pi;
    double qi;
    double pcr;
    double qsr;
    double pci;
    double qsi;
    double detersqr;
    double detersqi;
    double fir = 0;
    double fii = 0;
    for(i = 0; i < ncols*nrows; i++)
    {
        double * result = cdiv(BB[i].real, BB[i].imag, AA[i].real,AA[i].imag);
        pr = result[0];
        pi = result[1];
        free(result);

        result = cdiv(CC[i].real,CC[i].imag, AA[i].real,AA[i].imag);
        qr = result[0];
        qi = result[1];
        free(result);

        qr = qr/2;
        qi = qi/2;
        pr = pr/3;
        pi = pi/3;
        mexPrintf("Ps %f + i%f\n", pr, pi);
        mexPrintf("Qs %f + i%f\n", qr, qi);

        result = cmul(qr,qi, qr,qi);
        qsr = result[0];
        qsi = result[1];
        free(result);

        result = cmul(pr,pi, pr,pi);
        pcr = result[0];
        pci = result[1];
        free(result);

        result = cmul(pcr,pci, pr,pi);
        pcr = result[0];
        pci = result[1];
        free(result);
        mexPrintf("PCs %f + i%f\n", pcr, pci);

        result = csum(qsr,qsi, pcr,pci);
        deter = result[0];
        deteri = result[1];
        free(result);

        mexPrintf("Deters %f + i%f\n", deter, deteri);

        result = croot(deter, deteri, 2);
        detersqr = result[0];
        detersqi = result[1];
        free(result);
        mexPrintf("Derersqs %f + i%f\n", detersqr, detersqi);

        qr *= -1;
        qi *= -1;

        result = csum(qr,qi, detersqr,detersqi);
        t1r = result[0];
        t1i = result[1];
        free(result);
        mexPrintf("T1s %f + i%f\n", t1r, t1i);

        result = cdiff(qr,qi, detersqr,detersqi);
        t2r = result[0];
        t2i = result[1];
        free(result);
        mexPrintf("T2s %f + i%f\n", t2r, t2i);

        result = croot(t1r,t1i, 3);
        X11[i].real = result[0];
        X11[i].imag = result[1];
        X12[i].real = result[2];
        X12[i].imag = result[3];
        X13[i].real = result[4];
        X13[i].imag = result[5];
        mexPrintf("X1s %f + i%f    %f + i%f    %f + i%f\n", result[0], result[1], result[2], result[3], result[4], result[5]);
        free(result);

        result = croot(t2r,t2i, 3);

        if(pr<=0 && pi<=0 && qr>=0 && qi>0)
        {
            //0
            mexPrintf("<<<< %f\n", pr);
            X11[i].real += result[0];
            X11[i].imag += result[1];
            X12[i].real += result[4];
            X12[i].imag += result[5];
            X13[i].real += result[2];
            X13[i].imag += result[3];
        }
        else if(pr<=0 && pi<=0 && qr>=0 && qi<=0)
        {
            //1-yes
            mexPrintf("<<<> %f\n", pr);
            X11[i].real += result[4];
            X11[i].imag += result[5];
            X12[i].real += result[2];
            X12[i].imag += result[3];
            X13[i].real += result[0];
            X13[i].imag += result[1];
        }
        else if(pr<=0 && pi<0 && qr<=0 && qi>=0)
        {
            //2-yes
            mexPrintf("<<><\n");
            X11[i].real += result[4];
            X11[i].imag += result[5];
            X12[i].real += result[2];
            X12[i].imag += result[3];
            X13[i].real += result[0];
            X13[i].imag += result[1];
        }
        else if(pr<=0 && pi<=0 && qr<=0 && qi<=0)
        {
            //3
            mexPrintf("<<>>\n");
            X11[i].real += result[4];
            X11[i].imag += result[5];
            X12[i].real += result[2];
            X12[i].imag += result[3];
            X13[i].real += result[0];
            X13[i].imag += result[1];
        }
        else if(pr<0 && pi>=0 && qr>=0 && qi>=0)
        {
            //4
            mexPrintf("<><<\n");
            X11[i].real += result[4];
            X11[i].imag += result[5];
            X12[i].real += result[2];
            X12[i].imag += result[3];
            X13[i].real += result[0];
            X13[i].imag += result[1];
        }
        else if(pr<=0 && pi>=0 && qr>=0 && qi<=0)
        {
            //5-yes
            mexPrintf("<><> %f\n", pr);
            X11[i].real += result[2];
            X11[i].imag += result[3];
            X12[i].real += result[0];
            X12[i].imag += result[1];
            X13[i].real += result[4];
            X13[i].imag += result[5];
        }
        else if(pr=0 && pi>=0 && qr<=0 && qi>=0)
        {
            //6-yes
            mexPrintf("<>><\n");
            X11[i].real += result[4];
            X11[i].imag += result[5];
            X12[i].real += result[2];
            X12[i].imag += result[3];
            X13[i].real += result[0];
            X13[i].imag += result[1];
        }
        else if(pr<=0 && pi>=0 && qr<=0 && qi<=0)
        {
            //7
            mexPrintf("<>>>\n");
            X11[i].real += result[2];
            X11[i].imag += result[3];
            X12[i].real += result[0];
            X12[i].imag += result[1];
            X13[i].real += result[4];
            X13[i].imag += result[5];
        }
        else if(pr>=0 && pi<=0 && qr>=0 && qi>=0)
        {
            //8-yes
            mexPrintf("><<<\n");
            X11[i].real += result[0];
            X11[i].imag += result[1];
            X12[i].real += result[4];
            X12[i].imag += result[5];
            X13[i].real += result[2];
            X13[i].imag += result[3];
        }
        else if(pr>=0 && pi<=0 && qr>=0 && qi<=0)
        {
            //9
            mexPrintf("><<>\n");
            X11[i].real += result[0];
            X11[i].imag += result[1];
            X12[i].real += result[4];
            X12[i].imag += result[5];
            X13[i].real += result[2];
            X13[i].imag += result[3];
        }
        else if(pr>=0 && pi<0 && qr<=0 && qi>=0)
        {
            //10-yes
            mexPrintf("><><\n");
            X11[i].real += result[0];
            X11[i].imag += result[1];
            X12[i].real += result[4];
            X12[i].imag += result[5];
            X13[i].real += result[2];
            X13[i].imag += result[3];
        }
        else if(pr>=0 && pi<=0 && qr<=0 && qi<=0)
        {
            //11-yes
            mexPrintf("><>>\n");
            X11[i].real += result[2];
            X11[i].imag += result[3];
            X12[i].real += result[0];
            X12[i].imag += result[1];
            X13[i].real += result[4];
            X13[i].imag += result[5];
        }
        else if(pr>=0 && pi>=0 && qr>=0 && qi>=0)
        {
            //12-yes
            mexPrintf(">><<\n");
            X11[i].real += result[2];
            X11[i].imag += result[3];
            X12[i].real += result[0];
            X12[i].imag += result[1];
            X13[i].real += result[4];
            X13[i].imag += result[5];
        }
        else if(pr>=0 && pi>=0 && qr>=0 && qi<=0)
        {
            //13
            mexPrintf(">><>\n");
            X11[i].real += result[0];
            X11[i].imag += result[1];
            X12[i].real += result[4];
            X12[i].imag += result[5];
            X13[i].real += result[2];
            X13[i].imag += result[3];
        }
        else if(pr>=0 && pi>=0 && qr<=0 && qi>=0)
        {
            //14-yes
            mexPrintf(">>><\n");
            X11[i].real += result[2];
            X11[i].imag += result[3];
            X12[i].real += result[0];
            X12[i].imag += result[1];
            X13[i].real += result[4];
            X13[i].imag += result[5];
        }
        else if(pr>=0 && pi>=0 && qr<=0 && qi<=0)
        {
            //15-yes
            mexPrintf(">>>>\n");
            X11[i].real += result[2];
            X11[i].imag += result[3];
            X12[i].real += result[0];
            X12[i].imag += result[1];
            X13[i].real += result[4];
            X13[i].imag += result[5];
        }
        mexPrintf("X1s %f + i%f    %f + i%f    %f + i%f\n", result[0], result[1], result[2], result[3], result[4], result[5]);
        free(result);
    }
    //X11[0].real = AA[0].real-BB[0].real;
    //X12[0].real = 11;
    /*double * result = cdiff(AA[0].real, AA[0].imag, BB[0].real, BB[0].imag);
    double * root = croot(AA[0].real, AA[0].imag, 3);
    X12[0].real = root[0];
    X12[0].imag = root[1];
    X13[0].real = root[2];
    X13[0].imag = root[3];
    X11[0].real = root[4];
    X11[0].imag = root[5];*/

    //X13[0].real = result[0];
    //X13[0].imag = result[1];
    //*X3 = 0;
}

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    size_t ncols_A = mxGetM(prhs[0]);
    size_t nrows_A = mxGetN(prhs[0]);
    size_t ncols_B = mxGetM(prhs[1]);
    size_t nrows_B = mxGetN(prhs[1]);
    size_t ncols_C = mxGetM(prhs[2]);
    size_t nrows_C = mxGetN(prhs[2]);

    if(ncols_A != ncols_B || ncols_B != ncols_C || nrows_A != nrows_B || nrows_B != nrows_C)
    {
        mexErrMsgIdAndTxt("nrows\ncols", "dimensions must be same");
    }

    mwSize dbg;
    if(nrhs != 3)
    {
        mexErrMsgIdAndTxt("nrhs", "two inputs required");
    }
    if(nlhs != 3)
    {
        mexErrMsgIdAndTxt("nlhs", "one output reqiured");
    }
    //mxComplexDouble * Ar = mxGetComplexDoubles(prhs[0]);
    //mxComplexDouble * Br = mxGetComplexDoubles(prhs[1]);
    //mxComplexDouble * Cr = mxGetComplexDoubles(prhs[2]);

    plhs[0] = mxCreateDoubleMatrix((mwSize)nrows_A, (mwSize)ncols_A, mxCOMPLEX);
    plhs[1] = mxCreateDoubleMatrix((mwSize)nrows_A, (mwSize)ncols_A, mxCOMPLEX);
    plhs[2] = mxCreateDoubleMatrix((mwSize)nrows_A, (mwSize)ncols_A, mxCOMPLEX);

    //cubesolvee(Ar, Br, Cr, plhs[0], plhs[1], plhs[2], (mwSize)ncols_A, (mwSize)nrows_A);
    cubesolvee(prhs[0], prhs[1], prhs[2], plhs[0], plhs[1], plhs[2], (mwSize)ncols_A, (mwSize)nrows_A);
}
