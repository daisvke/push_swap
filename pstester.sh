#!/bin/bash
#     _    _    _    _    _    _    _    _  
#    / \  / \  / \  / \  / \  / \  / \  / \ 
#   ( p )( s )( t )( e )( s )( t )( e )( r )
#    \_/  \_/  \_/  \_/  \_/  \_/  \_/  \_/ 


# Arrays of tested numbers
twoDig=("1 2" "2 1")

threeDig=("1 3 2" "2 1 3" "2 3 1" "3 1 2" "3 2 1")

fourDig=(
	"1 2 4 3" "1 3 2 4" "1 3 4 2" "1 4 2 3" "1 4 3 2"
	"2 1 3 4" "2 1 4 3" "2 3 1 4" "2 4 1 3" "2 4 3 1" 
	"3 1 2 4"  "3 2 4 1" "3 2 1 4" "3 4 1 2" "3 4 2 1"
	"4 1 3 2" "4 2 1 3" "4 2 3 1" "4 3 1 2" "4 3 2 1"
	)

fiveDig=(
	"1 2 3 5 4" "1 2 4 3 5" "1 2 4 5 3" "1 2 5 4 3" "1 3 4 5 2" "1 3 5 4 2" "1 4 5 2 3"
	"2 1 3 4 5" "2 3 4 1 5" "2 3 4 5 1" "2 3 5 1 4" "2 4 5 1 3" "2 5 4 3 1"
	"3 2 1 4 5" "3 2 4 5 1" "3 2 5 4 1" "3 4 5 1 2" "3 4 5 2 1" "3 5 2 1 4"
	"4 2 3 5 1" "4 3 2 1 5" "4 3 5 1 2" "4 3 5 2 1" "4 5 2 3 1" "4 5 3 2 1"
	"5 1 2 3 4" "5 2 3 4 1" "5 3 1 2 4" "5 3 4 2 1" "5 4 2 3 1" "5 4 3 2 1"
	)

sixDig=(
	"1 2 3 4 6 5" "1 2 3 5 6 4"
	"2 1 3 4 5 6" "2 1 3 5 4 6"
	"3 2 1 4 5 6" "3 2 1 5 4 6"
	)

twentyDig=(
	"1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 17 16 18 20 19"
)

# Change this to checker_Mac if needed
CHECKER=checker_linux

# Your header location (if not at root)
# INC=push_swap.h

# Look for the libft folder and make it
if [[ -e libft ]]
then
	cd libft; sudo make; cd ..
	LIB=libft/libft.a
fi

# Colors
CYAN="\033[36m"
GREEN="\033[32m"
RED="\033[31m"
NC="\033[0m"

# Remove previous executable file
rm -f a.out 2> /dev/null
# Remove previous log file
rm -f log 2> /dev/null

# Compile (without flags !)
# All '.c' files have to be in the 'src' folder
gcc src/*.c $INC $LIB

while test $# -gt 0; do
	case "$1" in
		-h|--help)
			echo "options:"
			echo -ne "-h, --help\t\tshow brief help\n"
			echo -ne "-a,\t\t\tshow all moves\n"
			echo -ne "-e,\t\t\tshow moves for errors\n"
			echo -ne "-o,\t\t\tshow output from executable (no checker)"
			exit 0
      		;;
    	-a)
    		export ALL=true
	  		shift
	  		;;
		-e)
			export ERR=true
			shift
			;;
		-o)
			export OUT=true
			shift
			;;
		*)
			echo "Invalid option: $1"
      		exit 1
		    break
		    ;;
	esac
done

# Display moves
function printMoves ()
{
	echo -ne "\n"
	./a.out $1 2> /dev/null
	echo -ne "\n"
}

# Main testing function
function tester ()
{
	# Print label 
	echo -e "${CYAN}$1${NC}"
	shift
	# Testing loop
	for i in "$@"
	do
		# Feed log file
		echo -en "[$i]" >> log
		printMoves "$i" >> log
		# Print moves
		if [[ $ALL ]]
		then
			printMoves "$i"
		fi
		RES=$(./a.out $i 2> /dev/null | ./$CHECKER $i)
		if [[ $RES == "OK" ]]
		then # Print 'OK'
			echo -en "${GREEN}[$i]${NC} "
		elif [[ $RES == "KO" ]] # Print 'KO'
		then
			echo -en "\n${RED}[$i]${NC} "
			if [[ $ERR ]]
			then
				printMoves "$i"
			fi
		else
			if [[ $OUT ]]
			then
				echo -en "[$i]"
				printMoves "$i"
			else
				echo -en "${RED}[${RES}]${NC} "
			fi
		fi
	done
	echo -e "\n"
}

#
# Testing
#

echo -en "\n"
echo -e "START...\n"

# Two digits
tester "=== TWO DIGITS ===" "${twoDig[@]}"

# Three digits
tester "=== THREE DIGITS ===" "${threeDig[@]}"

# Four digits
tester "=== FOUR DIGITS ===" "${fourDig[@]}"

# Five digits
tester "=== FIVE DIGITS ===" "${fiveDig[@]}"

# Six digits
tester "=== SIX DIGITS ===" "${sixDig[@]}"

# Twenty digits
tester "=== TWENTY DIGITS ===" "${twentyDig[@]}"

echo -en "...END\n"
echo -en "\n"
