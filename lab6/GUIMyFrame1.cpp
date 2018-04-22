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
        unsigned int tmp = data[i] + value;
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
        unsigned int tmp = static_cast<int>((data[i] - 255./2) * contrast + 255./2);
        if (tmp > 255) tmp = 255;
        else if (tmp < 0) tmp = 0;
        data[i] = static_cast<unsigned char> (tmp);
    }
}

void GUIMyFrame1::m_b_prewitt_click( wxCommandEvent& event )
{
 Img_Cpy = Img_Org.Copy();

 for (int i = 1; i<Img_Cpy.GetWidth()-1; ++i)
    for (int j = 1; j<Img_Cpy.GetHeight()-1; ++j){
        int tmp = Img_Org.GetRed(i, j) * 3 - Img_Org.GetGreen(i, j) * 2 - Img_Org.GetBlue(i, j);
        if (tmp > 255) tmp = 255;
        else if (tmp < 0) tmp = 0;

        Img_Cpy.SetRGB(i, j, tmp, tmp, tmp);
 }
}

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

