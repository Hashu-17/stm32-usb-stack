#include "usb_core.h"
#include "usb_driver.h"

int main(void) {
    usb_driver_init();     // Low-level hardware init
    usb_core_init();       // Protocol-level init

    while (1) {
        usb_poll();        // Handle USB events
    }
}
