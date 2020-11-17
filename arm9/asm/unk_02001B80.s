    .include "asm/macros.inc"
    .include "global.inc"

	.extern gMain

	.section .rodata

	.balign 4, 0
	.global UNK_020ECAC8
UNK_020ECAC8: ; 0x020ECAC8
	.incbin "graphics/unk_020ECAC8.4bpp"

	.text

	thumb_func_start FUN_02001B80
FUN_02001B80: ; 0x02001B80
	ldr r3, _02001B88 ; =FUN_020191D0
	ldr r0, [r0, #0xc]
	bx r3
	nop
_02001B88: .word FUN_020191D0 
