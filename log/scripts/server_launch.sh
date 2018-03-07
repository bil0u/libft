#!/bin/bash
#
# Open new Terminal window from the command line
#
# Usage:
#     /bin/bash ./server_launch.sh [FIFO] [FLAGS]
#     [FIFO]            Open PATH in a new tab
#     [FLAGS]             Open a new tab and execute CMD

while getopts f:o: option
do
case "${option}"
in
f) FIFO=${OPTARG};;
o) OPTIONS=${OPTARG};;
esac
done

EXEC='./log_server'
SCRIPTPATH='\/log\/scripts'
SERVPATH=$(echo $PWD | sed "s/$SCRIPTPATH//")
CD_CMD="cd $SERVPATH"
RUN_CMD="$EXEC $FIFO $OPTIONS"

exec osascript <<END
tell application "iTerm"
	set currWin to (create window with default profile)
	tell current session of currWin
		write text "cd $SERVPATH"
		write text "clear"
		write text "$RUN_CMD"
	end tell
end tell
END
