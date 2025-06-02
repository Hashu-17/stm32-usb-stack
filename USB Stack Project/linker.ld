/* Linker script for STM32L433RCT6 (256KB Flash, 64KB RAM) */

ENTRY(Reset_Handler)

/* Define memory regions */
MEMORY
{
  FLASH (rx)  : ORIGIN = 0x08000000, LENGTH = 256K
  RAM   (xrw) : ORIGIN = 0x20000000, LENGTH = 64K
}

/* Define sections */
SECTIONS
{
  /* Vector table and startup code */
  .isr_vector :
  {
    KEEP(*(.isr_vector))       /* Ensure vector table is included */
  } > FLASH

  /* Read-only code (text), read-only data (rodata), and init arrays */
  .text :
  {
    *(.text*)
    *(.rodata*)
    *(.init)
    *(.fini)
    KEEP(*(.init_array*))
    KEEP(*(.fini_array*))
  } > FLASH

  /* .data section: initialized data copied to RAM */
  .data : AT(__etext)
  {
    __data_start__ = .;
    *(.data*)
    __data_end__ = .;
  } > RAM

  /* .bss section: uninitialized data in RAM */
  .bss :
  {
    __bss_start__ = .;
    *(.bss*)
    *(COMMON)
    __bss_end__ = .;
  } > RAM

  /* Stack section: stack grows down from end of RAM */
  ._stack :
  {
    . = ALIGN(8);
    __stack_top__ = ORIGIN(RAM) + LENGTH(RAM);
    __stack_bottom__ = __stack_top__ - 0x1000;  /* 4KB stack */
  } > RAM

  /* End of RAM */
  __end__ = .;
}

/* Symbols for startup code */
__etext = LOADADDR(.data);
__stack = __stack_top__;
