#pragma once

#define EFI_HEADER_SIZE		0x200 /* EFI File pe header size */
#define EFI_FALIGN		0x200 /* EFI File pe file alignment  */
#define EFI_SALIGN		0x1000 /* EFI File pe section alignment */
#define EFI_SECTIONS_NUM	3 /* .text .data .bss */

#ifndef __ASSEMBLY__
_Static_assert(EFI_HEADER_SIZE % EFI_FALIGN == 0 &&
	       EFI_FALIGN % 0x200 == 0 &&
	       EFI_SALIGN % 0x1000 == 0 &&
	       EFI_SALIGN >= EFI_FALIGN &&
	       EFI_SALIGN % EFI_FALIGN == 0, "check failed!");
#endif
