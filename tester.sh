RED="\033[0;31m"
BRED="\033[1;31m"
GREEN="\033[0;32m"
BGREE="\033[1;32m"
YELLOW="\033[0;33m"
BLUE="\033[0;34m"
PINK="\033[0;35m"
CYAN="\033[0;36m"
RESET="\033[0m"
WHITE="\033[1m"

folder=map_error

## ------ ANTS ERROR ------ ##
path=$folder/ants
err_ants=ants_error_
i=1
j=0
l_ants=$(ls $path | grep "$err_ants" | wc -l)

echo $WHITE"EXEC for $l_ants file       --$RESET\n"
while [ "$i" -le "$l_ants" ]
do
	file="$err_ants$i"
	if [ -e "$path/$file" ]; then
		$(./lem-in < $path/$file > $path/ret)
		ret=$(grep "ERROR" $path/ret)
		echo $ret
		if [ "$ret" == "ERROR" ]; then
			j=$(($j+1))
		else
			echo "$RED$file     $RESET-- no error"
		fi
	fi
	i=$(($i+1))
done
i=$(($i-$j-1))
if [ "$i" -gt 0 ]; then
	echo ""
fi
if [ "$i" -gt 0 ]; then
	echo "$RED$i file with no error   $RESET--"
fi
if [ "$j" -eq "$l_ants" ]; then
	echo $GREEN"WELL DONE ! Good for all file        $RESET--"
elif [ "$j" -gt 0 ]; then
	echo $GREEN"Good for $j file        $RESET--"
fi