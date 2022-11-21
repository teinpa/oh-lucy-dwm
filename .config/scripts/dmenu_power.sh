#!/bin/sh

RET=$(echo -e "shutdown\nreboot\nlogout\nlock\ncancel" | dmenu -nb "#1e1d23" -nf "#ff7da3" -sb "#ff7da3" -sf "#1e1d23" -X 15 -Y 5 -W 2150 -p "POWER:")

case $RET in
	shutdown) poweroff ;;
	reboot) reboot ;;
	logout) pkill -KILL -u hooxoo ;;
  lock) exec slock ;;
	*) ;;
esac   

