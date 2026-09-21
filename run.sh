#!/bin/bash

export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$(pwd)/build/install/lib

./build/install/bin/tiny-c-projects "John Doe"
echo -e "\n---"
./build/install/bin/tiny-c-projects
