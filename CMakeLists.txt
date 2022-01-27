# Set minimum required version of CMake
cmake_minimum_required(VERSION 3.13)

# Include build functions from Pico SDK
include(pico_sdk_import.cmake)

# Include FreeRTOS
include(FreeRTOS_Kernel_import.cmake)

# Set name of project (as PROJECT_NAME) and C/C++ standards
project(spkb_project C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Creates a pico-sdk subdirectory in our project for the libraries
pico_sdk_init()

add_library(spkb_common INTERFACE)
target_sources(spkb_common INTERFACE 
    src/main.c
    src/freertos/hooks.c
    src/input/matrix.c
)

target_include_directories(spkb_common INTERFACE
    ${CMAKE_CURRENT_LIST_DIR}/include
    src/
    src/input
)

# Create C header file with the name <pio program>.pio.h
pico_generate_pio_header(spkb_common ${CMAKE_CURRENT_LIST_DIR}/src/input/matrix_scan.pio)

# Link to pico_stdlib (gpio, time, etc. functions)
target_link_libraries(spkb_common INTERFACE
    pico_stdlib
    hardware_gpio
    hardware_pio
    hardware_i2c
    FreeRTOS-Kernel
    FreeRTOS-Kernel-Heap4
)

add_executable(spkb_master)
target_link_libraries(spkb_master spkb_common)
pico_enable_stdio_usb(spkb_master 1)
pico_enable_stdio_uart(spkb_master 0)
pico_add_extra_outputs(spkb_master)

add_executable(spkb_slave)
target_link_libraries(spkb_slave spkb_common)
target_compile_definitions(spkb_slave PRIVATE
        IS_SLAVE=1
)
pico_enable_stdio_usb(spkb_slave 1)
pico_enable_stdio_uart(spkb_slave 0)
pico_add_extra_outputs(spkb_slave)
