#include <wx/wx.h>
#include "GUIMyFrame1.h"
// UWAGA: TO JEST JEDYNY PLIK, KTORY NALEZY EDYTOWAC **************************

float shepard(int N, float d[100][3], const wxRealPoint &point);

void GUIMyFrame1::DrawMap(int N, float d[100][3], bool Contour, int MappingType, int NoLevels, bool ShowPoints)
{
 wxMemoryDC memDC;
 memDC.SelectObject(MemoryBitmap);
 memDC.SetBackground(*wxWHITE_BRUSH);
 memDC.Clear();

    if (!N) return;

    float shepardArr[500][500] = {{0.0}};
    for (int i = 0; i < MemoryBitmap.GetWidth(); i++) {
        for (int j = 0; j < MemoryBitmap.GetHeight(); j++) {
            wxRealPoint point ( (j/100.0) - 2.5, -((i/100.0) - 2.5) );
            shepardArr[j][i] = shepard(N, d, point);
        }
    }

    float _min, _max;
    _min = _max = d[0][2];
    for (int i = 1; i < N; i++) {
        if (d[i][2] < _min) _min = d[i][2];
        if (d[i][2] > _max) _max = d[i][2];
    }

    if (MappingType) {
        for (unsigned i{}; i<MemoryBitmap.GetWidth(); ++i)
            for (unsigned j{}; j<MemoryBitmap.GetHeight(); ++j){
                unsigned char color = (shepardArr[j][i] - _min) * 255 /(_max - _min);

                if (MappingType == 1){
                    memDC.SetPen(wxPen(wxColour(255 - color, 0, color)));
                    memDC.DrawPoint(j, i);
                }

                else if (MappingType == 2){
                    int b = (color - 128) * 2, g = 2 * color, r = 255 - 2 * color;
                    if (r < 0) r=0;
                    if (g > 255) g=-2 * color + 2 * 255;
                    if (b < 0) b = 0;

                    memDC.SetPen(wxPen(wxColour(r, g, b)));
                    memDC.DrawPoint(j, i);
                }

                else if (MappingType == 3){
                    memDC.SetPen(wxPen(wxColour(color, color, color)));
                    memDC.DrawPoint(j, i);
                }
            }
    }

    memDC.SetPen(*wxBLACK_PEN);
    memDC.SetBrush(*wxTRANSPARENT_BRUSH);

    if (ShowPoints) {
        for (unsigned i{}; i<N; ++i){
            wxPoint point (100 * (d[i][0] + 2.5), 100 * (2.5 - d[i][1]));
            memDC.DrawLine(point.x, point.y + 3, point.x, point.y - 3);
            memDC.DrawLine(point.x - 3, point.y, point.x + 3, point.y);
        }
    }

    if (Contour) {
        for (unsigned l{}; l < NoLevels; ++l) {
            float tPoint = _min + (l + 1) * (_max - _min) / (NoLevels + 1.0f);

            for (unsigned i{}; i<MemoryBitmap.GetWidth(); ++i)
                for (unsigned j{}; j<MemoryBitmap.GetHeight(); ++j)
                    if (shepardArr[j][i] > tPoint){
                        int range = 1;
                        for (int a=-range; a<=range; ++a)
                            for (int b=-range; b<=range; ++b)
                                if (a && b && (a+j>=0) && (b+i>=0) && (a+j<500) && (b+i<500) && (shepardArr[a+j][b+i] < tPoint))
                                    memDC.DrawPoint(j, i);
                    }
        }

    }
}

float shepard(int N, float d[100][3], const wxRealPoint &point) {
    float s1{}, s2{}, wk{};
    for (unsigned i{}; i<N; ++i){
        wk = 1. / fabs ( pow(point.x - d[i][0], 2) + pow(point.y - d[i][1], 2) );
        s1 += wk * d[i][2];
        s2 += wk;
    }

    return s1/s2;
}
