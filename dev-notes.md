# SD Organizer

**Idea**: a board with multiple SD card readers and an eink screen that organizes your SD cards by reading info from the images and displaying it next to each SD card. 

**HW**: microcontroller-based SPI master, with all SD holders on a single SPI bus, and eink screen on 2nd SPI bus. 

**SW**: microcontroller sits waiting for SD hotplug detection (TODO: how?).  On detect SD insert, read blocks at known offsets (TODO: how messy will this be?) to read top level config files or os-release.  Display on eink screen, then back to sleep.  Minimize SD read ops to avoid wear.  On power on, cycle through each slot sequentially to populate SD card information. 

## For Linux Image on SD card:
- Mount the SD card's root partition
- Check the contents of /etc/os-release which typically contains distribution information

```
eric@ubuntu-air:/media/eric/sys-1Dh$ ll
total 96
drwxr-xr-x  19 root root  4096 Nov 15  2023 ./
drwxr-x---+  3 root root  4096 Mar 25 18:31 ../
lrwxrwxrwx   1 root root     7 Feb  3  2022 bin -> usr/bin/
drwxr-xr-x   2 root root  4096 Nov 15  2023 boot/
drwxr-xr-x   2 root root  4096 Feb  3  2022 build/
drwxr-xr-x   4 root root  4096 Feb  3  2022 dev/
drwxr-xr-x  82 root root  4096 Mar 21 14:53 etc/
drwxr-xr-x   3 root root  4096 Sep 13  2023 home/
-rw-r--r--   1 root root   399 Sep 22  2023 imx-linux-5.15.71-29-boundary-20j
-rw-r--r--   1 root root   416 Nov 15  2023 imx-linux-5.15.71-30-boundary-20j
lrwxrwxrwx   1 root root     7 Feb  3  2022 lib -> usr/lib/
drwx------   2 root root 16384 Mar  4  2020 lost+found/
drwxr-xr-x   2 root root  4096 Feb  3  2022 media/
drwxr-xr-x   2 root root  4096 Sep 13  2023 mnt/
drwxr-xr-x  13 eric eric  4096 Mar 21 14:53 opt/
drwxr-xr-x   2 root root  4096 Nov  8  2021 proc/
drwxr-xr-x   6 root root  4096 Mar 24 11:49 root/
drwxr-xr-x   8 root root  4096 Feb  9  2022 run/
lrwxrwxrwx   1 root root     8 Feb  3  2022 sbin -> usr/sbin/
drwxr-xr-x   2 root root  4096 Feb  3  2022 srv/
drwxr-xr-x   2 root root  4096 Nov  8  2021 sys/
drwxrwxrwt  11 root root  4096 Mar 24 14:57 tmp/
drwxr-xr-x  11 root root  4096 Feb  3  2022 usr/
drwxr-xr-x  12 root root  4096 Sep 15  2023 var/
```

Note: os-release can be symlinked, as in nvidia jetson image below
```
lrwxrwxrwx   1 root root       21 Feb 14  2024 os-release -> ../usr/lib/os-release
```


## Examples:
**Yocto custom image:**
```
ID=fsl-imx-xwayland-boundary
NAME="NXP i.MX Release Distro"
VERSION="6.6-scarthgap (scarthgap)"
VERSION_ID=6.6-scarthgap
VERSION_CODENAME="scarthgap"
PRETTY_NAME="NXP i.MX Release Distro 6.6-scarthgap (scarthgap)"
CPE_NAME="cpe:/o:openembedded:fsl-imx-xwayland-boundary:6.6-scarthgap"
```


**Ubuntu image:**
```
PRETTY_NAME="Ubuntu 22.04.3 LTS"
NAME="Ubuntu"
VERSION_ID="22.04"
VERSION="22.04.3 LTS (Jammy Jellyfish)"
VERSION_CODENAME=jammy
ID=ubuntu
ID_LIKE=debian
HOME_URL="https://www.ubuntu.com/"
SUPPORT_URL="https://help.ubuntu.com/"
BUG_REPORT_URL="https://bugs.launchpad.net/ubuntu/"
PRIVACY_POLICY_URL="https://www.ubuntu.com/legal/terms-and-policies/privacy-policy"
UBUNTU_CODENAME=jammy
```


**RaspberryPi image (from rpi flasher):** 
```
PRETTY_NAME="Debian GNU/Linux 12 (bookworm)"
NAME="Debian GNU/Linux"
VERSION_ID="12"
VERSION="12 (bookworm)"
VERSION_CODENAME=bookworm
ID=debian
HOME_URL="https://www.debian.org/"
SUPPORT_URL="https://www.debian.org/support"
BUG_REPORT_URL="https://bugs.debian.org/"
```
