#!/bin/bash

export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/work/build/install/lib

./build/install/bin/tiny-c-projects "John Doe"
echo -e "\n---"
./build/install/bin/tiny-c-projects
