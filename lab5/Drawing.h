#pragma once

#include "GUIMyFrame1.cpp"
#include "vecmat.h"
#include <wx/wx.h>

extern std::vector <Segment> data;

class Drawing{

public:
    double t[3]; //translate
    double r[3]; //rotate
    double s[3];  //scale

    Matrix4 translate() const;
    Matrix4 rotateX() const;
    Matrix4 rotateY() const;
    Matrix4 rotateZ() const;
    Matrix4 scale() const;
    void trans(const Matrix4 &t, Point &p);

    Drawing() = default;
    void draw(wxDC *dc, int w, int h);
    void update (double A[3], double x, double y, double z);
};

void Drawing::draw(wxDC *dc, int w, int h) {
    Matrix4 mat = translate()*rotateZ()*rotateY()*rotateX()*scale();

    for (auto el : data) {
        trans (mat, el.begin);
        trans (mat, el.end);

		dc->SetPen(wxPen(RGB(el.color.R, el.color.G, el.color.B)));
		dc->DrawLine(el.begin.x * w, el.begin.y * h, el.end.x * w, el.end.y * h);
    }
}

void Drawing::update (double A[3], double x, double y, double z){
    A[0] = x;
    A[1] = y;
    A[2] = z;
}

Matrix4 Drawing::translate() const{
    Matrix4 mat;

	mat.data[0][0] = mat.data[1][1] = mat.data[2][2] = 1.0;
	mat.data[0][3] = t[0];
	mat.data[1][3] = -t[1];
	mat.data[2][3] = t[2];
    return mat;
}

Matrix4 Drawing::rotateX() const{
    Matrix4 mat;
    double a = - r[0] * M_PI / 180;

    mat.data[0][0] = 1;
	mat.data[1][1] = cos(a);
	mat.data[1][2] = -sin(a);
	mat.data[2][1] = sin(a);
	mat.data[2][2] = cos(a);
    return mat;
}

Matrix4 Drawing::rotateY() const{
    Matrix4 mat;
    double a = - r[1] * M_PI / 180;

	mat.data[0][0] = cos(a);
	mat.data[0][2] = sin(a);
	mat.data[1][1] = 1;
	mat.data[2][0] = -sin(a);
	mat.data[2][2] = cos(a);
    return mat;
}

Matrix4 Drawing::rotateZ() const{
    Matrix4 mat;
    double a = - r[2] * M_PI / 180;

    mat.data[0][0] = -cos(a);
    mat.data[0][1] = sin(a);
	mat.data[1][0] = -sin(a);
	mat.data[1][1] = -cos(a);
	mat.data[2][2] = 1;
    return mat;
}

Matrix4 Drawing::scale() const{
    Matrix4 mat;
	mat.data[0][0] = s[0];
	mat.data[1][1] = s[1];
	mat.data[2][2] = s[2];
	mat.data[3][3] = 1.0;
	return mat;
}

void Drawing::trans(const Matrix4 &mat, Point &p) {
    Matrix4 center;
	center.data[0][0] = center.data[1][1] = center.data[2][2] = 1;
	center.data[0][3] = center.data[1][3] = 0.5;
    center.data[2][3] = 0;

	Vector4 tmp;
	tmp.Set(p.x, p.y, p.z);
	tmp = mat * tmp;
    tmp.Set(tmp.GetX() / tmp.GetZ(), tmp.GetY() / tmp.GetZ(), tmp.GetZ());
	tmp = center * tmp;

	p.x = tmp.GetX();
	p.y = tmp.GetY();
	p.z = tmp.GetZ();
}
