//Extremely simple vector and matrix classes by Janusz Malinowski.
#include <stdio.h>
#pragma once

class Vector
{
 public:
 double data[3];
 Vector();
 void Print(void);
 void Set(double d1,double d2);
 double GetX();
 double GetY();
};

class Matrix
{
 public:
 double data[3][3];
 Matrix();
 void Print(void);
 Matrix operator*(const Matrix);
 friend Vector operator*(const Matrix,const Vector);
};


