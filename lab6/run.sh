#!/bin/bash

APP_PATH="./build/Bobrov_cam"

if [ -f "$APP_PATH" ]; then
    $APP_PATH
else
    echo "Error: executable file not found!"
    echo "To compile project run: ./build.sh"
    exit 1
fi