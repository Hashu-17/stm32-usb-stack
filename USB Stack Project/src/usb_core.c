#include "usb_core.h"
#include "usb_descriptors.h"

void usb_core_init(void) {
    // Setup endpoint 0 state machine
    // Maybe respond to USB RESET with default address
}

void usb_poll(void) {
    // Called in main loop, handles polling SETUP packets
    // Decode control transfer stages: SETUP -> DATA -> STATUS
}

void usb_handle_setup_packet(/* params */) {
    // Handle GET_DESCRIPTOR, SET_ADDRESS, etc.
}
