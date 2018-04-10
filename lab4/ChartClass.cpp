#include <wx-3.0/wx/dc.h>
#include <memory>

#include "ChartClass.h"


ChartClass::ChartClass(std::shared_ptr<ConfigClass> c){
    cfg= std::move(c);
    x_step=200;
    Set_Range();
}

void ChartClass::Set_Range(){
 double xmin=9999.9,xmax=-9999.9,ymin=9999.9,ymax=-9999.9;
 double x,y,step;
 int i;

 xmin=cfg->Get_x_start();
 xmax=cfg->Get_x_stop();

 step=(cfg->Get_x_stop()-cfg->Get_x_start())/(double)x_step;
 x=cfg->Get_x_start();

 for (i=0;i<=x_step;i++)
  {
   y=GetFunctionValue(x);
   if (y>ymax) ymax=y;
   if (y<ymin) ymin=y;
   x=x+step;
  }

 y_min=ymin;
 y_max=ymax;
 x_min=xmin;
 x_max=xmax;
}


double ChartClass::GetFunctionValue(double x){
 if (cfg->Get_F_type()==1) return x*x;
 if (cfg->Get_F_type()==2) return 0.5*exp(4*x-3*x*x);
 return x+sin(x*4.0);
}

void ChartClass::Draw(wxDC *dc, int w, int h){
    this->w = w;
    this->h = h;
 dc->SetBackground(wxBrush(RGB(255, 255, 255)));
 dc->Clear();
 dc->SetPen(wxPen(RGB(255, 0, 0)));
 dc->DrawRectangle(10, 10, w - 20, h - 20);
 dc->SetClippingRegion(wxRect(11, 11, w - 21, h - 21));

    Matrix mat;

    if (cfg->RotateScreenCenter()){
        mat = Rotate(cfg->Get_Alpha()) * Translate(cfg->Get_dX(), cfg->Get_dY()) * toScreen();
    }
    else{
        mat = Translate(cfg->Get_dX(), cfg->Get_dY()) * Rotate(cfg->Get_Alpha()) * toScreen();
    }

 dc->SetPen(wxPen(RGB(0, 0, 255)));
 drawAxis(dc, mat);

 dc->SetPen(wxPen(RGB(0, 255, 0)));
 double norm = (x_max - x_min)/x_step;

  for (double x = x_min; x < x_max; x+=norm){
    line2d(dc, mat, x, (GetFunctionValue(x)), x + norm, (GetFunctionValue(x + norm)));
  }
}

void ChartClass::line2d(wxDC *dc, Matrix t, double x1, double y1, double x2, double y2){
    Vector startLine;
    startLine.Set(x1, y1);

    Vector endLine;
    endLine.Set(x2, y2);

    startLine = t*startLine;
    endLine = t*endLine;

    dc->DrawLine(startLine.data[0], h-startLine.data[1], endLine.data[0], h-endLine.data[1]);
}

double ChartClass::Get_Y_min(){
    Set_Range();
    return y_min;
}

double ChartClass::Get_Y_max(){
    Set_Range();
    return y_max;
}

Matrix ChartClass::Translate(double x, double y) const {
    Matrix mat;
    mat.data[0][0] = mat.data[1][1] = 1.0;
    mat.data[0][2] = x;
    mat.data[1][2] = y;
    mat.data[0][1] = mat.data[1][0] = 0.;
    return mat;
}


Matrix ChartClass::Rotate(double angle){ //degrees
    double rad = angle * M_PI / 180;
    Matrix mat;

    int x, y;

    if (cfg->RotateScreenCenter()){
        x = w / 2;
        y = h / 2;
    }
    else {
        Vector tmp;
        tmp.Set(0, 0);
        tmp = toScreen()*tmp;

        x = tmp.GetX();
        y = tmp.GetY();
    }

    mat.data[0][0] = cos(rad);
    mat.data[0][1] = sin(rad);
    mat.data[1][0] = -sin(rad);
    mat.data[1][1] = cos(rad);
    mat.data[0][2] = x * (1 - mat.data[0][0]) + y * mat.data[1][0];
    mat.data[1][2] = -x * mat.data[1][0] + y * (1 - mat.data[0][0]);

    return mat;
}


Matrix ChartClass::toScreen(){
    Matrix mat;

    mat.data[0][0] = (w - 20.) / (cfg->Get_x1() - cfg->Get_x0());
    mat.data[0][1] = mat.data[1][0] = 0;
    mat.data[0][2] = 10. - ((w - 20.) / (cfg->Get_x1() - cfg->Get_x0()) * cfg->Get_x0());
    mat.data[1][1] = (h - 20.) / (cfg->Get_y1() - cfg->Get_y0());
    mat.data[1][2] = 10. - ((h - 20.) / (cfg->Get_y1() - cfg->Get_y0()) * cfg->Get_y0());

    return mat;
}

void ChartClass::drawAxis(wxDC *dc, Matrix mat){

    //ax X
    Vector vS;
    Vector vE;

    line2d(dc, mat, x_min, 0, x_max, 0);

    //arrow X
    line2d(dc, mat, x_max, 0, x_max - 0.1, 0.1);
    line2d(dc, mat, x_max, 0, x_max - 0.1, -0.1);

    //ax Y
    line2d(dc, mat, 0, y_min, 0, y_max);

    //arrow Y
    line2d(dc, mat, 0, y_max, 0.1, y_max - 0.1);
    line2d(dc, mat, 0, y_max, -0.1, y_max - 0.1);

    //delimiter X
    for (double x = x_min ; x < x_max; x += 0.5){
            if (x==0) continue;
        line2d(dc, mat, x, -0.1, x, 0.1);

        wxString textPos;
        textPos.Printf("%0.2g", x);

        Vector coord;
        coord.Set(x, 0.13);
        coord = mat * coord;

        dc->DrawRotatedText(textPos , coord.GetX() , coord.GetY(), cfg->Get_Alpha());
    }

    //delimiter Y
    for (double y = y_min ; y < y_max; y += 0.7){
            if (y < 0.1 && y > -0.1) continue;
        line2d(dc, mat, -0.1, y, 0.1, y);

        wxString textPos;
        textPos.Printf("%0.2g", y);

        Vector coord;
        coord.Set(0.13, y);
        coord = mat * coord;

        dc->DrawRotatedText(textPos , coord.GetX() , h - coord.GetY(), cfg->Get_Alpha());
    }

}

