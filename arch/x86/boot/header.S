#include <linux/pe.h>

#include "setup.h"

	.section ".efi_header0", "a"
.Lefi_header_start:
	# "MZ", MS-DOS header
	.word	IMAGE_DOS_SIGNATURE

	.fill	0x38-( . - .Lefi_header_start ), 1, 0
	#
	# Offset to the PE header.
	#
	.long	LINUX_PE_MAGIC
	.long	.Lpe_header - .Lefi_header_start
.Lpe_header:
	.long	IMAGE_NT_SIGNATURE

	.word	IMAGE_FILE_MACHINE_AMD64
	.word	EFI_SECTIONS_NUM		# nr_sections
	.long	0 				# TimeDateStamp
	.long	0				# PointerToSymbolTable
	.long	1				# NumberOfSymbols
	.word	section_table - optional_header	# SizeOfOptionalHeader
	.word	IMAGE_FILE_EXECUTABLE_IMAGE	| \
		IMAGE_FILE_DEBUG_STRIPPED	| \
		IMAGE_FILE_LINE_NUMS_STRIPPED	# Characteristics

optional_header:
	.word	IMAGE_NT_OPTIONAL_HDR64_MAGIC
	.byte	0x02				# MajorLinkerVersion
	.byte	0x14				# MinorLinkerVersion

	# Filled by linker
	#.long	_text_efi_file_size		# FileSizeOfCode
	#.long	_data_efi_file_size		# FileSizeOfInitializedData
	#.long	_bss_efi_file_size		# FileSizeOfUninitializedData
	#.long	efi_pe_entry			# VirtualAddressOfEntryPoint
	#.long	_text				# VirtualBaseOfCode

	.section ".efi_header1", "a"
	.quad	0				# ImageBase
	.long	EFI_SALIGN			# SectionAlignment
	.long	EFI_FALIGN			# FileAlignment
	.word	0				# MajorOperatingSystemVersion
	.word	0				# MinorOperatingSystemVersion
	.word	LINUX_EFISTUB_MAJOR_VERSION	# MajorImageVersion
	.word	LINUX_EFISTUB_MINOR_VERSION	# MinorImageVersion
	.word	0				# MajorSubsystemVersion
	.word	0				# MinorSubsystemVersion
	.long	0				# Win32VersionValue

	# Filled by linker
	#.long	_efi_virtual_end		# VirtualSizeOfImage

	.section ".efi_header2", "a"
	.long	EFI_HEADER_SIZE			# FileSizeOfHeaders
	.long	0				# CheckSum
	.word	IMAGE_SUBSYSTEM_EFI_APPLICATION	# Subsystem (EFI application)
	.word	IMAGE_DLLCHARACTERISTICS_NX_COMPAT	# DllCharacteristics
	.quad	0				# SizeOfStackReserve
	.quad	0				# SizeOfStackCommit
	.quad	0				# SizeOfHeapReserve
	.quad	0				# SizeOfHeapCommit
	.long	0				# LoaderFlags
	.long	(section_table - .) / 8		# NumberOfRvaAndSizes

	.quad	0				# ExportTable
	.quad	0				# ImportTable
	.quad	0				# ResourceTable
	.quad	0				# ExceptionTable
	.quad	0				# CertificationTable
	.quad	0				# BaseRelocationTable

	# Section table
section_table:
	# We put .text and .rodata section together -> .text
	.ascii	".text\0\0\0"
	# Filled by linker
	#.long	_text_size			# VirtualSize
	#.long	_text				# VirtualAddress
	#.long	_text_efi_file_size		# FileSizeOfRawData
	.section ".efi_header3", "a"
	.long	EFI_HEADER_SIZE			# PointerToRawData(FileOffset)
	.long	0				# PointerToRelocations
	.long	0				# PointerToLineNumbers
	.word	0				# NumberOfRelocations
	.word	0				# NumberOfLineNumbers
	.long	IMAGE_SCN_CNT_CODE		| \
		IMAGE_SCN_MEM_READ		| \
		IMAGE_SCN_MEM_EXECUTE		# Characteristics

	.ascii	".data\0\0\0"
	# Filled by linker
	#.long	_data_size			# VirtualSize
	#.long	_data				# VirtualAddress
	#.long	_data_file_size			# FileSizeOfRawData
	#.long	_data_efi_file_offset		# PointerToRawData(FileOffset)
	.section ".efi_header4", "a"
	.long	0, 0, 0
	.long	IMAGE_SCN_CNT_INITIALIZED_DATA	| \
		IMAGE_SCN_MEM_READ		| \
		IMAGE_SCN_MEM_WRITE		# Characteristics

	.ascii	".bss\0\0\0\0"
	# Filled by linker
	#.long	_bss_size			# VirtualSize
	#.long	_bss				# VirtualAddress
	.section ".efi_header5", "a"
	.long	0				# SizeOfRawData
	.long	0				# PointerToRawData
	.long	0, 0, 0
	.long	IMAGE_SCN_CNT_UNINITIALIZED_DATA	| \
		IMAGE_SCN_MEM_READ		| \
		IMAGE_SCN_MEM_WRITE		# Characteristics
