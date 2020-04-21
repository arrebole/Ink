echo "install drivers"
pacman -S xf86-video-intel xf86-video-nouveau
echo "install desktop"
pacman -S sway alacritty wofi
#-->
#   path ~/.config/sway/config
#   
#   设置间隔
#   gaps inner 10
#   gaps outer 5
#
#   设置无边框
#   default_border pixel
#  
#   终端与启动器
#   set $menu dmenu_path | wofi --show drun -i | xargs swaymsg exec --
#   set $term alacritty
#   
#
#<--