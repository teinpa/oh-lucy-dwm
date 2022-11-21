#!/bin/sh

RET=$(echo -e "play-pause\nnext\nprevious\nstop\ncancel" | dmenu -nb "#1e1d23" -nf "#7ec49d" -sb "#7ec49d" -sf "#1e1d23" -X 15 -Y 5 -W 2150 -p "MUSIC:")

case $RET in
  play-pause) playerctl play-pause ;;
  next) playerctl next ;;
  previous) playerctl previous ;;
  stop) playerctl stop ;;
  *) ;;
esac

