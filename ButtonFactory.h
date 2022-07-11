#pragma once
#include "WidgetsWindow.h"

class wxButton;

class ButtonFactory
{
public:
	static void CreateButton(wxWindow *parent, std::vector<wxButton*>& buttons, const char* symbol, int x = 0, int y = 0);
};

