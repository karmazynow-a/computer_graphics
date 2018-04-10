#include "vecmat.h"

Vector::Vector()
{
 data[0]=0.0; data[1]=0.0; data[2]=1.0;
}

void Vector::Print(void)
{
 printf("(%2.3lf,%2.3lf,%2.3lf)\n",data[0],data[1],data[2]);
}

void Vector::Set(double d1,double d2)
{
 data[0]=d1; data[1]=d2;
}

double Vector::GetX()
{
 return data[0];
}

double Vector::GetY()
{
 return data[1];
}

Matrix::Matrix()
{
 data[0][0]=0.0; data[0][1]=0.0; data[0][2]=0.0;
 data[1][0]=0.0; data[1][1]=0.0; data[1][2]=0.0;
 data[2][0]=0.0; data[2][1]=0.0; data[2][2]=1.0;
}

void Matrix::Print(void)
{
 printf("\n|%2.3lf,%2.3lf,%2.3lf|\n",data[0][0], data[0][1], data[0][2]);
 printf("|%2.3lf,%2.3lf,%2.3lf|\n",data[1][0], data[1][1], data[1][2]);
 printf("|%2.3lf,%2.3lf,%2.3lf|\n",data[2][0], data[2][1], data[2][2]);
}

Matrix Matrix::operator* (const Matrix gMatrix)
{
 int i,j,k;
 Matrix tmp;

 for (i=0;i<3;i++)
    for (j=0;j<3;j++)
     {
      tmp.data[i][j]=0.0;
      for (k=0;k<3;k++)
       tmp.data[i][j]=tmp.data[i][j]+(data[i][k]*gMatrix.data[k][j]);
     }
 return tmp;
}

Vector operator* (const Matrix gMatrix,const Vector gVector)
{
 unsigned int i,j;
 Vector tmp;

 for (i=0;i<3;i++)
  {
   tmp.data[i]=0.0;
   for (j=0;j<3;j++) tmp.data[i]=tmp.data[i]+(gMatrix.data[i][j]*gVector.data[j]);
  }
 return tmp;
}
