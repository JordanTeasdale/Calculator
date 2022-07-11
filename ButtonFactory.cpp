#include "ButtonFactory.h"
#include "wx/wx.h"

void ButtonFactory::CreateButton(wxWindow* parent, std::vector<wxButton*>& buttons, const char* symbol, int x, int y) {
	wxButton* newButton = new wxButton(parent, wxID_ANY, symbol, wxPoint(x, y), wxSize(125, 125));
	buttons.push_back(newButton);

}
