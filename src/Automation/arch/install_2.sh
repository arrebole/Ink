echo "config localtime"
ln -sf /usr/share/zoneinfo/Asia/Shanghai /etc/localtime
echo "hwclock time"
hwclock --systohc --utc
timedatectl set-timezone Asia/Shanghai
timedatectl set-ntp true
echo "config locale.gen"
cat << EOF >> /etc/locale.gen
en_US.UTF-8 UTF-8
zh_CN.UTF-8 UTE-8
zh_TW.UTF-8 UTF-8
EOF
locale-gen
echo LANG=en_US.UTF-8  > /etc/locale.conf
echo "config hostname"
echo archlinux > /etc/hostname
cat << EOF >> /etc/hosts
127.0.0.1	localhost
::1		    localhost
127.0.1.1	archlinux.localdomain	archlinux
EOF
echo "add user"
pacman -S zsh
useradd -m -g wheel -s /bin/zsh hacker
pacman -S adobe-source-han-sans-cn-fonts
echo "grub efi"
pacman -S dosfstools grub efibootmgr
grub-install --target=x86_64-efi --efi-directory=/boot/EFI --bootloader-id=GRUB
grub-mkconfig -o /boot/grub/grub.cfg
echo "install gui"
pacman -S nvidia nvidia-utils
pacman -S gnome
# echo "安装网络"
# pacman -S wpa_supplicant
# systemctl enable wpa_supplicant
# systemctl enable dhcpcd