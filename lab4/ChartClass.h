#ifndef __ChartClass__
#pragma once

#define __ChartClass__
#pragma once
#include <memory>
#include "ConfigClass.h"
#include "vecmat.h"

class Matrix;

class ChartClass
{
    private:
        std::shared_ptr<ConfigClass> cfg;
        int x_step;         // liczba odcinkow z jakich bedzie sie skladal wykres
        double x_min,x_max; // zakres zmiennej x
        double y_min,y_max; // zakres wartosci przyjmowanych przez funkcje
        double GetFunctionValue(double x); // zwraca wartosci rysowanej funkcji

        int w, h;

        void line2d(wxDC *dc,Matrix t,double x1,double y1,double x2,double y2);
        // powyzej sugerowana funkcja transformujaca odcinki (jesli ktos ma
        // inny pomysl mozna ja usunac)
        void drawAxis(wxDC *dc, Matrix mat);
        Matrix Translate(double x, double y) const;
        Matrix Rotate(double angle);
        Matrix toScreen();

    public:
        ChartClass(std::shared_ptr<ConfigClass> c);
        void Set_Range();   // ustala wartosci zmiennych x_min,y_min,x_max,y_max
        double Get_Y_min(); // zwraca y_min
        double Get_Y_max(); // zwraca y_max
        void Draw(wxDC *dc, int w, int h);  // rysuje wykres
};

#endif
