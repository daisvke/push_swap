#!/bin/bash
#
# CONFIG FILE
#

#
# CHECKER
#
# Change this to checker_Mac if needed
checker=checker_linux

#
# HEADER
#
# inc=../push_swap.h

#
# LIBFT
#
# Look for the libft folder and make it
if [[ -e ../libft ]]
then
	cd ../libft; sudo make; cd ../pstester
	lib=../libft/libft.a
fi

#
# GCC
#
src="../src/*.c"
#mem="-fsanitize=address"
#flags="-Wall -Wextra -Werror $mem"
cc="clang $flags"

#
# TIMEOUT
#
timeout=.02

#
# COLORS
#
cyan="\033[36m"
green="\033[32m"
red="\033[31m"
nc="\033[0m"
