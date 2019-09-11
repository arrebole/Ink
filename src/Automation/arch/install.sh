cat << EOF
-------------------------------------------------
|                                               |
|        Archlinux install script               |
|                                               |
-------------------------------------------------
EOF
echo "更新系统时钟"
hwclock --systohc --utc
timedatectl set-timezone Asia/Shanghai
timedatectl set-ntp true
echo "磁盘格式化"
mkfs.ext4 /dev/sda2
mkfs.fat /dev/sda1
echo "挂载磁盘"
mount /dev/sda2 /mnt
mkdir -p /mnt/boot/EFI
mount /dev/sda1 /mnt/boot/EFI
echo "配置安装源"
pacman -Syu
sed -i '/China/!{n;/Server/s/^/#/};t;n' /etc/pacman.d/mirrorlist
echo "安装基础文件"
pacstrap /mnt base
echo "生成分区表"
genfstab -U /mnt >> /mnt/etc/fstab
echo "进入挂载系统"
arch-chroot /mnt
echo "设置时区"
ln -sf /usr/share/zoneinfo/Asia/Shanghai /etc/localtime
echo "设置硬件时间"
hwclock --systohc --utc
timedatectl set-timezone Asia/Shanghai
timedatectl set-ntp true
echo "设置语言"
cat << EOF >> /etc/locale.gen
en_US.UTF-8 UTF-8
zh_CN.UTF-8 UTE-8
zh_TW.UTF-8 UTF-8
EOF
locale-gen
echo LANG=en_US.UTF-8  > /etc/locale.conf
echo "设置主机名"
echo archlinux > /etc/hostname
cat << EOF >> /etc/hosts
127.0.0.1	localhost
::1		    localhost
127.0.1.1	archlinux.localdomain	archlinux
EOF
echo "创建普通用户"
pacman -S zsh
useradd -m -g wheel -s /bin/zsh hacker
pacman -S adobe-source-han-sans-cn-fonts
echo "设置启动引导"
pacman -S dosfstools grub efibootmgr
grub-install --target=x86_64-efi --efi-directory=/boot/EFI --bootloader-id=GRUB
grub-mkconfig -o /boot/grub/grub.cfg
# echo "安装网络"
# pacman -S wpa_supplicant
# systemctl enable wpa_supplicant
# systemctl enable dhcpcd