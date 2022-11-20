#!/bin/sh

# import .xprofile
[ -f ~/.xprofile ] && . ~/.xprofile

# kill if already running
# killall -9 dunst transmission-daemon

# start picom
# picom --config /home/hooxoo/.config/picom.conf --experimental-backends --animations --animation-window-mass 0.5 --animation-for-open-window zoom --animation-stiffness 100 --animation-dampening 15 &
picom --config /home/hooxoo/.config/picom.conf &

# monitor timeout
xset s 0 &

# xrdb
xrdb ~/.config/.Xresources

# lockscreen
xsidle.sh slock &

# mouse and keyboard
xsetroot -cursor_name left_ptr &
xset r rate 225 25 &
# sxhkd &

# notifications
dunst &

# korean input related
# export GTK_IM_MODULE=kime
# export QT_IM_MODULE=kime
# export XMODIFIERS=@im=kime
kime &

# set wallpaper
bash $HOME/.fehbg &

# torrent
transmission-daemon &

# eww bar
# eww -c $HOME/.config/eww/bar open bar &

# launch dwm status bar
bash $HOME/.config/scripts/dwm_statusbar.sh &

# start wm
exec dwm
# exec bspwm

