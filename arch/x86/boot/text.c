#include <linux/efi.h>

#include "efistub.h"

const efi_system_table_t *efi_system_table;

static void efi_char16_puts(efi_char16_t *str)
{
	efi_call_proto(efi_table_attr(efi_system_table, con_out),
		       output_string, str);
}

static void __noreturn efi_exit(efi_handle_t handle, efi_status_t status)
{
	efi_bs_call(exit, handle, status, 0, NULL);
	for(;;)
		asm("hlt");
}

efi_status_t __efiapi efi_pe_entry(efi_handle_t handle,
				   efi_system_table_t *sys_table_arg)
{
	efi_system_table = sys_table_arg;

	efi_char16_puts(L"Hello World!\n");
	efi_exit(handle, 0);
}
