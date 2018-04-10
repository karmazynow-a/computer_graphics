#pragma once

#include "GUIMyFrame1.h"

class ConfigClass
{
    private:
       GUIMyFrame1 *MainWindow;   // wskaznik do glownego okna aplikacji
        double x0,y0,x1,y1;     // wspolrzedne definiujace prostokat swiata
        double alpha;           // kat obrotu wykresu
        bool ScreenRotate;      // jesli true obracamy wokol srodka ekranu
                                // jesli false obracamy punktu przeciecia osi
        double dX,dY;           // przesuniecie wykresu wzgledem srodka ekranu
        double x_start, x_stop; // zakres zmiennosci argumentu funkcji x
        int F_type;             // rodzaj obliczanej funkcji
    public:
        ConfigClass(GUIMyFrame1 *wnd);
        double Get_x_start(){return x_start;};
        void   Set_x_start(double v){x_start=v;};
        double Get_x_stop(){return x_stop;};
        void   Set_x_stop(double v){x_stop=v;};
        bool RotateScreenCenter(){return ScreenRotate;};
        void SetRotateScreen(bool b){ScreenRotate=b;};
        double Get_Alpha(){return alpha;};
        void Set_Alpha(int a){alpha=a;};
        double Get_dX(){return dX;};
        void   Set_dX(float v){dX=v;};
        double Get_dY(){return dY;};
        void   Set_dY(float v){dY=v;};
        double Get_x0(){return x0;};
        void   Set_x0(float v){x0=v;};
        double Get_y0(){return y0;};
        void   Set_y0(float v){y0=v;};
        double Get_x1(){return x1;};
        void   Set_x1(float v){x1=v;};
        double Get_y1(){return y1;};
        void   Set_y1(float v){y1=v;};
        int  Get_F_type(){return F_type;};
        void Set_F_type(int i){F_type=i;};
        void Save(char *filename);
        void Load(char *filename);
};
