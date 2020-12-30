echo "config localtime"
ln -sf /usr/share/zoneinfo/Asia/Shanghai /etc/localtime

echo "hwclock time"
hwclock --systohc --utc
timedatectl set-timezone Asia/Shanghai
timedatectl set-ntp true

echo "config locale.gen"
cat << EOF >> /etc/locale.gen
en_US.UTF-8 UTF-8
zh_CN.UTF-8 UTF-8
zh_TW.UTF-8 UTF-8
EOF
locale-gen
echo LANG=en_US.UTF-8  > /etc/locale.conf

echo "config hostname"
echo universe > /etc/hostname
cat << EOF >> /etc/hosts
127.0.0.1	localhost
::1		    localhost
127.0.1.1	universe.localdomain	universe
EOF

echo "add user"
pacman -S zsh sudo
useradd -m -g wheel -s /bin/zsh hacker
pacman -S ttf-fira-code

echo "network"
pacman -S dhcpcd
systemctl enable dhcpcd
# pacman -S wpa_supplicant
# systemctl enable wpa_supplicant

echo "add archlinuxcn"
cat << EOF >> /etc/pacman.conf
[archlinuxcn]
SigLevel = Optional TrustAll
Server = https://repo.archlinuxcn.org/\$arch
EOF
pacman -Syu

echo "grub efi"
pacman -S dosfstools grub efibootmgr
grub-install --target=x86_64-efi --efi-directory=/boot/efi --bootloader-id=GRUB
grub-mkconfig -o /boot/grub/grub.cfg
