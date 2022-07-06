#pragma once
#include "wx/wx.h"

class WidgetsWindow;

class WidgetsApp : public wxApp
{
	WidgetsWindow* window = nullptr;
public:
	virtual bool OnInit();
};

