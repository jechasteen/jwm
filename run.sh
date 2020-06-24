#!/bin/env bash

Xephyr :1 -ac -br -noreset -screen 800x600 &
sleep 1

if [ "$1" = "debug" ]; then
    DISPLAY=:1.0 gdb build/jwm
else
    DISPLAY=:1.0 build/jwm
fi
