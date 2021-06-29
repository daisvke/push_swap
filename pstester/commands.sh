#!/bin/bash
#
# AVAILABLE FLAGS
#

while test $# -gt 0
do
	case "$1" in
		-h|--help)
			echo "options:"
			echo -ne "-h, --help\t\tshow brief help\n"
			echo -ne "-m,\t\t\tshow number of moves\n"
			echo -ne "-a,\t\t\tshow all moves\n"
			echo -ne "-e,\t\t\tshow outputs for errors\n"
			exit 0
      		;;
    	-a)
    		export all=true
	  		shift
	  		;;
		-m)
			export move_count=true
			shift
			;;
		-e)
			export err=true
			shift
			;;
		*)
			echo "Invalid option: $1"
      		exit 1
		    break
		    ;;
	esac
done
