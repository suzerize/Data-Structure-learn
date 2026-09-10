#include<stdio.h>

typedef struct
{
	double realpart;
	double imagpart;
}Complex;

void assign__0103(Complex* A, double real, double imag);
Complex add__0103(Complex* A, double real, double imag);
Complex minus__0103(Complex* A, double real, double imag);
Complex multiply__0103(Complex* A, double real, double imag);
Complex divide__0103(Complex* A, double real, double imag);
int main__0103()
{
	
	return 0;
}

void assign__0103(Complex* A, double real, double imag)
{
	A->imagpart = imag;
	A->realpart = real;
}
Complex add__0103(Complex* A, double real, double imag)
{
	Complex result;
	result.realpart = real + A->realpart;
	result.imagpart = imag + A->imagpart;
	return result;
}
Complex minus__0103(Complex* A, double real, double imag)
{
	Complex result;
	result.realpart = A->realpart-real;
	result.imagpart =  A->imagpart-imag ;
	return result;
}
Complex multiply__0103(Complex* A, double real, double imag)
{
	Complex result;
	result.realpart = real * A->realpart- imag * A->imagpart;
	result.imagpart = real*A->imagpart+imag*A->realpart;
	return result;
}
Complex divide__0103(Complex* A, double real, double imag)
{
	Complex result = { 0,0 };
	double div = real * real+ imag * imag;
	if (div==0)
	{
		printf("COMPLEX_ERR_DIV_BY_ZERO\n");
 		return result;

	}
	result=multiply__0103(A, real, -imag);
	result.realpart /= div;
	result.imagpart /= div;
	return result;
}
