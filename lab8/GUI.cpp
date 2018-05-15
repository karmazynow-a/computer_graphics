#include "GUI.h"

#include <stdio.h>

#if defined(__mingw32__)
#define __msvcrt_version__ 0x800
#define _win32_winnt 0x0500
#endif  // if needed //

#include "CImg.h"
#include "FreeImage.h"

#include <wx/dcbuffer.h>
#include <wx/window.h>
#include <wx/timer.h>

#define SIZE 360

using namespace cimg_library;


wxBEGIN_EVENT_TABLE(GUIMyFrame, wxFrame)
    EVT_TIMER(wxEVT_COMMAND_CHECKBOX_CLICKED, GUIMyFrame::OnTimer)
wxEND_EVENT_TABLE()


GUIMyFrame::GUIMyFrame( wxWindow* parent ): MyFrame1( parent ){
    wxClientDC dc(m_panel1);

    img = new wxImage();
    tmp = new wxImage();
    animation = new wxImage [SIZE];

    m_timer = new wxTimer(this, wxEVT_COMMAND_CHECKBOX_CLICKED);

    currA = 0;
    isReady = false;

    wxInitAllImageHandlers();

    render (dc);
}

GUIMyFrame::~GUIMyFrame() {
    delete img;
    delete tmp;
    delete [] animation;
}

void GUIMyFrame::render (wxClientDC &dc){
    if (m_checkBox1->IsChecked() && img->Ok()){
            static const int INTERVAL = 5; // milliseconds
            m_timer->Start(INTERVAL);
    }

    else if (img->Ok()) {
        m_gauge1 -> Hide();
        this->Layout();
        m_timer->Stop();
        isReady = false;

		wxBufferedDC bufferedDC(&dc);
		wxSize size(dc.GetSize());

		img->Rescale(size.x, size.y);
		wxBitmap bitmap(*img);
		bufferedDC.DrawBitmap(bitmap, 0, 0);
	}

    else{
        m_timer->Stop();
        m_gauge1 -> Hide();
        this->Layout();
        isReady = false;
	}
}

void GUIMyFrame::MyFrame1OnUpdateUI( wxUpdateUIEvent& event ){
    wxClientDC dc(m_panel1);
    render (dc);
}

void GUIMyFrame::read_file( wxCommandEvent& event ) {
    wxClientDC dc(m_panel1);

    wxFileDialog * dialog = new wxFileDialog(this, "Load file", "", "", wxT("TO JPG (*.jpg)|*.jpg"), wxFD_OPEN | wxFD_FILE_MUST_EXIST);
    dialog->ShowModal();
    img->LoadFile(dialog->GetPath(), wxBITMAP_TYPE_JPEG);

    FIBITMAP *dib = FreeImage_Load(FIF_JPEG, dialog->GetPath(), JPEG_DEFAULT);
    FITAG *tagMake = NULL;
    FreeImage_GetMetadata(FIMD_EXIF_MAIN, dib, "YResolution", &tagMake);

    m_textCtrl1->AppendText("Rozmiar obrazka: " + std::to_string(FreeImage_GetWidth(dib)) + "*" + std::to_string(FreeImage_GetHeight(dib)));
    m_textCtrl1->AppendText("\n");

    m_textCtrl1->AppendText("EXIF Info: ");
    m_textCtrl1->AppendText("\n");

    FreeImage_GetMetadata(FIMD_EXIF_MAIN, dib, "Artist", &tagMake);
    m_textCtrl1->AppendText("Artist: ");
    m_textCtrl1->AppendText(FreeImage_TagToString(FIMD_EXIF_MAIN, tagMake));
    m_textCtrl1->AppendText("\n");

    FreeImage_GetMetadata(FIMD_EXIF_MAIN, dib, "Copyright", &tagMake);
    m_textCtrl1->AppendText("Copyright: ");
    m_textCtrl1->AppendText(FreeImage_TagToString(FIMD_EXIF_MAIN, tagMake));
    m_textCtrl1->AppendText("\n");

    FreeImage_GetMetadata(FIMD_EXIF_MAIN, dib, "ResolutionUnit", &tagMake);
    m_textCtrl1->AppendText("Resolution Unit: ");
    m_textCtrl1->AppendText(FreeImage_TagToString(FIMD_EXIF_MAIN, tagMake));
    m_textCtrl1->AppendText("\n");

    FreeImage_GetMetadata(FIMD_EXIF_MAIN, dib, "XResolution", &tagMake);
    m_textCtrl1->AppendText("XResolution: ");
    m_textCtrl1->AppendText(FreeImage_TagToString(FIMD_EXIF_MAIN, tagMake));
    m_textCtrl1->AppendText("\n");

    FreeImage_GetMetadata(FIMD_EXIF_MAIN, dib, "YCbCrPositioning", &tagMake);
    m_textCtrl1->AppendText("YCbCrPositioning: ");
    m_textCtrl1->AppendText(FreeImage_TagToString(FIMD_EXIF_MAIN, tagMake));
    m_textCtrl1->AppendText("\n");

    FreeImage_GetMetadata(FIMD_EXIF_MAIN, dib, "YResolution", &tagMake);
    m_textCtrl1->AppendText("YResolution: ");
    m_textCtrl1->AppendText(FreeImage_TagToString(FIMD_EXIF_MAIN, tagMake));

    FreeImage_Unload(dib);

    for (int i {}; i<SIZE; i++)
        animation[i] = *img;

    render (dc);
}

