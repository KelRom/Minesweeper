#include "WidgetsApp.h"
wxIMPLEMENT_APP(WidgetsApp);
WidgetsApp::WidgetsApp()
{}

WidgetsApp::~WidgetsApp()
{}

bool WidgetsApp::OnInit()
{
    window = new WidgetsFrame();
    window->Show();
    return true;
}
