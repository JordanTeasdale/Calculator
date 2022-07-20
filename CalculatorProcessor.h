#pragma once
#include <string>

class wxTextCtrl;

class CalculatorProcessor
{
private:
	static CalculatorProcessor* instance;
	CalculatorProcessor() {}
	int GetButtonType(std::string label);
	
	char oper = NULL;
	double firstNum = 0;
	double currentNum = 0;
	bool operated = false;
	bool isBin = false;
	bool isHex = false;
	bool isDec = false;

public:
	static CalculatorProcessor* GetInstance();
	void ProcessInput(std::string label, wxTextCtrl* textBox);

	CalculatorProcessor(CalculatorProcessor& other) = delete;
	void operator=(CalculatorProcessor& other) = delete;

	std::string ToBinaryString(int number);
	std::string ToHexString(int number);
};

