#!/bin/bash
#     _    _    _    _    _    _    _    _  
#    / \  / \  / \  / \  / \  / \  / \  / \ 
#   ( p )( s )( t )( e )( s )( t )( e )( r )
#    \_/  \_/  \_/  \_/  \_/  \_/  \_/  \_/ 

source config.sh
source commands.sh
source short_sets.sh
source long_sets.sh

#
# CLEAN
#
# Remove previous executable file
rm -f a.out 2> /dev/null
# Remove previous log file
rm -f log 2> /dev/null

#
# COMPILE
#
$cc $src $inc $lib

# Display moves
function printMoves ()
{
	echo -ne "\n"
	timeout $timeout ./a.out $1 2> /dev/null	
	export moves=$(timeout $timeout ./a.out $1 2> /dev/null | wc -l)
	echo -ne "\n"
}

#
# FUNCTIONS
#
# Variables to get the total score
score=0 # Total OKs
average=0;
total=0 # Total tests
unsorted=0 # Total unsorted lists 
hm=0 # Total higher moves
count=0 # Number of tested combinations for a set 

# Main testing function
function tester ()
{
	# Print label 
	echo -e "${cyan}$1${nc}"
	# Allowed max moves
	limit=$2
	shift
	shift
	average=0
	count=0
	# testing loop
	for i in "$@"
	do
		total=$[$total + 1]
		# Feed log file
		echo -en "[$i]" >> log
		printMoves "$i" >> log
		# Variable that displays number of moves
		if [[ $move_count ]]
		then
			display_move_count=" (${moves}mv)"
		fi
		# Print moves
		if [[ $all ]]
		then
			printmoves "$i"
		fi
		res=$(timeout $timeout ./a.out $i 2> /dev/null | ./$checker $i)
		if [[ $res == "OK" ]] && [[ $moves -le $limit ]]
		then # Print 'OK'
			((score++))
			echo -en "${green}[$i${display_move_count}]${nc} "
		elif [[ $res == "KO" ]] # print 'ko'
		then
			((unsorted++))
			if [[ $err ]]
			then
				echo -en "\n${red}[$i${display_move_count}]${nc} "
				printmoves "$i"
			else
				echo -en "${red}[$i${display_move_count}]${nc} "
			fi
		elif [[ $res == "OK" ]] && [[ $moves -gt $limit ]]
		then
			((hm++))
			echo -en "${red}[HM:$i${display_move_count}]${nc} "
		else
			echo -en "${red}[${res}]${nc} "
		fi
		average=$[$average + $moves]
		count=$[$count + 1]
	done
	average=$[$average / $count]
	echo -e "\n"
	echo -e "Average: $average moves"
	echo -e "\n"
}

#
# Testing
#

echo -en "\n"
echo -e "START...\n"

# Non continuous numbers
tester "=== NON CONTINUOUS ===" "12" "${nonContinuous[@]}"
# Two elements
tester "=== 2  ===" "1" "${two[@]}"
# Three elements
tester "=== 3 ELEMENTS ===" "2" "${three[@]}"
# Four elements
tester "=== 4 ELEMENTS ===" "12" "${four[@]}"
# Five elements
tester "=== 5 ELEMENTS ===" "12" "${five[@]}"
# Six elements
tester "=== 6 ELEMENTS ===" "13" "${six[@]}"
# Seven elements
tester "=== 7 ELEMENTS ===" "17" "${seven[@]}"
# Twenty elements
tester "=== 20 ELEMENTS ===" "90" "${twenty[@]}"
# Hundred elements
tester "=== 100 ELEMENTS ===" "1100" "${hundred[@]}"
# Five hundred elements
ulimit -s 65000000 # Increase max command arguments
tester "=== 500 ELEMENTS ===" "5500" "${five_hundred[@]}"

#
# Print results
#

echo -en "...END\n\n"
echo -en "Your score:\t\t$score/$total\n"
echo -en "Unsorted lists:\t\t$unsorted\n"
echo -en "Higher moves:\t\t$hm"
echo -en "\n\n"

#
# Clean
#
rm -f ../*.gch 2> /dev/null
