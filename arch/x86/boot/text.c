void efi_pe_entry(void)
{
	__asm__ volatile ("nop");
	__asm__ volatile ("nop");
	__asm__ volatile ("movq %%rax, %%rcx":::);
	__asm__ volatile ("movq %%rcx, %%rax":::);
	__asm__ volatile ("nop");
	while (1) {}
}
int x;
int y = 1;

//int x;
