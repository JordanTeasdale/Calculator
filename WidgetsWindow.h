#pragma once
#include "wx/wx.h"
#include <vector>

class WidgetsWindow : public wxFrame
{
private:
	std::vector<wxButton*> buttons;
	wxTextCtrl* TextBox = nullptr;
	std::vector<std::string> symbols{ "+/-", "c", "Bin", "Hex", "Dec", "7", "8", "9", "%", "4", "5", "6", "/", "1", "2", "3", "X", "0", "=", "+", "-" };

public:
	WidgetsWindow();

	void OnButtonClicked(wxCommandEvent& evt);

	wxDECLARE_EVENT_TABLE();
};

