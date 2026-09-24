#!/bin/bash

set -e

script_dir="$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" && pwd)"
install_dir="$script_dir/build/install"

export LD_LIBRARY_PATH="${LD_LIBRARY_PATH:+$LD_LIBRARY_PATH:}$install_dir/lib"

cd "$install_dir/bin"

./tiny-c-projects "John Doe"
echo -e "\n---"
./tiny-c-projects
