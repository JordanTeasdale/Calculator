
#include "CppUnitTest.h"
#include "../CalculatorProcessor.h"
#include "wx/wx.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CalculatorProcessorTests
{
	TEST_CLASS(CalculatorProcessorTests)
	{
	public:
		wxWindow* window = new wxFrame(nullptr, wxID_ANY, "Calculator", wxPoint(200, 200), wxSize(515, 790));
		TEST_METHOD(HexConvert12345)
		{
			CalculatorProcessor* processor = CalculatorProcessor::GetInstance();
			Assert::AreEqual((std::string)"0x3039", processor->ToHexString(12345));
		}
		TEST_METHOD(HexConvert67890)
		{
			CalculatorProcessor* processor = CalculatorProcessor::GetInstance();
			Assert::AreEqual((std::string)"0x10932", processor->ToHexString(67890));
		}
		TEST_METHOD(HexConvert345678)
		{
			CalculatorProcessor* processor = CalculatorProcessor::GetInstance();
			Assert::AreEqual((std::string)"0x5464E", processor->ToHexString(345678));
		}
		TEST_METHOD(BinConvert12345)
		{
			CalculatorProcessor* processor = CalculatorProcessor::GetInstance();
			Assert::AreEqual((std::string)"0011000000111001", processor->ToBinaryString(12345));
		}
		TEST_METHOD(BinConvert56789)
		{
			CalculatorProcessor* processor = CalculatorProcessor::GetInstance();
			Assert::AreEqual((std::string)"1101110111010101", processor->ToBinaryString(56789));
		}
		TEST_METHOD(BinConvert789123)
		{
			CalculatorProcessor* processor = CalculatorProcessor::GetInstance();
			Assert::AreEqual((std::string)"0000101010000011", processor->ToBinaryString(789123));
		}
		TEST_METHOD(Add12345And67890)
		{
			CalculatorProcessor* processor = CalculatorProcessor::GetInstance();
			wxTextCtrl* textBox = new wxTextCtrl(window, wxID_ANY, "", wxPoint(125, 0), wxSize(375, 125));
			textBox->SetValue(std::to_string(12345));
			processor->ProcessInput("+", textBox);
			processor->ProcessInput("1", textBox);
			textBox->SetValue(std::to_string(67890));
			processor->ProcessInput("=", textBox);
			Assert::AreEqual("80235.000000", textBox->GetValue());
		}
		TEST_METHOD(Subtract12345And67890)
		{
			CalculatorProcessor* processor = CalculatorProcessor::GetInstance();
			wxTextCtrl* textBox = new wxTextCtrl(window, wxID_ANY, "", wxPoint(125, 0), wxSize(375, 125));
			textBox->SetValue(std::to_string(12345));
			processor->ProcessInput("-", textBox);
			processor->ProcessInput("1", textBox);
			textBox->SetValue(std::to_string(67890));
			processor->ProcessInput("=", textBox);
			Assert::AreEqual("-55545.000000", textBox->GetValue());
		}
		TEST_METHOD(Multiply12345And67890)
		{
			CalculatorProcessor* processor = CalculatorProcessor::GetInstance();
			wxTextCtrl* textBox = new wxTextCtrl(window, wxID_ANY, "", wxPoint(125, 0), wxSize(375, 125));
			textBox->SetValue(std::to_string(12345));
			processor->ProcessInput("X", textBox);
			processor->ProcessInput("1", textBox);
			textBox->SetValue(std::to_string(67890));
			processor->ProcessInput("=", textBox);
			Assert::AreEqual("838102050.000000", textBox->GetValue());
		}
		TEST_METHOD(Divide12345And67890)
		{
			CalculatorProcessor* processor = CalculatorProcessor::GetInstance();
			wxTextCtrl* textBox = new wxTextCtrl(window, wxID_ANY, "", wxPoint(125, 0), wxSize(375, 125));
			textBox->SetValue(std::to_string(12345));
			processor->ProcessInput("/", textBox);
			processor->ProcessInput("1", textBox);
			textBox->SetValue(std::to_string(67890));
			processor->ProcessInput("=", textBox);
			Assert::AreEqual("0.181838", textBox->GetValue());
		}
	};
}
