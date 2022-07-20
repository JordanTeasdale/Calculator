
#include "CppUnitTest.h"
#include "../ButtonFactory.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ButtonFactoryTests
{
	TEST_CLASS(ButtonFactoryTests)
	{
	public:
		wxWindow* window = new wxFrame(nullptr, wxID_ANY, "Calculator", wxPoint(200, 200), wxSize(515, 790));
		TEST_METHOD(ButtonLabelPlus)
		{
			std::vector<wxButton*> buttons;
			ButtonFactory factory;
			factory.CreateButton(window, buttons, "+", 125, 125);
			Assert::AreEqual(buttons[0]->GetLabel(), "+");
		}
		TEST_METHOD(ButtonIDPlus)
		{
			std::vector<wxButton*> buttons;
			ButtonFactory factory;
			factory.CreateButton(window, buttons, "+", 125, 125);
			bool result(buttons[0]->GetId() == 10043);
			Assert::IsTrue(result);
		}

		TEST_METHOD(ButtonLabelBin)
		{
			std::vector<wxButton*> buttons;
			ButtonFactory factory;
			factory.CreateButton(window, buttons, "Bin", 125, 125);
			Assert::AreEqual(buttons[0]->GetLabel(), "Bin");
		}
		TEST_METHOD(ButtonIDBin)
		{
			std::vector<wxButton*> buttons;
			ButtonFactory factory;
			factory.CreateButton(window, buttons, "Bin", 125, 125);
			bool result(buttons[0]->GetId() == 10066);
			Assert::IsTrue(result);
		}

		TEST_METHOD(ButtonLabel2)
		{
			std::vector<wxButton*> buttons;
			ButtonFactory factory;
			factory.CreateButton(window, buttons, "2", 125, 125);
			Assert::AreEqual(buttons[0]->GetLabel(), "2");
		}
		TEST_METHOD(ButtonID2)
		{
			std::vector<wxButton*> buttons;
			ButtonFactory factory;
			factory.CreateButton(window, buttons, "2", 125, 125);
			bool result(buttons[0]->GetId() == 10050);
			Assert::IsTrue(result);
		}

		TEST_METHOD(ButtonLabel0)
		{
			std::vector<wxButton*> buttons;
			ButtonFactory factory;
			factory.CreateButton(window, buttons, "0", 125, 125);
			Assert::AreEqual(buttons[0]->GetLabel(), "0");
		}
		TEST_METHOD(ButtonID6)
		{
			std::vector<wxButton*> buttons;
			ButtonFactory factory;
			factory.CreateButton(window, buttons, "0", 125, 125);
			bool result(buttons[0]->GetId() == 10048);
			Assert::IsTrue(result);
		}

		TEST_METHOD(ButtonLabelModulos)
		{
			std::vector<wxButton*> buttons;
			ButtonFactory factory;
			factory.CreateButton(window, buttons, "%", 125, 125);
			Assert::AreEqual(buttons[0]->GetLabel(), "%");
		}
		TEST_METHOD(ButtonIDP8)
		{
			std::vector<wxButton*> buttons;
			ButtonFactory factory;
			factory.CreateButton(window, buttons, "%", 125, 125);
			bool result(buttons[0]->GetId() == 10037);
			Assert::IsTrue(result);
		}

	};
}