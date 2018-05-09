#include "GUIMyFrame1.h"

GUIMyFrame1::GUIMyFrame1( wxWindow* parent )
:
MyFrame1( parent )
{
 m_tb_pokaz_punkty->SetLabel(_(L"Poka\u017C punkty"));
 sbSizer2->GetStaticBox()->SetLabel(_(L"Wyb\u00F3r funkcji"));
 this->SetBackgroundColour(wxColor(192, 192, 192));
 MemoryBitmap.Create(500, 500,24);
 image.Create(500, 500);
 PrepareData(0);
 DrawMap(NoPoints, FunctionData, ContourFlag, ColoringType, NoLevels, ShowPoints);
}

void GUIMyFrame1::UpdateUI( wxUpdateUIEvent& event )
{
 Repaint();
}

void GUIMyFrame1::m_cb_Kontur_Click( wxCommandEvent& event )
{
ContourFlag = m_cb_Kontur->IsChecked();
if (!m_cb_Kontur->IsChecked())
{
m_cb_Mapa->SetValue(true);
m_cb_Mapa_Click(event);
}
else
{
DrawMap(NoPoints, FunctionData, ContourFlag, ColoringType, NoLevels, ShowPoints);
Repaint();
}
}

void GUIMyFrame1::m_cb_Mapa_Click( wxCommandEvent& event )
{
if (m_cb_Mapa->IsChecked())
{
m_rb_NC->Enable();
m_rb_NZC->Enable();
m_rb_Na_szaro->Enable();
if (m_rb_NC->GetValue()) ColoringType = 1;
if (m_rb_NZC->GetValue()) ColoringType = 2;
if (m_rb_Na_szaro->GetValue()) ColoringType = 3;
}
else
{
m_rb_NC->Disable();
m_rb_NZC->Disable();
m_rb_Na_szaro->Disable();
m_cb_Kontur->SetValue(true);
ColoringType = 0;
ContourFlag = true;
}
DrawMap(NoPoints, FunctionData, ContourFlag, ColoringType, NoLevels, ShowPoints);
Repaint();
}

void GUIMyFrame1::m_tb_function_1_click( wxCommandEvent& event )
{
if (m_tb_function_1->GetValue()) PrepareData(1); else PrepareData(0);
m_tb_function_2->SetValue(false);
m_tb_function_3->SetValue(false);
m_tb_function_4->SetValue(false);
DrawMap(NoPoints, FunctionData, ContourFlag, ColoringType, NoLevels, ShowPoints);
Repaint();
}

void GUIMyFrame1::m_tb_function_2_click( wxCommandEvent& event )
{
if (m_tb_function_2->GetValue()) PrepareData(2); else PrepareData(0);
m_tb_function_1->SetValue(false);
m_tb_function_3->SetValue(false);
m_tb_function_4->SetValue(false);
DrawMap(NoPoints, FunctionData, ContourFlag, ColoringType, NoLevels, ShowPoints);
Repaint();
}

void GUIMyFrame1::m_tb_function_3_click( wxCommandEvent& event )
{
if (m_tb_function_3->GetValue()) PrepareData(3); else PrepareData(0);
m_tb_function_1->SetValue(false);
m_tb_function_2->SetValue(false);
m_tb_function_4->SetValue(false);
DrawMap(NoPoints, FunctionData, ContourFlag, ColoringType, NoLevels, ShowPoints);
Repaint();
}

void GUIMyFrame1::m_tb_function_4_click( wxCommandEvent& event )
{
if (m_tb_function_4->GetValue()) PrepareData(4); else PrepareData(0);
m_tb_function_1->SetValue(false);
m_tb_function_2->SetValue(false);
m_tb_function_3->SetValue(false);
DrawMap(NoPoints, FunctionData, ContourFlag, ColoringType, NoLevels, ShowPoints);
Repaint();
}

void GUIMyFrame1::m_s_ile_poziomic_scroll( wxScrollEvent& event )
{
NoLevels = m_s_ile_poziomic->GetValue();
m_st_liczba_poziomic->SetLabel("Liczba poziomic: "+ wxString::Format(wxT("%i"), NoLevels));
DrawMap(NoPoints, FunctionData, ContourFlag, ColoringType, NoLevels, ShowPoints);
Repaint();
}

void GUIMyFrame1::m_tb_pokaz_punkty_toggle( wxCommandEvent& event )
{
ShowPoints = m_tb_pokaz_punkty->GetValue();
DrawMap(NoPoints, FunctionData, ContourFlag, ColoringType, NoLevels, ShowPoints);
Repaint();
}


void GUIMyFrame1::Repaint()
{
 
 wxMemoryDC memDC;
 memDC.SelectObject(MemoryBitmap);
 wxClientDC dc(m_panel1);
 dc.Blit(0, 0, 500, 500, &memDC, 0, 0);
 memDC.SelectObject(wxNullBitmap);
 /*
 wxBitmap bitmap(image);           // Tworzymy tymczasowa bitmape na podstawie Img_Cpy
 wxClientDC dc(m_panel1);   // Pobieramy kontekst okna
 dc.DrawBitmap(bitmap, 0, 0, true);
 */
}

void GUIMyFrame1::PrepareData(int fun)
{
 int i;
 float x, y;
 srand(376257);
 switch (fun)
 {
 case 0:     NoPoints = 5;
  FunctionData[0][0] = -1.0;	FunctionData[0][1] = 1.0;	FunctionData[0][2] = 0.0;
  FunctionData[1][0] = 1.0;	FunctionData[1][1] = 1.0;	FunctionData[1][2] = 25.0;
  FunctionData[2][0] = 1.0;	FunctionData[2][1] = -1.0;	FunctionData[2][2] = 5.0;
  FunctionData[3][0] = -1.0;	FunctionData[3][1] = -1.0;	FunctionData[3][2] = 25.0;
  FunctionData[4][0] = 0.0;	FunctionData[4][1] = 0.0;	FunctionData[4][2] = 15.0;
  break;
 case 1:     NoPoints = 20;
  for (i = 0; i<NoPoints; i++)
  {
   x = 4.8*(float(rand()) / RAND_MAX) - 2.4;
   y = 4.8*(float(rand()) / RAND_MAX) - 2.4;
   FunctionData[i][0] = x;
   FunctionData[i][1] = y;
   FunctionData[i][2] = 200 * (float(rand()) / RAND_MAX);
  }
  break;
 case 2:     NoPoints = 100;
  for (i = 0; i<NoPoints; i++)
  {
   x = 4.8*(float(rand()) / RAND_MAX) - 2.4;
   y = 4.8*(float(rand()) / RAND_MAX) - 2.4;
   FunctionData[i][0] = x;
   FunctionData[i][1] = y;
   FunctionData[i][2] = x * (2 * x - 7)*(2 * y + 1) + 2 * y;
  }
  break;
 case 3:     NoPoints = 10;
  for (i = 0; i<NoPoints; i++)
  {
   x = 4.8*(float(rand()) / RAND_MAX) - 2.4;
   y = 4.8*(float(rand()) / RAND_MAX) - 2.4;
   FunctionData[i][0] = x;
   FunctionData[i][1] = y;
   FunctionData[i][2] = x * sin(2 * y);
  }
  break;
 case 4:     NoPoints = 100;
  for (i = 0; i<NoPoints; i++)
  {
   x = 2 * (float(rand()) / RAND_MAX) - 1;
   y = 2 * (float(rand()) / RAND_MAX) - 1;
   FunctionData[i][0] = x;
   FunctionData[i][1] = y;
   FunctionData[i][2] = sin(8 * (x*x + y * y));
  }
  break;
 }
}