#pragma warning(disable: 4996) // Visual Studio: warning C4996: 'XXX': This function or variable may be unsafe. <- wxcrt.h
#include <fstream>
#include "ConfigClass.h"

using namespace std;

ConfigClass::ConfigClass(GUIMyFrame1 *wnd)
{
 MainWindow=wnd;
 x_start=-1.0;
 x_stop=2.0;
 ScreenRotate=true;
 F_type=0;
 alpha=0;
 x0=-1.0;
 y0=-2.0;
 x1=1.0;
 y1=2.0;
 dX=0;
 dY=0;
}

void ConfigClass::Save(char *filename)
{
 fstream f;
 
 f.open(filename,ios::out);
 f << x0 << " " << y0 << " " << x1 << " " << y1 << endl;
 f << alpha << endl;
 f << ScreenRotate << endl;
 f << dX << " " << dY << endl;
 f << x_start << " " << x_stop << endl;
 f << F_type << endl;    
 f.close();
}

istream& rd2EOL(istream& str)
{
 int ch;
 
 while( (ch=str.get()) != EOF && ch != '\n');
 return str;
}

void ConfigClass::Load(char *filename)
{
 fstream f;
 
 f.open(filename,ios::in);
 f >> x0 >> y0 >> x1 >> y1 >> rd2EOL;
 f >> alpha >> rd2EOL;
 f >> ScreenRotate >> rd2EOL;
 f >> dX >> dY >> rd2EOL;
 f >> x_start >> x_stop >> rd2EOL;
 f >> F_type >> rd2EOL;
 f.close();
    
 MainWindow->UpdateControls();
}
