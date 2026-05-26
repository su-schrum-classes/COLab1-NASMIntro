#!/usr/bin/env bash
set -o pipefail

nasm -felf64 Assembly.asm -o Assembly.o
if [ $? -ne 0 ]; then
    echo "Compilation failed: nasm failed." >&2
    exit 1
fi

gcc Grade.c Assembly.o -o grade.out
if [ $? -ne 0 ]; then
    echo "Compilation failed: gcc failed." >&2
    exit 1
fi

./grade.out
exit_code=$?

if [ $exit_code -eq 0 ]; then
    exit 0
else
    exit 1
fi
