cat << EOF
-------------------------------------------------
|                                               |
|        Archlinux install script               |
|                                               |
-------------------------------------------------
EOF

echo "update time"
hwclock --systohc --utc
timedatectl set-timezone Asia/Shanghai
timedatectl set-ntp true

echo "mkfs disk"
mkfs.ext4 /dev/sda2
mkfs.fat /dev/sda1

echo "mount disk"
mount /dev/sda2 /mnt
mkdir -p /mnt/boot/efi
mount /dev/sda1 /mnt/boot/efi

echo "config mirr"
sed -i '/China/!{n;/Server/s/^/#/};t;n' /etc/pacman.d/mirrorlist

echo "pacstrap /mnt base linux linux-firmware"
pacstrap /mnt base linux linux-firmware

echo "genfstab -U /mnt >> /mnt/etc/fstab"
genfstab -U /mnt >> /mnt/etc/fstab
