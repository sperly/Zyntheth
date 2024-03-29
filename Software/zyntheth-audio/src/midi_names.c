#include "usb_names.h"

// Edit these lines to create your own name.  The length must
// match the number of characters in your custom name.

#define PRODUCT_NAME                           \
    {                                          \
        'Z', 'y', 'n', 't', 'h', 'e', 't', 'h' \
    }
#define PRODUCT_NAME_LEN 8

// Do not change this part.  This exact format is required by USB.

struct usb_string_descriptor_struct usb_string_product_name = {
    2 + PRODUCT_NAME_LEN * 2,
    3,
    PRODUCT_NAME};

#define MANUFACTURER_NAME                      \
    {                                          \
        'Z', 'y', 'n', 't', 'h', 'e', 't', 'h' \
    }
#define MANUFACTURER_NAME_LEN 8

// Do not change this part.  This exact format is required by USB.

struct usb_string_descriptor_struct usb_string_manufacturer_name = {
    2 + MANUFACTURER_NAME_LEN * 2,
    3,
    MANUFACTURER_NAME};