#include "../MEMZ.h"

#ifndef CLEAN
LRESULT CALLBACK watchdogWindowProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	return DefWindowProc(hwnd, msg, wParam, lParam);
}

DWORD WINAPI watchdogThread(LPVOID parameter) {

}
#endif