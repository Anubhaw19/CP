#!/usr/bin/sh

#UPower command tool for getting battery% and charging status and storing in a seperate txt file(batpower.txt)
upower -i $(upower -e | grep BAT) | grep --color=never -E "state|percentage">batstatus.txt

#getting charging status
state=`grep  -o -w 'charging\|discharging' batstatus.txt`
#getting battery percentage status
percent=`grep   -o [0123456789]  batstatus.txt | awk '{print}' ORS=''`
echo "percentage : $percent%"
echo "state : $state"


#notify if battery% >=70 and charging
if [ $percent -ge 70 ] && [ "$state" = "charging" ]
then
echo "Kindly unplug your charger"
zenity --warning --title=Bat_Charged --text="Unplug the charger"
fi
#warns if  battery%<=30 and discharging
if [ $percent -le 30 ] && [ "$state" = "discharging" ]
then
echo "Kindly plug your charger"
zenity --error --title=Bat_LOW --text="Plug in the charger"
fi

# watch -n 10 ./test.sh
