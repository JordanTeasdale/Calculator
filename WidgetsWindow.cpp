#include "WidgetsWindow.h"

wxBEGIN_EVENT_TABLE(WidgetsWindow, wxFrame)
EVT_BUTTON(10000, WidgetsWindow::OnButtonClicked)
EVT_BUTTON(10001, WidgetsWindow::OnButtonClicked)
EVT_BUTTON(10002, WidgetsWindow::OnButtonClicked)
EVT_BUTTON(10003, WidgetsWindow::OnButtonClicked)
EVT_BUTTON(10004, WidgetsWindow::OnButtonClicked)
EVT_BUTTON(10005, WidgetsWindow::OnButtonClicked)
EVT_BUTTON(10006, WidgetsWindow::OnButtonClicked)
EVT_BUTTON(10007, WidgetsWindow::OnButtonClicked)
EVT_BUTTON(10008, WidgetsWindow::OnButtonClicked)
EVT_BUTTON(10009, WidgetsWindow::OnButtonClicked)
EVT_BUTTON(10010, WidgetsWindow::OnButtonClicked)
EVT_BUTTON(10011, WidgetsWindow::OnButtonClicked)
EVT_BUTTON(10012, WidgetsWindow::OnButtonClicked)
EVT_BUTTON(10013, WidgetsWindow::OnButtonClicked)
EVT_BUTTON(10014, WidgetsWindow::OnButtonClicked)
EVT_BUTTON(10015, WidgetsWindow::OnButtonClicked)
EVT_BUTTON(10016, WidgetsWindow::OnButtonClicked)
EVT_BUTTON(10017, WidgetsWindow::OnButtonClicked)
EVT_BUTTON(10018, WidgetsWindow::OnButtonClicked)
EVT_BUTTON(10019, WidgetsWindow::OnButtonClicked)
EVT_BUTTON(10020, WidgetsWindow::OnButtonClicked)
wxEND_EVENT_TABLE()

WidgetsWindow::WidgetsWindow() : wxFrame(nullptr, wxID_ANY, "Calculator", wxPoint(200, 200), wxSize(515, 790)) {
	wxFont font(50, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false);
	wxFont font2(24, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false);
	TextBox = new wxTextCtrl(this, wxID_ANY, "", wxPoint(125, 0), wxSize(375, 125));
	TextBox->SetFont(font);
	buttons.push_back(bttnC = new wxButton(this, wxID_ANY, "+/-", wxPoint(0, 0), wxSize(125, 125)));
	buttons.push_back(bttnC = new wxButton(this, wxID_ANY, 'c', wxPoint(0, 125), wxSize(125, 125)));
	buttons.push_back(bttnBin = new wxButton(this, wxID_ANY, "Bin", wxPoint(125, 125), wxSize(125, 125)));
	buttons.push_back(bttnHex = new wxButton(this, wxID_ANY, "Hex", wxPoint(250, 125), wxSize(125, 125)));
	buttons.push_back(bttnDec = new wxButton(this, wxID_ANY, "Dec", wxPoint(375, 125), wxSize(125, 125)));
	buttons.push_back(bttn7 = new wxButton(this, wxID_ANY, '7', wxPoint(0, 250), wxSize(125, 125)));
	buttons.push_back(bttn8 = new wxButton(this, wxID_ANY, '8', wxPoint(125, 250), wxSize(125, 125)));
	buttons.push_back(bttn9 = new wxButton(this, wxID_ANY, '9', wxPoint(250, 250), wxSize(125, 125)));
	buttons.push_back(bttnMod = new wxButton(this, wxID_ANY, '%', wxPoint(375, 250), wxSize(125, 125)));
	buttons.push_back(bttn4 = new wxButton(this, wxID_ANY, '4', wxPoint(0, 375), wxSize(125, 125)));
	buttons.push_back(bttn5 = new wxButton(this, wxID_ANY, '5', wxPoint(125, 375), wxSize(125, 125)));
	buttons.push_back(bttn6 = new wxButton(this, wxID_ANY, '6', wxPoint(250, 375), wxSize(125, 125)));
	buttons.push_back(bttnDivide= new wxButton(this, wxID_ANY, '/', wxPoint(375, 375), wxSize(125, 125)));
	buttons.push_back(bttn1 = new wxButton(this, wxID_ANY, '1', wxPoint(0, 500), wxSize(125, 125)));
	buttons.push_back(bttn2 = new wxButton(this, wxID_ANY, '2', wxPoint(125, 500), wxSize(125, 125)));
	buttons.push_back(bttn3 = new wxButton(this, wxID_ANY, '3', wxPoint(250, 500), wxSize(125, 125)));
	buttons.push_back(bttnMultiply = new wxButton(this, wxID_ANY, 'X', wxPoint(375, 500), wxSize(125, 125)));
	buttons.push_back(bttn0 = new wxButton(this, wxID_ANY, '0', wxPoint(0, 625), wxSize(125, 125)));
	buttons.push_back(bttnEquals = new wxButton(this, wxID_ANY, '=', wxPoint(125, 625), wxSize(125, 125)));
	buttons.push_back(bttnPlus = new wxButton(this, wxID_ANY, '+', wxPoint(250, 625), wxSize(125, 125)));
	buttons.push_back(bttnMinus = new wxButton(this, wxID_ANY, '-', wxPoint(375, 625), wxSize(125, 125)));

	for (int i = 0; i < buttons.size(); ++i) {
		buttons[i]->SetFont(font2);
		buttons[i]->SetId(10000 + i);
		//buttons[i]->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &WidgetsWindow::OnButtonClicked, this);
	}
}

void WidgetsWindow::OnButtonClicked(wxCommandEvent& evt) {
	int index = (evt.GetId() - 10000);
	TextBox->AppendText(buttons[index]->GetLabel());

	evt.Skip();
}