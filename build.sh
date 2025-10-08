#!/bin/bash

CPPFLAGS=(-D__KERNEL__ -include include/linux/compiler_types.h -I./arch/x86/include -I include/ -I./arch/x86/include/uapi -I./include/uapi)

set -x
clang-me "${CPPFLAGS[@]}" -D__ASSEMBLY__ arch/x86/boot/header.S -c -o arch/x86/boot/header.o
clang-me "${CPPFLAGS[@]}" -fshort-wchar -fpie arch/x86/boot/text.c -c -o arch/x86/boot/text.o
clang-me "${CPPFLAGS[@]}" -D__ASSEMBLY__ arch/x86/boot/setup.lds.S -E -o arch/x86/boot/setup.lds

ld -pie --no-dynamic-linker -T arch/x86/boot/setup.lds arch/x86/boot/text.o arch/x86/boot/header.o -o arch/x86/boot/setup.elf
objcopy -O binary -j .text arch/x86/boot/setup.elf arch/x86/boot/setup_text.bin
objcopy -O binary -j .data arch/x86/boot/setup.elf arch/x86/boot/setup_data.bin
objcopy -O binary -j .efi_header arch/x86/boot/setup.elf arch/x86/boot/efi_header.bin

(dd if=arch/x86/boot/efi_header.bin bs=512 conv=sync status=none;
dd if=arch/x86/boot/setup_text.bin bs=512 conv=sync status=none;
dd if=arch/x86/boot/setup_data.bin bs=512 conv=sync status=none) > arch/x86/boot/bootx64.efi
