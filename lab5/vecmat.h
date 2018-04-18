#include <stdio.h>
#pragma once

class Vector4
{
 public:
 double data[4];
 Vector4();
 void Print(void);
 void Set(double d1,double d2,double d3);
 double GetX();
 double GetY();
 double GetZ();
 Vector4 operator-(const Vector4 &);
 friend Vector4 operator*(const Vector4 &,double);
};

class Matrix4
{
 public:
 double data[4][4];
 Matrix4();
 void Print(void);
 Matrix4 operator*(const Matrix4);
 friend Vector4 operator*(const Matrix4,const Vector4);
};

Vector4::Vector4()
{
 data[0]=0.0; data[1]=0.0; data[2]=0.0; data[3]=1.0;
}

void Vector4::Print(void)
{
 printf("(%2.3lf,%2.3lf,%2.3lf,%2.3lf)\n",data[0],data[1],data[2],data[3]);
}

void Vector4::Set(double d1,double d2,double d3)
{
 data[0]=d1; data[1]=d2; data[2]=d3;
}

double Vector4::GetX()
{
	return data[0];
}

double Vector4::GetY()
{
	return data[1];
}

double Vector4::GetZ()
{
	return data[2];
}

Vector4 Vector4::operator- (const Vector4 &gVector)
{
 unsigned int i;
 Vector4 Result;
 for (i=0;i<4;i++) Result.data[i]=data[i]-gVector.data[i];
 return Result;
}

Vector4 operator* (const Vector4 &gVector,double val)
{
 unsigned int i;
 Vector4 Result;
 for (i=0;i<4;i++) Result.data[i]=gVector.data[i]*val;
 return Result;
}

Matrix4::Matrix4()
{
 data[0][0]=0.0; data[0][1]=0.0; data[0][2]=0.0; data[0][3]=0.0;
 data[1][0]=0.0; data[1][1]=0.0; data[1][2]=0.0; data[1][3]=0.0;
 data[2][0]=0.0; data[2][1]=0.0; data[2][2]=0.0; data[2][3]=0.0;
 data[3][0]=0.0; data[3][1]=0.0; data[3][2]=0.0; data[3][3]=1.0;
}

void Matrix4::Print(void)
{
 printf("\n|%2.3lf,%2.3lf,%2.3lf,%2.3lf|\n",data[0][0], data[0][1], data[0][2], data[0][3]);
 printf("|%2.3lf,%2.3lf,%2.3lf,%2.3lf|\n",data[1][0], data[1][1], data[1][2], data[1][3]);
 printf("|%2.3lf,%2.3lf,%2.3lf,%2.3lf|\n",data[2][0], data[2][1], data[2][2], data[2][3]);
 printf("|%2.3lf,%2.3lf,%2.3lf,%2.3lf|\n",data[3][0], data[3][1], data[3][2], data[2][3]);
}

Matrix4 Matrix4::operator* (const Matrix4 gMatrix)
{
 int i,j,k;
 Matrix4 tmp;

 for (i=0;i<4;i++)
    for (j=0;j<4;j++)
     {
      tmp.data[i][j]=0.0;
      for (k=0;k<4;k++)
       tmp.data[i][j]=tmp.data[i][j]+(data[i][k]*gMatrix.data[k][j]);
     }
 return tmp;
}

Vector4 operator* (const Matrix4 gMatrix,const Vector4 gVector)
{
 unsigned int i,j;
 Vector4 tmp;

 for (i=0;i<4;i++)
  {
   tmp.data[i]=0.0;
   for (j=0;j<4;j++) tmp.data[i]=tmp.data[i]+(gMatrix.data[i][j]*gVector.data[j]);
  }
 return tmp;
}
