#!/bin/bash

CC="gcc"
SRC=(
    "cat"
    "clear"
    "echo"
    "ls"
    "mkdir"
    "touch"
    "uname"
    "yes"
)

if ! command -v "$CC" &>/dev/null; then
    printf "\033[0;91merror:\033[0m C compiler not found => \033[1m$CC.\033[0m\n" ; exit 1
fi

case $1 in
    "--prefix")
        PREFIX="$2"
        if [[ -z $2 ]]; then
            printf "\033[0;91merror:\033[0m no directory selected\n" ; exit 1
        elif [[ ! -d $2 ]]; then
            printf "\033[0;91merror:\033[0m directory does not exist.\n" ; exit 1
        fi
    ;;
    *)
        if [[ $EUID -ne 0 ]]; then
            printf "\033[0;91merror:\033[0m you can't run this without root access.\n" ; exit 1
        fi
        PREFIX="/usr/local/bin"
    ;;
esac

for sourceCode in "${SRC[@]}"; do
    "$CC" src/"$sourceCode".c -o "$PREFIX/$sourceCode"
done
