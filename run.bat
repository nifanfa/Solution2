nasm -fbin loader.asm -o loader.o
copy /b loader.o+Debug\kernel.exe grub2\boot\kernel.bin
mkisofs.exe -relaxed-filenames -J -R -o kernel.iso -b boot/grub/i386-pc/eltorito.img -no-emul-boot -boot-load-size 4 -boot-info-table grub2
"C:\Program Files\qemu\qemu-system-x86_64.exe" -m 1024 -smp 2 -k en-gb -boot d -cdrom kernel.iso -d guest_errors -serial stdio -device AC97 -rtc base=localtime