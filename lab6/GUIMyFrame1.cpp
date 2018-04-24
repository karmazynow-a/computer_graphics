#include "GUIMyFrame1.h"
#include <iostream>
#include <vector>
#include <iterator>
#include <initializer_list>

GUIMyFrame1::GUIMyFrame1( wxWindow* parent )
:
MyFrame1( parent )
{
 m_staticText1->SetLabel(_(L"Jasnosc"));
 m_b_threshold->SetLabel(_(L"Prog 128"));
 this->SetBackgroundColour(wxColor(192, 192, 192));
 m_scrolledWindow->SetScrollbars(25, 25, 52, 40);
 m_scrolledWindow->SetBackgroundColour(wxColor(192, 192, 192));
}

void GUIMyFrame1::m_scrolledWindow_update( wxUpdateUIEvent& event )
{
 Repaint();
}

void GUIMyFrame1::m_b_grayscale_click( wxCommandEvent& event )
{
 Img_Cpy = Img_Org.Copy().ConvertToGreyscale();
}

void GUIMyFrame1::m_b_blur_click( wxCommandEvent& event )
{
 Img_Cpy = Img_Org.Copy().Blur(5);
}

void GUIMyFrame1::m_b_mirror_click( wxCommandEvent& event )
{
 Img_Cpy = Img_Org.Copy().Mirror();
}

void GUIMyFrame1::m_b_replace_click( wxCommandEvent& event )
{
    Img_Cpy = Img_Org.Copy();
    Img_Cpy.Replace(254, 0, 0, 0, 0, 255);
}

void GUIMyFrame1::m_b_rescale_click( wxCommandEvent& event )
{
    Img_Cpy = Img_Org.Copy().Rescale(320,240);
}

void GUIMyFrame1::m_b_rotate_click( wxCommandEvent& event )
{
    Img_Cpy = Img_Org.Rotate(M_PI * 30 / 180, wxPoint(Img_Org.GetWidth(), Img_Org.GetHeight()));
}

void GUIMyFrame1::m_b_rotate_hue_click( wxCommandEvent& event )
{
    Img_Cpy = Img_Org.Copy();
    Img_Cpy.RotateHue(0.5);
}

void GUIMyFrame1::m_b_mask_click( wxCommandEvent& event )
{
    Img_Cpy = Img_Org.Copy();
    Img_Cpy.SetMaskFromImage(Img_Mask, 0, 0, 0);
}

void GUIMyFrame1::m_s_brightness_scroll( wxScrollEvent& event )
{
    Brightness(m_s_brightness->GetValue() - 100);
    Repaint();
}

void GUIMyFrame1::Brightness(int value)
{
    Img_Cpy = Img_Org.Copy();
    unsigned char *data = Img_Cpy.GetData();
    int len = Img_Cpy.GetWidth() * Img_Cpy.GetHeight() * 3; //all pixels * 3 (RGB)

    for (int i = 0; i<len; ++i){
        int tmp = data[i] + value;
        if (tmp > 255) tmp = 255;
        else if (tmp < 0) tmp = 0;
        data[i] = static_cast<unsigned char> (tmp);
    }
}

void GUIMyFrame1::m_s_contrast_scroll( wxScrollEvent& event )
{
    Contrast(m_s_contrast->GetValue() - 100);
    Repaint();
}

void GUIMyFrame1::Contrast(int value)
{
    Img_Cpy = Img_Org.Copy();
    unsigned char *data = Img_Cpy.GetData();
    int len = Img_Cpy.GetWidth() * Img_Cpy.GetHeight() * 3; //all pixels * 3 (RGB)
    double contrast = static_cast<double>(value + 100)/(100 - value);

    for (int i = 0; i<len; ++i){
        int tmp = static_cast<int>((data[i] - 255./2) * contrast + 255./2);
        if (tmp > 255) tmp = 255;
        else if (tmp < 0) tmp = 0;
        data[i] = static_cast<unsigned char> (tmp);
    }
}

