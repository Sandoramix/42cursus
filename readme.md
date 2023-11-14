# Born2Beroot

B2BR

## monitor.sh

```bash
#!/bin/bash

#OS
uname=$(uname -a)

#CPU
cpus=$(nproc)
threads=$(lscpu | awk '/Thread/ {print $4; exit}')

#RAM
meminfo=$(free -m | grep ^Mem)

totram=$(echo "$meminfo" | awk '// {print $2; exit}')
freeram=$(echo "$meminfo" | awk '// {print $4; exit}')
usedram=$(echo "$meminfo" | awk '// {print $3; exit}')
rampercentage=$((usedram * 100 / totram))

#DISK
diskraw=$(df -h --total | grep ^total)
diskused=$(echo "$diskraw" | awk '/total/ {print $3; exit}')
disktot=$(echo "$diskraw" | awk '/total/ {print $2; exit}')
diskpercentage=$(echo "$diskraw" | awk '/total/ {print $5; exit}')

#CPU
cpu=$(top -bn 1 | grep "Cpu(s)" | sed "s/.*, *\([0-9.]*\)%* id.*/\1/" | awk '{print 100 - $1}')

#LAST BOOT
lastboot=$(who -b | awk '// {print $3 " " $4}')

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
totsudo=$(awk '/COMMAND=.*sudo/ {count++} END {print count}' /var/log/sudo/sudo.log)

#echo	"#Architecture		:	$uname"
#echo	"#CPU physical		:	$cpus"
#echo	"#vCPU			:	$threads"
#echo	"#Memory usage		:	$usedram/${totram}MB (${rampercentage}%)"
#echo	"#Disk usage		:	${diskused}/${disktot} (${diskpercentage})"
#echo	"#CPU load:		:	${cpu}%"
#echo	"#Last boot		:	$lastboot"
#echo	"#LVM use		:	$isLvm"
#echo	"#Connections TCP	:	$established"
#echo	"User log		:	$users"
#echo	"#Network		:	IP $ip (${mac})"
echo	"#Sudo			:	$totsudo cmd"
```
