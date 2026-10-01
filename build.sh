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
)

case $1 in
    "--prefix")
        PREFIX="$2"
        if [[ -z $2 ]]; then
            printf "\033[0;91merror:\033[0m no directory selected\n" ; exit
        elif [[ ! -d $2 ]]; then
            printf "\033[0;91merror:\033[0m directory does not exist.\n" ; exit
        fi
    ;;
    *)
        if [[ $EUID != 0 ]]; then
            printf "\033[0;91merror:\033[0m you can't run this without root access.\n" ; exit
        fi
        PREFIX="/usr/local/bin"
    ;;
esac

for sourceCode in "${SRC[@]}"; do
    "$CC" src/"$sourceCode".c -o "$PREFIX/$sourceCode"
done