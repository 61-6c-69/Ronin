#pragma once
#include"WinGui.h"
const char gui_className[] = "MainClass";

LRESULT CALLBACK  WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam){
	switch (msg){
		case WM_DESTROY:
			PostQuitMessage(0);
			break;
		default:
			return DefWindowProc(hwnd, msg, wParam, lParam);
	}
	return 0;
}

void WinGui::Init(){
	WNDCLASSEX wc;
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = NULL;
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = gui_className;
	RegisterClassEx(&wc);
}

HWND WinGui::Winform::CreateForm(){
	this->base_hwnd = CreateWindowEx(
			WS_EX_CLIENTEDGE,
			gui_className,
			TEXT(this->text == NULL ? APP_NAME : this->text),
			WS_OVERLAPPEDWINDOW | WS_VISIBLE,
			CW_USEDEFAULT,
			CW_USEDEFAULT,
			this->width,
			this->height,
			NULL,
			NULL,
			NULL,
			NULL
		);
	return this->base_hwnd;
}

int WinGui::Winform::Show(){
	MSG msg;
	ShowWindow(this->base_hwnd, 1);
	UpdateWindow(this->base_hwnd);
	while (GetMessage(&msg, this->base_hwnd, 0, 0) > 0){
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}

void WinGui::ElementController::Create(HWND base_hwnd){
	this->element = CreateWindow(
		TEXT((this->type() == WinGui::ElementType::_Button ? "BUTTON" : (this->type() == WinGui::ElementType::_Label ? "STATIC" : "EDIT"))),
		TEXT(this->text),
		this->style(),
		this->left,
		this->top,
		this->width,
		this->height,
		base_hwnd,
		NULL,
		NULL,
		NULL
	);
}

void WinGui::ElementController::setText(char* text){
	if (text != NULL){
		SendMessage(this->element, WM_SETTEXT, 0, (LPARAM)text);
	}
}

char* WinGui::ElementController::getText(){
	char text[GUI_TEXT_LENGTH];
	SendMessage(this->element, WM_GETTEXT, sizeof(text), LPARAM(text));
	return text;
}

void WinGui::ElementController::Hide(){
	ShowWindow(this->element, SW_HIDE);
}

void WinGui::ElementController::Show(){
	ShowWindow(this->element, SW_SHOW);
}