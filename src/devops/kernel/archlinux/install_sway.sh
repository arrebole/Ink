echo "install drivers"
pacman -S xf86-video-intel # xf86-video-nouveau

echo "install desktop"
pacman -S sway waybar alacritty wofi xorg-server-xwayland
