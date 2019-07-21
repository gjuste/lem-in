#!/bin/sh
## initilisation ##
RED="\033[0;31m"
BRED="\033[1;31m"
GREEN="\033[0;32m"
BGREEN="\033[1;32m"
YELLOW="\033[0;33m"
BYELLOW="\033[1;33m"
BLUE="\033[0;34m"
BBLUE="\033[1;34m"
PINK="\033[0;35m"
CYAN="\033[0;36m"
BCYAN="\033[1;36m"
RESET="\033[0m"
WHITE="\033[1m"
## chemin de test ##
folder=map_error

readFunction()
{
	case "$1" in
		yes | [yY] | Yes | YES ) start=2;;
		no | [nN] | No | NO ) start=0;;
		* ) read -p "Say yes or no ([yY]/[nN]) : " make; readFunction "$make";;
	esac
}

## ------ INITIALISATION ------ ##
if [ "$1" = "-d" ]; then
	rm -f $folder/*/*ret*
	echo $YELLOW"ret files deleted ✅"
	exit;
fi
if [ -x "lem-in" ]; then
	start=1
else
	printf "Ohoh.. no$WHITE lem-in$RESET ! Do you want to$WHITE make$RESET ? "
	read make
	readFunction "$make"
fi
if [ "$start" -eq 0 ]; then
	exit;
elif [ "$start" -eq 2 ]; then
	echo ""
	make
	echo ""
fi
## options ##
if [ "$1" = "-l" ] || [ "$1" = "--leaks" ]; then
	leaks="valgrind --leak-check=full "
fi

## ------ START PRINT ------ ##
echo $WHITE"***          --- START TESTS ---          ***"$RESET
printf "%45s\n\n" "by gjuste"

## ------ TEST FUNCTION ------ ##
testFunction()
{
	## variable initialisées ##
	i=1
	j=0
	k=0
	nb_test=$(ls $path | grep "$test_name" | wc -l)
	nb_test=$(($nb_test/1))
	## affichage debut série de test ##
	printf $BCYAN"%-19s %19s   ---\n"$RESET "$title TEST" "for $nb_test test"
	## boucle de test ##
	while [ "$i" -le "$nb_test" ]
	do
		file="$test_name$i"
		if [ -e "$path/$file" ]; then
			## recuperation des erreur ##
			$($leaks./lem-in < $path/$file > $path/ret_$test"_$i")
			err=$(grep "ERROR" $path/ret_$test"_$i")
			ld=$(grep "definitely lost" $path/ret_$test"_$i")
			li=$(grep "indirectly lost" $path/ret_$test"_$i")
			## traitement des erreurs ##
			if [ "$err" ]; then
				j=$(($j+1))
			else
				printf $RED"%-28s$RESET-- no error\n" "$file ❌"
			fi
			if [ "$leaks" ] && [ "$ld" ]; then
				k=$(($k+1))
			elif [ "$leaks" ] && [ "$li" ]; then
				k=$(($k+1))
			fi
			## suppression des fichiers inutiles ##
			if [ "$err" ] || [ "$ld" ] || [ "$li" ]; then
				$(rm -f $path/ret_$test"_$i")
			fi
		fi
		i=$(($i+1))
	done
	## affichage resultats des tests ##
	if [ "$nb_test" -eq 0 ]; then
		printf "%-42s---\n\n" "NO TEST TO DO"
	elif [ "$j" -eq "$nb_test" ]; then
		printf $BGREEN"%-42s$RESET---\n\n" "Good for all files ($j/$nb_test test) ✅"
	elif [ "$j" -gt "$(($nb_test/2))" ]; then
		printf $BYELLOW"%-42s$RESET---\n\n" "Good for $j/$nb_test files"
	elif [ "$j" -ge 0 ]; then
		printf $BRED"%-42s$RESET---\n\n" "Good for $j/$nb_test files"
	fi
}

## ------ ANTS ERROR ------ ##
title=ANTS
test=ants
path=$folder/$test
test_name=$test"_error_"
testFunction

## ------ ROOM ERROR ------ ##
title=ROOM
test=room
path=$folder/$test
test_name=$test"_error_"
testFunction

## ------ PIPE ERROR ------ ##
title=PIPE
test=pipe
path=$folder/$test
test_name=$test"_error_"
testFunction

## ------ END PRINT ------ ##
echo $WHITE"***          ---     END     ---          ***"$RESET
