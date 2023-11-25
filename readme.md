# Born2Beroot

B2BR

## monitor.sh

```bash
#!/bin/bash

#OS
uname=$(uname -snrvmpio)

#CPU
cpus=$(nproc)
threads=$(lscpu | awk '/Thread/ {print $4; exit}')

#RAM
meminfo=$(free -m | grep ^Mem)

totram=$(echo "$meminfo" | awk '{print $2; exit}')
freeram=$(echo "$meminfo" | awk '{print $4; exit}')
usedram=$(echo "$meminfo" | awk '{print $3; exit}')
rampercentage=$((usedram * 100 / totram))

#DISK
diskraw=$(df -h --total | grep ^total)
diskused=$(echo "$diskraw" | awk '/total/ {print $3; exit}')
disktot=$(echo "$diskraw" | awk '/total/ {print $2; exit}')
diskpercentage=$(echo "$diskraw" | awk '/total/ {print $5; exit}')

#CPU
cpu=$(top -bn 1 | awk 'NR>7 { sum += $9; } END { print sum; }')


#LAST BOOT
lastboot=$(who -b | awk '{print $3 " " $4}')

#LVM
isLvm="no"
if [[ $(which lvm | wc -c) -gt 0 ]]; then
	isLvm="yes"
fi

#CONNECTIONS
established=$(ss -t | grep ESTAB | wc -l)

#ACTIVE USERS
users=$(who | wc -l)

#NETWORK
ip=$(hostname -I)
mac=$(ip link show | awk '/link\/ether/ {print $2;exit}')

#SUDO COMMANDS HISTORY COUNT
totsudo=$(cat /var/log/sudo/sudo.log | grep COMMAND | wc -l)

NL=$'\n'

res=""
res="${res}#Architecture		:	$uname${NL}"
res="${res}#CPU physical		:	$cpus${NL}"
res="${res}#vCPU			:	$threads${NL}"
res="${res}#Memory usage		:	$usedram/${totram}MB (${rampercentage}%)${NL}"
res="${res}#Disk usage		:	${diskused}/${disktot} (${diskpercentage})${NL}"
res="${res}#CPU load:		:	${cpu}%${NL}"
res="${res}#Last boot		:	$lastboot${NL}"
res="${res}#LVM use		:	$isLvm${NL}"
res="${res}#Connections TCP	:	$established${NL}"
res="${res}User log		:	$users${NL}"
res="${res}#Network		:	IP $ip (${mac})${NL}"
res="${res}#Sudo			:	$totsudo cmd"
echo "$res" | wall


```
