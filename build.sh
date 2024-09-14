#!/bin/sh

CC=gcc
CFLAGS="--pedantic -Wall -Wextra -Wno-unused-parameter `pkg-config --cflags gtk4`"
LFLAGS="-Icode `pkg-config --libs gtk4`"
SOURCES="./code/curly_main.c ./code/curly_application.c ./code/curly_application_window.c"
TARGET=curly

$CC $CFLAGS -o $TARGET $SOURCES $LFLAGS
