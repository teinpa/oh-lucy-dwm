#!/bin/sh

time=`date +%s`
dir="`xdg-user-dir PICTURES`/screenshots"
file="ss_${time}.png"

# notify via dunst
notify_user () {
	if [[ -e "$dir/$file" ]]; then
	dunstify "Saved in $dir" -u low
	fi
}

# fullscreen shot
shotnow () {
  cd ${dir} && sleep 1 && maim -u -f png -m 3 "$file"
  notify_user
}

# active window shot
shotwin () {
  cd ${dir} && maim -u -f png -i `xdotool getactivewindow` -m 3 "$file"
  notify_user
}

# selected area shot
shotarea () {
  cd ${dir} && maim -u -f png -s -b 2 -c 0.35,0.55,0.85,0.25 -l -m 3 "$file"
  notify_user
}

SHOT=$(echo -e "fullscreen\nwindow\narea\ncancel" | dmenu -nb "#1e1d23" -nf "#8bb8d0" -sb "#8bb8d0" -sf "#1e1d23" -X 10 -Y 7 -W 2150 -p "CAPTURE:")

case $SHOT in
  fullscreen) shotnow ;;
  window) shotwin ;;
  area) shotarea ;;
  *) ;;
esac

