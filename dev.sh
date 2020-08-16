#!/usr/bin/env bash

nodemon --exec "gcc *.c -o main.o && ./main.o" -e "c"
