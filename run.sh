#!/bin/env bash

Xephyr :1 -ac -br -noreset -screen 800x600 &
sleep 1
DISPLAY=:1.0 gdb build/jwm