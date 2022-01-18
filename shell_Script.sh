#!/usr/bin/sh

# upower -i $(upower -e | grep BAT) | grep --color=never -E "state|to\ full|to\ empty|percentage" >output.txt
 upower -i $(upower -e | grep BAT) | grep --color=never -E "state|percentage">output.txt
# zenity --warning --title=Low_Battery --text="Plugin the charger"
# value=`cat output.txt` 
# echo "$value"
state=`grep  -o charging output.txt`
percent=`grep   -o [0123456789]  output.txt | awk '{print}' ORS=''`
echo $percent
echo "$state"
# grep   [0-9][0-9]  output.txt
# grep   -o [0123456789]  output.txt | awk '{print}' ORS=''


if [ $percent -gt 60 ] && [ "$state" = "charging" ]
then
echo "more than 60% battery"
zenity --warning --title=Low_Battery --text="Unplug the charger"
fi

# if [ "$value2" = "charging" ]
# then
# echo "plugged in"
# zenity --warning --title=Low_Battery --text="Plugin the charger"
# fi

# filename="output.txt"
# count=0
# while read line
# do 
# 	count=`expr $count + 1`
# 	if [ $count -eq 3 ]
# 	then
# 	echo "true"
# 	echo "$line"
	
# 	fi
# done < $filename

#----------------------------------------
#  

# VAR=9
# if [ $VAR -gt 10 ]
# then
#   echo "The variable is greater than 10."
#   else
#   echo " The variable is not greater than 10."
# fi


# VAR1="Linuxize"
# VAR2="Linuxize"

# if [ "$VAR1" = "$VAR2" ]; then
#     echo "Strings are equal."
# else
#     echo "Strings are not equal."
# fi



# CARS="bmw"

# #Pass the variable in string
# case "$CARS" in
# 	#case 1
# 	"mercedes") echo "Headquarters - Affalterbach, Germany" ;;
	
# 	#case 2
# 	"audi") echo "Headquarters - Ingolstadt, Germany" ;;
	
# 	#case 3
# 	"bmw") echo "Headquarters - Chennai, Tamil Nadu, India" ;;
# esac

#--------------------------------------------

# filename="output.txt"

# #While loop to read line by line
# while IFS= read -r line; do
#     #If the line starts with ST then set var to yes.
#     if [[ $line == qwe* ]] ; then
#         printline="yes"
#         # Just t make each line start very clear, remove in use.
#         echo "----------------------->>"
#     fi
#     # If variable is yes, print the line.
#     if [[ $printline == "yes" ]] ; then
#         echo "$line"
#     fi
#     #If the line starts with ST then set var to no.
#     if [[ $line == ewq* ]] ; then
#         printline="no"
#         # Just to make each line end very clear, remove in use.
#         echo "----------------------------<<"
#     fi
# done < "$filename"
