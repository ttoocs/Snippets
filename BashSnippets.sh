#Turns a piped stream to a single line that updates.
function ONELINE() { while read line; do echo -ne "\t\033[2K\r"; echo -n $line ; done ; echo -ne "\t\033[2K\r" ; }
