cmake_minimum_required(VERSION 3.22)

set(PLATFORM_BUILD_ARCH "i386"
    CACHE STRING "i386" FORCE)

set(PLATFORM_BUILD_BOOT_TYPE "elf32"
    CACHE STRING "elf32; efi" FORCE)

set(PLATFORM_BUILD_DISABLE_WARNINGS ON
    CACHE BOOL "ON; OFF" FORCE)