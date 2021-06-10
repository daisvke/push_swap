#!/bin/bash
#     _    _    _    _    _    _    _    _  
#    / \  / \  / \  / \  / \  / \  / \  / \ 
#   ( p )( s )( t )( e )( s )( t )( e )( r )
#    \_/  \_/  \_/  \_/  \_/  \_/  \_/  \_/ 


# Arrays of tested numbers
threeDig=("1 3 2" "2 1 3" "3 1 2" "2 3 1" "3 2 1")
fourDig=("34 5 2 7" "4 1 3 7" "4 1 3 2" "4 3 5 2" \
	"1 2 4 3" "1 3 2 4" "1 4 3 2")
fiveDig=("1 2 3 5 4" "4 2 3 5 1")

# Change this to checker_Mac if needed
CHECKER=checker_linux

# Colors
CYAN="\033[36m"
GREEN="\033[32m"
RED="\033[31m"
NC="\033[0m"

# Compile
gcc src/*.c push_swap.h libft/libft.a

# Function
function tester ()
{
	# Print label 
	echo -e "${CYAN}$label${NC}\n"
	# Testing loop
	for i in "$@"
	do
		# Print tested numbers
#		echo -e "${CYAN}[$i]${NC}"
		# Print moves
		# ./a.out $i
		RES=$(./a.out $i | ./$CHECKER $i)
		if [[ $RES == "OK" ]]
		then # Print 'OK'
			echo -en "${GREEN}[$i]${NC} "
		elif [[ $RES == "KO" ]] # Print 'KO'
		then
			echo -e "${RED}[${RES}]${NC}\n"
		else
			echo -e "${RED}[${RES}]${NC}\n"
		fi
	done
}

#
# Testing
#

echo -e "\n"
echo "START"

# Three digits
tester "=== THREE DIGITS ===" "${threeDig[@]}"

# Four digits
tester "=== FOUR DIGITS ===" "${fourDig[@]}"

