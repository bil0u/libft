#!/bin/bash
#
# Open new Terminal window from the command line
#
# Usage:
#	/bin/bash ./server_launch.sh -f [FIFO] [-o [OPTIONS]]
#		[FIFO]			Fifo to read on
#		[OPTIONS]		Options to pass to the log_server

while getopts f:o: option
do
case "${option}"
in
f) FIFO=${OPTARG};;
o) OPTIONS=${OPTARG};;
esac
done

SCRIPTPATH='\/log\/scripts\/launch_server.sh'
EXEC='\/log_server'
RUN_CMD=$(echo $0 | sed "s/$SCRIPTPATH/$EXEC/")

exec osascript <<END
tell application "iTerm2"
	set currWin to (create window with default profile)
	tell current session of currWin
		write text "$RUN_CMD $FIFO $OPTIONS"
	end tell
end tell
END
