@echo off
nasm -fbin loader.asm -o loader.o
copy /b loader.o+Debug\kernel.exe grub2\boot\kernel.bin
mkisofs.exe -relaxed-filenames -J -R -o kernel.iso -b boot/grub/i386-pc/eltorito.img -no-emul-boot -boot-load-size 4 -boot-info-table grub2
if exist "C:\Program Files (x86)\VMware\VMware Workstation\vmplayer.exe" (
	"C:\Program Files (x86)\VMware\VMware Workstation\vmplayer.exe" "Solution2.vmx"
) else if exist "C:\Program Files (x86)\VMware\VMware Player\vmplayer.exe" (
	"C:\Program Files (x86)\VMware\VMware Player\vmplayer.exe" "Solution2.vmx"
) else (
	echo "Please install VMWare Player in order to Run Solution2!"
	pause
	exit
)