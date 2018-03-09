#!/bin/bash
#
# Open new Terminal window from the command line
#
# Usage:
#	/bin/bash ./server_launch.sh -f [FILE] [-o [OPTIONS]]
#		[FILE]			File to read on
#		[OPTIONS]		Options to pass to the log_server

while getopts f:o: option
do
case "${option}"
in
f) FILE=${OPTARG};;
o) OPTIONS=${OPTARG};;
esac
done

SCRIPTPATH='\/log\/scripts\/launch_server.sh'
EXEC='\/log_server'
RUN_CMD=$(echo $0 | sed "s/$SCRIPTPATH/$EXEC/")

echo $RUN_CMD

exec osascript <<END
tell application "iTerm"
	set currWin to (create window with default profile)
	tell current session of currWin
		write text "$RUN_CMD $FILE $OPTIONS"
	end tell
end tell
END
