#include "WidgetsApp.h"
#include "WidgetsWindow.h"

wxIMPLEMENT_APP(WidgetsApp);

bool WidgetsApp::OnInit() {
	window = new WidgetsWindow();
	window->Show();
	return true;
}