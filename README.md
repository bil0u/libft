# Libft

This is my personal toolkit for C programming based on the Standard C Library.  

Note: this code has only been tested on macOS and ArchLinux  

## Usage

First, clone
```sh
$ git clone https://github.com/bil0u/libft.git
```

You have to specify the include path `-I <libft_path>` and the library flags `-lft -Llibft`  

Don't forget to `#include "libft.h"` or `"libft_macros.h"`
(Note that `libft.h` already includes `libft_macros.h`)  

A Makefile is provided, just run in your shell
```sh
$ make
```
or call it from a parent one with the rule `make -C <libft_path>`

## Components

### Memory
Memory allocation and management  
See [memory.h](memory/includes/memory.h) for details  

### Characters
Characters testing and converting functions  
See [characters.h](characters/includes/characters.h) for details  

### Strings
Strings allocation, management and utilities functions  
See [strings.h](strings/includes/strings.h) for details  

### Wide Strings
Wide strings allocation, management, testing and searching functions  
See [wide_strings.h](wide_strings/includes/wide_strings.h) for details  

### Read/Write
Reading and printing fuctions  
See [read_write.h](read_write/includes/read_write.h) for details  

### Printf
Personal implementation of printf() and its variants  
Handling additionnal flags like `%b` for binary and `{colors}`  
See [ft_printf.h](ft_printf/includes/ft_printf.h) for details  

### Maths
Common math functions  
See [maths.h](maths/includes/maths.h) for details  

### Linked Lists
Linked lists creation, management and searching functions  
See [linked_lists.h](linked_lists/includes/linked_lists.h) for details  

### Log
Logging functions that allows to open new shell windows, run a logging program that listen on a fifo and prints all readed input  
Printed output can be saved in log files  
See [log.h](log/includes/log.h) for details

---
`IMPORTANT NOTE`  

Log functions only works on macOS 10.11+ if app `iTerm` (Free) is installed.
This is because of the script used to create new windows and launch the logging binary.

You can manually launch a log session in a newly opened terminal window by typing the following
```sh
$ <main_directory>/libft/log_server /tmp/libft_log.<window_name> [-scl]
```
* `<main_directory>`  
   This is the path where you cloned this project  
* `<window_name>`  

   | Name to type | Debug level |
   | ------------ | ----------- |
   | `inf`        | 1           |
   | `mem`        | 2           |
   | `ins`        | 4           |
   | `arg`        | 8           |
   | `job`        | 16          |
   | `reg`        | 32          |
* `-s`  
   Save all printed output in a log file, in the `<main_directory>/libft/log_files` directory  
* `-c`  
   Close the terminal window when the log_server stops  
* `-l`  
   Keep the log_server running even if the parent program is terminated  
   This allow you to use the same debug windows for your game sessions, and not to have to resize them each time you launch the game  

To close a window properly, you must quit the log_server by pressing `Ctrl + C` first.  
If you kill the program by any other way, the log server will not suppress the used fifo, and you will encouter problems for launching a new session. (Your programm will stuck do nothing)  

If this happens, you can reset the logging fifos by typing  
```
$ rm -f /tmp/libft_log.*
```
---

## Makefile rules

* all  
   Compile all the library components  
* libft  
   Compile only the library  
* log_server  
   Compile only the logging server binary  
* log_client  
   Compile only the logging client binary  
* clean  
   Delete all the objects files  
* fclean  
   Delete both objects and binaries  
* re  
   Runs the `fclean` and `all` rules  
* norm  
   Runs the `norminette` command on all the sources and includes subdirectories (Only usable in 42 clusters)  

## License

This project is licensed under the GNU General Public License v3.0 - see the [LICENSE.txt](LICENSE.txt) file for details