void GUIMyFrame1::m_b_prewitt_click( wxCommandEvent& event )
{
 Img_Cpy = Img_Org.Copy();
  unsigned char *data = Img_Cpy.GetData();
  int len = Img_Cpy.GetWidth() * Img_Cpy.GetHeight() * 3;
  int w = Img_Cpy.GetWidth();
  int h = Img_Cpy.GetHeight();
  unsigned char *tmp = new unsigned char [len];
  std::copy(data, data + len, tmp);

  int R[3][3], G[3][3], B[3][3], Pervitt[3][3];

    Pervitt[0][0] = Pervitt[1][0] = Pervitt[2][0] = -1;
    Pervitt[0][1] = Pervitt[1][1] = Pervitt[2][1] = 0;
    Pervitt[0][2] = Pervitt[1][2] = Pervitt[2][2] = 1;

  for (int i = 1; i < w-1; ++i)
    for (int j = 1; j < h-1; ++j){
        R[0][0] = tmp[3*((j-1) * w + i - 1)];
        R[0][1] = tmp[3*((j-1) * w + i)];
        R[0][2] = tmp[3*((j-1) * w + i + 1)];
        R[1][0] = tmp[3*((j) * w + i - 1)];
        R[1][1] = tmp[3*((j) * w + i)];
        R[1][2] = tmp[3*((j) * w + i + 1)];
        R[2][0] = tmp[3*((j+1) * w + i - 1)];
        R[2][1] = tmp[3*((j+1) * w + i)];
        R[2][2] = tmp[3*((j+1) * w + i + 1)];

        int r =  - (Pervitt[0][0] * R[0][0] + Pervitt[0][1] * R[0][1] + Pervitt[0][2] * R[0][2])
                    - (Pervitt[1][0] * R[1][0] + Pervitt[1][1] * R[1][1] + Pervitt[1][2] * R[1][2])
                    - (Pervitt[2][0] * R[2][0] + Pervitt[2][1] * R[2][1] + Pervitt[2][2] * R[2][2]);

        if (r > 255) r = 255;
        else if (r < 0) r = 0;

        data [3 * (j * w + i)] = static_cast <unsigned char> (r);

        G[0][0] = tmp[3*((j-1) * w + i - 1)+1];
        G[0][1] = tmp[3*((j-1) * w + i)+1];
        G[0][2] = tmp[3*((j-1) * w + i + 1)+1];
        G[1][0] = tmp[3*((j) * w + i - 1)+1];
        G[1][1] = tmp[3*((j) * w + i)+1];
        G[1][2] = tmp[3*((j) * w + i + 1)+1];
        G[2][0] = tmp[3*((j+1) * w + i - 1)+1];
        G[2][1] = tmp[3*((j+1) * w + i)+1];
        G[2][2] = tmp[3*((j+1) * w + i + 1)+1];

        int g =  - (Pervitt[0][0] * G[0][0] + Pervitt[0][1] * G[0][1] + Pervitt[0][2] * G[0][2])
                - (Pervitt[1][0] * G[1][0] + Pervitt[1][1] * G[1][1] + Pervitt[1][2] * G[1][2])
                - (Pervitt[2][0] * G[2][0] + Pervitt[2][1] * G[2][1] + Pervitt[2][2] * G[2][2]);

        if (g > 255) g = 255;
        else if (g < 0) g = 0;

        data [3 * (j * w + i)+1] = static_cast<unsigned char> (g);

        B[0][0] = tmp[3*((j-1) * w + i - 1)+2];
        B[0][1] = tmp[3*((j-1) * w + i)+2];
        B[0][2] = tmp[3*((j-1) * w + i + 1)+2];
        B[1][0] = tmp[3*((j) * w + i - 1)+2];
        B[1][1] = tmp[3*((j) * w + i)+2];
        B[1][2] = tmp[3*((j) * w + i + 1)+2];
        B[2][0] = tmp[3*((j+1) * w + i - 1)+2];
        B[2][1] = tmp[3*((j+1) * w + i)+2];
        B[2][2] = tmp[3*((j+1) * w + i + 1)+2];

        int b = - (Pervitt[0][0] * B[0][0] + Pervitt[0][1] * B[0][1] + Pervitt[0][2] * B[0][2])
                    - (Pervitt[1][0] * B[1][0] + Pervitt[1][1] * B[1][1] + Pervitt[1][2] * B[1][2])
                    - (Pervitt[2][0] * B[2][0] + Pervitt[2][1] * B[2][1] + Pervitt[2][2] * B[2][2]);

        if (b > 255) b = 255;
        else if (b < 0) b = 0;

        data [3 * (j * w + i)+2] = static_cast<unsigned char> (b);

    }
    delete[] tmp;
  }
/*
 for (int i = 1; i<Img_Cpy.GetWidth(); ++i)
    for (int j = 1; j<Img_Cpy.GetHeight(); ++j){
        int tmp = Img_Org.GetRed(i, j) * 3 - Img_Org.GetGreen(i, j) * 2 - Img_Org.GetBlue(i, j);
        if (tmp > 255) tmp = 255;
        else if (tmp < 0) tmp = 0;

        Img_Cpy.SetRGB(i, j, tmp, tmp, tmp);
 }
 */


void GUIMyFrame1::m_b_threshold_click( wxCommandEvent& event )
{
    Img_Cpy = Img_Org.Copy();
    unsigned char *data = Img_Cpy.GetData();
    int len = Img_Cpy.GetWidth() * Img_Cpy.GetHeight() * 3; //all pixels * 3 (RGB)

    for (int i = 0; i<len; ++i){
        if (data[i] < 128) data[i] = 0;
        else data[i] = 255;
    }
}

void GUIMyFrame1::Repaint()
{
 wxBitmap bitmap(Img_Cpy);          // Tworzymy tymczasowa bitmape na podstawie Img_Cpy
 wxClientDC dc(m_scrolledWindow);   // Pobieramy kontekst okna
    wxBufferedDC dc_buff(&dc);
    dc_buff.Clear();
 m_scrolledWindow->DoPrepareDC(dc_buff); // Musimy wywolac w przypadku wxScrolledWindow, zeby suwaki prawidlowo dzialaly
 dc_buff.DrawBitmap(bitmap, 0, 0, true); // Rysujemy bitmape na kontekscie urzadzenia
}

