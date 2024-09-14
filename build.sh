#!/bin/sh

CC=gcc
CFLAGS="
    --pedantic -Wall -Wextra
    -Wno-unused-parameter -Wno-unused-function -Wno-unused-variable
    `pkg-config --cflags gtk4` `pkg-config --cflags libcurl`"
LFLAGS="
    -Icode
    `pkg-config --libs gtk4`
    `pkg-config --libs libcurl`"
SOURCES="
    ./code/curly_main.c
    ./code/curly_application.c
    ./code/curly_application_window.c
    ./code/curly_request_input.c"
TARGET=curly

$CC $CFLAGS -o $TARGET $SOURCES $LFLAGS
