cmake_minimum_required(VERSION 3.13)

include(pico_sdk_import.cmake)

project(mosfet_drive C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
pico_sdk_init()

add_executable(mosfet_drive
    main.c
)

pico_add_extra_outputs(mosfet_drive)

target_include_directories(mosfet_drive INTERFACE ./)

target_link_libraries(mosfet_drive pico_stdlib hardware_pwm)

