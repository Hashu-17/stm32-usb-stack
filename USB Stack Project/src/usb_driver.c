#include "usb_driver.h"
#include "stm32l433rc.h"

void usb_driver_init(void) {
    // Enable USB peripheral clock
    RCC->APB1ENR1 |= RCC_APB1ENR1_USBFSEN;

    // Configure USB pins and pull-ups if needed (PA11, PA12)
    // Setup endpoint 0 buffer and control

    // Enable USB interrupt
    NVIC_EnableIRQ(USB_IRQn);
}

void USB_IRQHandler(void) {
    // Check for SETUP, RX, TX interrupts
    // Call handler in usb_core.c
}
