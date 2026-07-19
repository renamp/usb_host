cmake_minimum_required(VERSION 3.22)

if(COMMAND idf_component_register)
    # --- ESP32 Configuration ---
    idf_component_register(
        SRCS 
            "Src/UsbHost.c"
        INCLUDE_DIRS 
            "Inc/"
        REQUIRES usb_low_level
    )

else()
    add_library(usb_host OBJECT)

    target_sources(usb_host PRIVATE 
        Src/UsbHost.c
    )
    target_include_directories(usb_host PUBLIC 
        Inc
    )
endif()
