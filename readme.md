# Born2Beroot

B2BR

---

## Update apt

```bash
apt update && apt upgrade -y
```

---

## Sudo

### Install sudo

```bash
apt install sudo
```

### Sudo Configuration

```bash
sudo visudo
```
or (not recommended)

```bash
nano /etc/sudoers
```

Add/Edit/Uncomment the following lines:

```config
# Reset environment variables (only for the running command) on each sudo command execution
Defaults	env_reset
# Send a mail to the users's specified email if the running sudo does not enter a valid command
Defaults	mail_badpass
# Limit the $PATH variable for sudo command
Defaults	secure_path="/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/snap/bin"


Defaults	use_pty
Defaults	requiretty

Defaults	passwd_tries=3
Defaults	insults

Defaults	logfile="/var/log/sudo/sudo.log"
Defaults	iolog_dir="/var/log/sudo"
Defaults	log_input,log_output

Defaults	timestamp_timeout=15

root		ALL=(ALL:ALL) ALL

%sudo		ALL=(ALL:ALL) NOPASSWD: /bin/ls, /usr/bin/apt-get, /usr/bin/apt
%sudo		ALL=(ALL:ALL) ALL, !/bin/rm !/bin/su
```

---

## SSH

### Install the service with

*If you're not root use the `sudo` command*
```bash
apt install openssh-server
```

### SSH Configuration

```bash
nano /etc/ssh/sshd_config
```

Edit/uncomment the following lines:
```
# Listen for connections on port 4242
Port 4242

# Listen for connections with any IP
ListenAddress 0.0.0.0

PermitRootLogin prohibit-password

# OPTIONAL (if you want to login with the public key:
# You'll need to put into needed user's `~/.ssh/authorized_keys` file your public key)
PubKeyAuthentication yes
```

---

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
