#include <intrin.h>

int cursor_x = 0;
int cursor_y = 0;

void console_initialize() {
	cursor_x = 0;
	cursor_y = 0;
	__stosw(0xb8000, 0x0F00, 80 * 25);

	__outbyte(0x3D4, 0x0A);
	__outbyte(0x3D5, ((__inbyte(0x3D5) & 0xC0) | 0));
	__outbyte(0x3D4, 0x0B);
	__outbyte(0x3D5, ((__inbyte(0x3D5) & 0xE0) | 15));
	__outbyte(0x3D4, 0x0A);
	__outbyte(0x3D5, 0b1110);
}

void console_putchar(char c) {
	if (c == '\n')goto newline;

	unsigned short* ptr = 0xb8000;
	ptr[cursor_y * 80 + cursor_x] = 0x0F00|c;
	cursor_x++;
	if (cursor_x >= 80) {
	newline:
		cursor_x = 0;
		cursor_y++;
	}

	short pos = (cursor_y * 80) + cursor_x;
	__outbyte(0x3D4, 0x0F);
	__outbyte(0x3D5, (pos & 0xFF));
	__outbyte(0x3D4, 0x0E);
	__outbyte(0x3D5, ((pos >> 8) & 0xFF));
}