#pragma once
#include "wx/wx.h"
#include <vector>

class WidgetsWindow : public wxFrame
{
private:
	std::vector<wxButton*> buttons;
	wxTextCtrl* TextBox = nullptr;
	std::vector<std::string> symbols{ "+/-", "c", "Bin", "Hex", "Dec", "7", "8", "9", "%", "4", "5", "6", "/", "1", "2", "3", "X", "0", "=", "+", "-" };

	wxButton* bttnNegator = nullptr;
	wxButton* bttn0 = nullptr;
	wxButton* bttn1= nullptr;
	wxButton* bttn2 = nullptr;
	wxButton* bttn3 = nullptr;
	wxButton* bttn4 = nullptr;
	wxButton* bttn5 = nullptr;
	wxButton* bttn6 = nullptr;
	wxButton* bttn7 = nullptr;
	wxButton* bttn8 = nullptr;
	wxButton* bttn9 = nullptr;
	wxButton* bttnEquals = nullptr;
	wxButton* bttnC = nullptr;
	wxButton* bttnBin = nullptr;
	wxButton* bttnHex = nullptr;
	wxButton* bttnDec = nullptr;
	wxButton* bttnMinus = nullptr;
	wxButton* bttnPlus = nullptr;
	wxButton* bttnMultiply = nullptr;
	wxButton* bttnDivide = nullptr;
	wxButton* bttnMod = nullptr;

public:
	WidgetsWindow();

	void OnButtonClicked(wxCommandEvent& evt);

	wxDECLARE_EVENT_TABLE();
};

