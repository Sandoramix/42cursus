# DEBIAN

Premise: there won't be much of a theory explained here, but every command and/or section's name is a good hint of what you should lookup on the Internet.

## Download ISO

https://www.debian.org/distrib/

The `small installation image` is all we need. Version downloaded is [`debian-12.9.0-amd64-netinst/ 64-bit PC netinst ISO`](https://cdimage.debian.org/debian-cd/current/amd64/iso-cd/debian-12.9.0-amd64-netinst.iso). Other versions might be slightly different.
![download](images/debian/download.png)

### Mandatory
#### Install

![start install](images/debian/install/start.png)

##### Select your preferences

1. Choose the language
2. Choose the location
3. Choose the keymap

##### Configure the network

1. Set up the hostname with your `<login>`.
![alt text](images/debian/install/hostname.png)
2. Set up the domain name. You can leave it to default, which is provided to you by your router. Or you can set it to blank.

##### Set up users and passwords

###### Root

Set up the root password.

1. Set up the root password and confirm it.
![How to set up the root password](images/debian/install/root-password.png)

###### User

Set up the user with your `<login>` and password.

1. Full name: up to you
2. Username: your `<login>`
3. Password: password

##### Configure the clock

Set up the time zone.

##### Partition disks

You can either do it manually or you can use the Guided Partitioning Tool. I prefer the latter because it has all necessary options.

1. Choose the partitioning method.
	![alt text](images/debian/install/partitioning/method.png)
2. Select the disk to partition.
	![alt text](images/debian/install/partitioning/disk.png)
3. Choose the partitioning scheme. We need to separate the `/home` and `/` partitions. So the second choice is the most suitable.
	![alt text](images/debian/install/partitioning/scheme.png)
4. Confirm the overwirte of the partition table.
	![alt text](images/debian/install/partitioning/confirm.png)
5. Choose the encrpypted partition's passphrase. **Attention**: the passphrase is case-sensitive and you cannot change it. It should be quite long (write it down somewhere). Then confirm it.
	![alt text](images/debian/install/partitioning/encrypt-passphrase.png)
6. Choose the partition's size. I prefer to use the entire disk space.
	![alt text](images/debian/install/partitioning/encrypt-size.png)
7. Confirm the partitioning and write the changes to the disk.
	![alt text](images/debian/install/partitioning/finish-partitioning.png)
8. Confirm the changes.
	![alt text](images/debian/install/partitioning/confirm-changes.png)
##### Install the operating system

Wait for the installation to finish.

##### Configure the package manager

###### Installation media

Skip if the sections shows up.
![alt text](images/debian/install/package-manager/extra-installation-media.png)

###### Archive mirror country

Choose the country closest to you. Still any country is fine. I'll be using the `United States`.
![alt text](images/debian/install/package-manager/archive-mirror-country.png)
![alt text](images/debian/install/package-manager/archive-mirror.png)

###### Proxy

Skip.
![alt text](images/debian/install/package-manager/proxy.png)

##### Configuring popularity-contest

Skip. Or if you want to, you can enable it.
![alt text](images/debian/install/popularity-contest.png)

##### Software selection

1. Remove any option of the `Debian desktop environment` section and choose `SSH server` and `Standard system utilities`.
	![alt text](images/debian/install/software-selection/software-selection.png)

##### Configuring grub-pc

In order to boot the system, you need to configure the boot loader. The boot loader is responsible for loading the kernel and choosing+loading the operating system.

![alt text](images/debian/install/configuring-grub-pc.png)
![alt text](images/debian/install/configuring-grub-pc-2.png)

##### COMPLETE

![alt text](images/debian/install/complete.png)

---

#### Configuration

First of all, you need to log in to the system. After inserting the crypted partition password, you should be able to see the login screen. Use your `<login>` and password to login.

P.s. remember that the system's services configuration should be edited by users with higher privileges than the standard. So you should be using the `sudo <command>` (super user do; run as root) command to edit the configuration files, or switch to the root user with the `su -` (switch user; without any username specified it will try to login as root. `-` is needed to update the working directory to the switched user's home directory and update the environment variables) command and do everything with the root user.

---

##### Switch to root user

**For simplicity**, I'll be using the `su -` command to switch to the root user.

```bash
su -
```

and enter the root password.

```bash
<root-password>
```

---

##### SSH

Starting with [`SSH`](https://www.techtarget.com/searchsecurity/definition/Secure-Shell) (secure shell) will be useful for the following reasons:
- By remotely accessing the system, you'll have a more useful shell and you'll be able to copy-paste text from the host (physical machine) to the guest (virtual machine).

###### Install

It should be already installed, because of the installation of the `standard system utilities` + `SSH server` in the previous step. But if you want to install it manually, you can do it with the following command:

```bash
apt install openssh-server
```

###### Configure

The configuration file is located in `/etc/ssh/sshd_config`.
You can configure the SSH server with the following any text editor. I'll be using the `nano` command.

1. Open the configuration file with the following command:

	```bash
	nano /etc/ssh/sshd_config
	```

2. Configure the following options by uncommenting them if commented out and set the values accordingly:

	```ini
	#...
	# Listen on port 4242
	Port 4242
	# Listen on from any IP address
	ListenAddress 0.0.0.0
	#...
	# Deny access with root login
	PermitRootLogin no
	```
	Save and exit the editor. (CTRL + S and then CTRL + X)

3. Restart the SSH server with the following command:

	```bash
	systemctl restart ssh
	```
	or
	```bash
	service ssh restart
	```


###### 
