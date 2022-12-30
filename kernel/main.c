#include <stdint.h>
#include <intrin.h>
#include "printf.h"

struct multiboot_information {
	uint32_t flags;
	uint32_t mem_lower;
	uint32_t mem_upper;
	uint32_t boot_device;
	uint32_t cmdline;
	uint32_t mods_count;
	uint32_t mods_addr;
	uint8_t syms[12];
	uint32_t mmap_length;
	uint32_t mmap_addr;
	uint32_t drives_length;
	uint32_t drives_addr;
	uint32_t config_table;
	uint32_t boot_loader_name;
	uint32_t apm_table;
	uint32_t vbe_control_info;
	uint32_t vbe_mode_info;
	uint32_t vbe_mode;
	uint16_t vbe_interface_seg;
	uint16_t vbe_interface_off;
	uint16_t vbe_interface_len;
	uint64_t framebuffer_addr;
	uint32_t framebuffer_pitch;
	uint32_t framebuffer_width;
	uint32_t framebuffer_height;
	uint8_t framebuffer_bpp;
	uint8_t framebuffer_type;
	uint8_t color_info[5];
};

int main(struct multiboot_information* mboot,uint32_t magic)
{
	console_initialize();
	printf("sizeof void*:%d\n",sizeof(void*));
	printf("fb:0x%x",mboot->framebuffer_addr);
	for (;;);
}