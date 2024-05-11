#include"Keyboard.h"

HHOOK hook = NULL;

LRESULT CALLBACK KeyboardHook(int code, WPARAM wp, LPARAM lp) {
	if ((code == HC_ACTION) && ((wp == WM_SYSKEYDOWN) || (lp == WM_KEYDOWN))) {
		KBDLLHOOKSTRUCT hooked = *((KBDLLHOOKSTRUCT*)lp);

		unsigned long tmpScanCode = 1;
		tmpScanCode += hooked.scanCode << 16;
		tmpScanCode += hooked.flags << 24;

		char charName[0x100] = { 0 };
		int i = GetKeyNameText(tmpScanCode, (charName + 1), 255) + 1;

	}
	return CallNextHookEx(hook, code, wp, lp);
}

void Keyboard::Start(void(*callback)(char*)) {
	hook = SetWindowsHookEx(WH_KEYBOARD_LL, KeyboardHook, NULL, NULL);

	MSG msg;
	while (!GetMessage(&msg, NULL, NULL, NULL)){
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}

void Keyboard::Stop() {
	UnhookWindowsHookEx(hook);
}