#pragma once
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")
#include"Ronin.h"

class WinGui{
	enum  ElementType
	{
		_Button,
		_Label,
		_Textbox
	};
protected:
	class ElementInfo{
	public:
		int top;
		int left;
		int width;
		int height;
		char* text;
	};

	class ElementController : public ElementInfo{
	protected:
		virtual ElementType type() const{
			return ElementType::_Label;
		}
		virtual DWORD style() const{
			return WS_VISIBLE | WS_CHILD;
		}
	public:
		HWND element;
		void Create(HWND base_hwnd);
		void setText(char* text);
		char* getText();
		void Hide();
		void Show();
	};
public:
	void Init();

	//windows form
	class Winform: public ElementInfo{
	protected:	
	public:
		HWND base_hwnd;
		HWND CreateForm();
		int Show();
	};
	
	//element
	class Button : public ElementController{
	protected:
		ElementType type() const override{
			return ElementType::_Button;
		}
	};

	class Label : public ElementController{
	protected:
		ElementType type() const override{
			return ElementType::_Label;
		}
	};

	class TextBox : public ElementController{
	protected:
		ElementType type() const override{
			return ElementType::_Textbox;
		}
		DWORD style() const override{
			return WS_BORDER | WS_CHILD | WS_VISIBLE | ES_LEFT | ES_AUTOVSCROLL;
		}
	};

	class TextArea : public ElementController{
	protected:
		ElementType type() const override{
			return ElementType::_Textbox;
		}
		DWORD style() const override{
			return WS_BORDER | WS_CHILD | WS_VISIBLE | ES_LEFT | ES_MULTILINE | ES_AUTOVSCROLL | WS_HSCROLL | WS_VSCROLL;
		}
	};

	class Number : public ElementController{
	protected:
		ElementType type() const override{
			return ElementType::_Textbox;
		}
		DWORD style() const override{
			return WS_BORDER | WS_CHILD | WS_VISIBLE | ES_LEFT | ES_NUMBER | ES_AUTOVSCROLL;
		}
	};
};