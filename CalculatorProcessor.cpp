#include "CalculatorProcessor.h"
#include "wx/wx.h"
#include <bitset>
CalculatorProcessor* CalculatorProcessor::instance = nullptr;

CalculatorProcessor* CalculatorProcessor::GetInstance() {
	if (instance == nullptr)
		instance = new CalculatorProcessor();
	return instance;
}

int CalculatorProcessor::GetButtonType(std::string label) {
	if (label.length() > 1 || (char)label.c_str()[0] == 99)
		return 1;
	else if ((char)label.c_str()[0] > 47 && (char)label.c_str()[0] < 58)
		return 2;
	else
		return 3;
}

void CalculatorProcessor::ProcessInput(std::string label, wxTextCtrl* textBox) {
	double product = 0;
	char buffer[256] = { 0, };
	isDec = false;
	isBin = false;
	isHex = false;
	switch (GetButtonType(label)) {
	case 1: // Manipulates the number currently displayed
		switch ((int)label.c_str()[0]) {
		case 43: // +/- negates the current number
			if (!isBin && !isHex)
			{
				if (textBox->GetValue()[0] != '-')
					textBox->SetValue('-' + textBox->GetValue());
				else
					textBox->SetValue(textBox->GetValue().erase('-'));
				break;
			}
		case 66: // Displays the current number in Binary
			if (!isBin) {
				textBox->SetValue(ToBinaryString(currentNum));
				isBin = true;
				isDec = false;
				isHex = false;
				operated = true;
			}
			break;
		case 68: // Displays the current number in Decimal
			if (!isDec) {
				textBox->SetValue(std::to_string(currentNum));
				if (isHex)
					//textBox->SetValue(wxHexToDec(textBox->GetValue()));
				isDec = true;
				isBin = false;
				isHex = false;
				operated = true;
			}
			break;
		case 72: // Displays the current number in Hexidecimal
			if (!isHex) {
				textBox->SetValue(ToHexString(currentNum));
				isHex = true;
				isBin = false;
				isDec = false;
				operated = true;
			}
			break;
		case 99: // Clears the calculator
			firstNum = 0;
			oper = NULL;
			textBox->SetValue("");
			break;
		}
		break;
	case 2: // Appends a number to the text box
		if (operated)
			textBox->Clear();
		textBox->AppendText((wxString)label);
		currentNum = stoi((std::string)textBox->GetValue());
		operated = false;
		break;
	case 3: { // Operators 
		if (textBox->IsEmpty())
			break;
		if (!operated)	{
			switch (oper) {
			case 37: // Modulos
				textBox->SetLabel(std::to_string((int)firstNum % stoi((std::string)textBox->GetValue())));
				break;
			case 47: // Division
				textBox->SetLabel(std::to_string(firstNum / stod((std::string)textBox->GetValue())));
				break;
			case 88: // Multiplication
				textBox->SetLabel(std::to_string(firstNum * stod((std::string)textBox->GetValue())));
				break;
			case 61: // Equals
				break;
			case 43: // Addition
				textBox->SetLabel(std::to_string(firstNum + stod((std::string)textBox->GetValue())));
				break;
			case 45: // Subtraction
				textBox->SetLabel(std::to_string(firstNum - stod((std::string)textBox->GetValue())));
				break;
			default:
				break;
			}
			if ((char)label.c_str()[0] != 61) {
				oper = (char)label.c_str()[0];
				firstNum = stoi((std::string)textBox->GetValue());
			}
			operated = true;
		}
		else
			oper = (char)label.c_str()[0];
	}
		break;
	default:
		break;
	}
	
}

std::string CalculatorProcessor::ToBinaryString(int number) {
	std::string results = "";
	for (int i = 0; i < 16; ++i) {
		results = std::to_string(number % 2) + results;
		number = number / 2;
	}
	return results;
}

std::string CalculatorProcessor::ToHexString(int number) {
	std::string results = "";
	while (number > 0) {
		int remainder = number % 16;
		if (remainder < 10)
			results = std::to_string(remainder) + results;
		else
			results = (char)(remainder + 55) + results;

		number = number / 16;
	}
	return "0x" + results;
}