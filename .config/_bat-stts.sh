#!/usr/bin/bash

chargestatus="$(cat /sys/class/power_supply/BAT1/status)" 
chargepercent="$(cat /sys/class/power_supply/BAT1/capacity)"
chargemax="$(cat /sys/class/power_supply/BAT1/charge_control_end_threshold)"

printf "\nBattery :: \n\t[Status]       %s \n\t[Current]      %s \n\t[Max Capacity] %s \n" "$chargestatus" "$chargepercent" "$chargemax"