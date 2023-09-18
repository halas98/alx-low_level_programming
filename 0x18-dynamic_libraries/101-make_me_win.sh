#!/bin/bash
wget -P /tmp https://github.com/halas98/alx-low_level_programming/master/0x18-dynamic_libraries/libgiga.so
export LD_PRELOAD=/tmp/libgiga.so
