#include "usb_descriptors.h"

const uint8_t device_descriptor[] = {
    0x12,       // bLength
    0x01,       // bDescriptorType = Device
    0x00, 0x02, // bcdUSB = 2.00
    0x00,       // bDeviceClass = Defined in interface
    0x00,       // bDeviceSubClass
    0x00,       // bDeviceProtocol
    0x40,       // bMaxPacketSize0 = 64 bytes
    0x83, 0x04, // idVendor (random)
    0x50, 0x57, // idProduct
    0x00, 0x01, // bcdDevice
    0x01,       // iManufacturer
    0x02,       // iProduct
    0x03,       // iSerialNumber
    0x01        // bNumConfigurations
};

// Add config descriptor, string descriptors, etc.