void GUIMyFrame::cenzure( wxCommandEvent& event ) {
    wxClientDC dc(m_panel1);
    if (!img->IsOk()) return;

    int x {0.57 * img->GetWidth()};
    int y {0.05 * img->GetHeight()};
    int w {0.15 * img->GetWidth()};
    int h {0.1 * img->GetHeight()};

	CImg<unsigned char> cImage(w, h, 1, 3);
	for (int i = 0; i<w; ++i)
		for (int j = 0; j<h; ++j) {
			cImage(i, j, 0) = img->GetRed(x + i, y + j);
			cImage(i, j, 1) = img->GetGreen(x + i, y + j);
			cImage(i, j, 2) = img->GetBlue(x + i, y + j);
		}
	cImage.blur(2.5);
	for (int i = 0; i<w; ++i)
		for (int j = 0; j<h; ++j) {
			img->SetRGB(x + i, y + j, cImage(i, j, 0), cImage(i, j, 1), cImage(i, j, 2));
		}
    render (dc);
}

void GUIMyFrame::erode( wxCommandEvent& event ) {
    wxClientDC dc(m_panel1);
    if (!img->IsOk()) return;

    int w {img->GetWidth()};
    int h {img->GetHeight()};

	CImg<unsigned char> cImage(w, h, 1, 3);
	for (int i = 0; i<w; ++i)
		for (int j = 0; j<h; ++j) {
			cImage(i, j, 0) = img->GetRed(i, j);
			cImage(i, j, 1) = img->GetGreen(i, j);
			cImage(i, j, 2) = img->GetBlue(i, j);
		}

	cImage.erode(5,5);

	for (int i = 0; i<w; ++i)
		for (int j = 0; j<h; ++j) {
			img->SetRGB(i, j, cImage(i, j, 0), cImage(i, j, 1), cImage(i, j, 2));
		}
    render (dc);
}

void GUIMyFrame::animate( wxCommandEvent& event ) {
    if (!img->IsOk()) return;

    wxClientDC dc(m_panel1);
    wxBufferedDC bufferedDC(&dc);

    if (!m_checkBox1->IsChecked()) m_timer->Stop();
    else{
        m_gauge1 -> Show();
        this->Layout();

		int w {img->GetWidth()};
        int h {img->GetHeight()};
        float spectrum [3] = {1.,1.,1.};
        float fi = 2*M_PI / SIZE, r = h/4;

        CImg<float> mask1 (w, h, 1, 3);
        CImg<float> mask2 (w, h, 1, 3);

        CImg<unsigned char> cImage(w, h, 1, 3);
        CImg<unsigned char> cTmp(w, h, 1, 3);

        for (int i {}; i<w; ++i)
            for (int j = 0; j<h; ++j) {
                cImage(i, j, 0) = img->GetRed(i, j);
                cImage(i, j, 1) = img->GetGreen(i, j);
                cImage(i, j, 2) = img->GetBlue(i, j);
		}

        for (int i {}; i<SIZE; ++i){
            cTmp = cImage;

            mask1.draw_gaussian(w/2 + r * cos (i*fi), h/2 + r * sin(i*fi), 80., spectrum, 1);
            mask2.draw_gaussian(w/2 + r * cos (i*fi + M_PI), h/2 + r * sin(i*fi+ M_PI), 80., spectrum, 1);
            mask1 += mask2;
            cTmp.mul(mask1);

            for (int x {}; x<w; ++x)
                for (int y {}; y<h; ++y) {
                    animation[i].SetRGB(x, y, cTmp(x, y, 0), cTmp(x, y, 1), cTmp(x, y, 2));
            }

            m_gauge1->SetValue(i*100/SIZE);
        }
        isReady = true;
    }

    render (dc);
}

void GUIMyFrame::OnTimer(wxTimerEvent& event){
    if (isReady){
        if (currA == SIZE){
             *img = animation[0];
             currA = 0;
        }
        else
            *img = animation[currA];

        ++currA;
    }
    wxClientDC dc(m_panel1);
    wxBufferedDC bufferedDC(&dc);
    bufferedDC.DrawBitmap(wxBitmap(*img), 0, 0);
    render (dc);
}

