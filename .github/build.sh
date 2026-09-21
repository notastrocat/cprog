#!/usr/bin/env bash

set -euo pipefail

script_dir="$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" && pwd)"
build_dir="$script_dir/../build"

if ! command -v clang >/dev/null 2>&1 || ! command -v clang++ >/dev/null 2>&1; then
	if ! command -v apt-get >/dev/null 2>&1; then
		printf 'error: clang is missing and apt-get is unavailable\n' >&2
		exit 1
	fi

	apt=(apt-get)
	if [[ "$EUID" -ne 0 ]]; then
		if ! command -v sudo >/dev/null 2>&1; then
			printf 'error: installing clang requires root or sudo\n' >&2
			exit 1
		fi
		apt=(sudo apt-get)
	fi

	printf 'clang is missing; installing it with apt-get...\n'
	"${apt[@]}" update
	"${apt[@]}" install -y --no-install-recommends clang
fi

cmake -S "$script_dir/.." -B "$build_dir" \
	-DCMAKE_C_COMPILER=clang \
	-DCMAKE_CXX_COMPILER=clang++
cmake --build "$build_dir"
cmake --install "$build_dir"
