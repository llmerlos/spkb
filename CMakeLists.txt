# Set minimum required version of CMake
cmake_minimum_required(VERSION 3.12)

# Include build functions from Pico SDK
include(pico_sdk_import.cmake)

# Include FreeRTOS
include(FreeRTOS_Kernel_import.cmake)

# Set name of project (as PROJECT_NAME) and C/C++ standards
project(spkb C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Creates a pico-sdk subdirectory in our project for the libraries
pico_sdk_init()

# Tell CMake where to find the executable source file
add_executable(spkb
    src/main.c
)

target_include_directories(spkb PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/include
)

# Link to pico_stdlib (gpio, time, etc. functions)
target_link_libraries(spkb
    pico_stdlib
    hardware_gpio
    FreeRTOS-Kernel
    FreeRTOS-Kernel-Heap4
)

# Enable usb output, disable uart output
pico_enable_stdio_usb(spkb 1)
pico_enable_stdio_uart(spkb 0)

# Create map/bin/hex/uf2 files
pico_add_extra_outputs(spkb)