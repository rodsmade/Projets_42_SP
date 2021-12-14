#!/bin/bash

# VARIABLES
#ARCHITECTURE
OS=$(hostnamectl | grep "Operating System" | sed 's/^[ \t]*//;s/[ \t]*$//' | sed 's/: /:\t/')
KERNEL=$(hostnamectl | grep Kernel | sed 's/^[ \t]*//;s/[ \t]*$//' | sed 's/: /:\t\t/')
ARCH=$(hostnamectl | grep Architecture | sed 's/^[ \t]*//;s/[ \t]*$//' | sed 's/: /:\t/')
CPU=$(lscpu | grep "CPU(s)" | head -1 | tr -s ' ' | sed 's/^[ \t]*//;s/[ \t]*$//' | sed 's/: /:\t\t/')
VCPU=$(cat /proc/cpuinfo | grep processor | wc -l)

#RAM = free --si --total | sed -n '2 p'
RAM_USED=$(free --si --total -h | sed -n '2 p' | tr -s ' ' | cut -d ' ' -f3)
RAM_TOTAL=$(free --si --total -h | sed -n '2 p' | tr -s ' ' | cut -d ' ' -f2)
RAM_AVLBL_PERC=$(free --si --total -m -h | grep Mem | awk '{printf("%0.2f", $3 / $2 * 100)}')

#STORAGE = df -H --total | tail -1
STRG_USED=$(df -H --total | tail -1 | tr -s ' ' | cut -d ' ' -f3)
STRG_TOTAL=$(df -H --total | tail -1 | tr -s ' ' | cut -d ' ' -f2)
STRG_AVLBL_PERC=$(df -H --total | tail -1 | tr -s ' ' | cut -d ' ' -f5)

#PROCESSOR USAGE
PROCESSOR=$(mpstat | grep all | awk '{printf("%s%%", 100 - $13)}')

#LAST BOOT = who -b
LAST_BOOT=$(who -b | tr -s ' ' | sed 's/^[ ]//' | cut -d ' ' -f3,4)

#LVM active or not
LVM_USE=$(lsblk -f | grep LVM -oq && echo yes || echo no)

#ACTIVE CONNECTIONS
TCP_CONNEXN=$(ss -s | grep TCP | sed -n '1 p' | tr -s ' ' | cut -d ' ' -f2)

#USERS CURRENTLY LOGGED IN IN SERVER = who | wc -l
USERS=$(who | wc -l)

#IP AND MAC ADDRESS = hostname -I | cut --delimiter=" " -f2
IP=$(hostname -I | cut --delimiter=" " -f1)
MAC=$(ifconfig | grep ether | cut -d ' ' -f 10)

#The number of commands executed with the sudo program. = cat /var/log/sudo/sudo_logs | grep USER | wc -l
SUDO_COUNT=$(cat /var/log/sudo/sudo_logs | grep USER | wc -l)

# MONITORING PANNEL
echo " # ${OS}"
echo " # ${KERNEL}"
echo " # ${ARCH}"
echo " # ${CPU}"
echo " # vCPU:		${VCPU}"
echo " # Memory Usage:	${RAM_USED} / ${RAM_TOTAL} (${RAM_AVLBL_PERC}%)"
echo " # Disk Usage:		${STRG_USED} / ${STRG_TOTAL} (${STRG_AVLBL_PERC})"
echo " # CPU Usage:		${PROCESSOR}"
echo " # Last boot:		${LAST_BOOT}"
echo " # LVM use:		${LVM_USE}"
echo " # TCP connections:	${TCP_CONNEXN}"
echo " # Logged in users:	${USERS}"
echo " # Network:		${IP} (IP) / ${MAC} (MAC)"
echo " # Sudo:		${SUDO_COUNT}"

