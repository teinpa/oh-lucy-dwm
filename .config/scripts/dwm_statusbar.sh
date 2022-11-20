interval=0

# functions

spotify() {
    if ps -C ncspot > /dev/null; then
        PLAYER="ncspot"
    fi
    
    if [ "$PLAYER" = "ncspot" ]; then
        ARTIST=$(playerctl metadata xesam:albumArtist)
        # TRACK=$(playerctl metadata title | sed 's/(.*//')
        TRACK=$(playerctl metadata title)
        STATUS=$(playerctl status)
        SEP1=" | "
        if [ "$STATUS" = "Playing" ]; then
            # STATUS="PLA"
            printf "^C5^ $ARTIST ^C7^$TRACK "
        # else
            # STATUS="PAU"
            # printf "^b$red^^c$black^ PAU ^b$black^^c$red^ $ARTIST - $TRACK "
            # printf null
        fi
    fi
}

pkg_updates() {
	updates=$(checkupdates | wc -l)   # arch , needs pacman contrib
	printf "^C3^ PKG ^C7^$updates"
}

get_volume(){
  curStatus=$(pamixer --get-mute)
  volume=$(pamixer --get-volume-human)

        if [ "${curStatus}" = 'true' ]
        then
            printf "^C1^ VOL MUTED^d^"
        else
            printf "^C2^ VOL ^C7^$volume%"
        fi
}

mem() {
  memory=$(free -h | awk '/^Mem/ { print $3 }')
  printf "^c$tk_c^ MEM ^c$tk_w0^$memory"
}

cpu() {
  # Get the first line with aggregate of all CPUs
  cpu_last=($(head -n1 /proc/stat))
  cpu_last_sum="${cpu_last[@]:1}"
  cpu_last_sum=$((${cpu_last_sum// /+}))

  sleep 0.05

  cpu_now=($(head -n1 /proc/stat))
  cpu_sum="${cpu_now[@]:1}"
  cpu_sum=$((${cpu_sum// /+}))

  cpu_delta=$((cpu_sum - cpu_last_sum))
  cpu_idle=$((cpu_now[4]- cpu_last[4]))
  cpu_used=$((cpu_delta - cpu_idle))
  cpu_usage=$((100 * cpu_used / cpu_delta))

  # Keep this as last for our next read
  cpu_last=("${cpu_now[@]}")
  cpu_last_sum=$cpu_sum

  printf "^c$d_red^ CPU ^c$d_white^$cpu_usage^c$d_black^"
}

weather() {
  temp=$(curl -s wttr.in/Seoul?format=%t)
  cond=$(curl -s wttr.in/Seoul?format=%C | awk '{ print toupper($0) }')
  printf "^C5^ $cond"
  printf "^C7^ $temp"
}

clock() {
  printf "^C4^ $(date '+%^a')"
  printf "^C7^ $(date '+%I:%M%p')"
}

day() {
  printf "^C1^ $(date '+%^b')"
  printf "^C7^ $(date '+%d')"
}

while true; do

	[ $interval = 0 ] || [ $(($interval % 3600)) = 0 ] && updates=$(pkg_updates && weather)
	interval=$((interval + 1))

    sleep 1 && xsetroot -name "$(spotify)$(pkg_updates) $(get_volume) $(day) $(clock)"
done

