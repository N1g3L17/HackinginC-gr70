# Utilities for hacking

## Prerequisites

Make sure `xxd` and `python` are installed on this system, the shell functions
rely on them.

## Functionality provided

### Shell functions:

`shell-rc` contains a few shell functions performing basic functionality. These
are usable anywhere where your input is first being processed by the shell.
However, that excludes the interface of `gdb` and whenever you are directly
typing into a program.

* `spamf` outputs its first argument a specified number of times.
* `revaddr` turns its ASCII hexadecimal argument (or `stdin`) into bytes
  *and* reverses the order of those bytes.
  * `revaddr` differs from `reverseaddr.c` (see below) in that it also outputs
    any *leading* NULL-bytes you give it.
* `rexxd` turns its ASCII hexadecimal argument (or `stdin`) back into bytes
  *and* hexdumps them in standard hexdump format, for ease of reading.
* `revbytes` simply reverses the order of bytes on `stdin`.

### Shell scripts:

`attack.sh` and `exploit-loop.sh` give some ideas on how to use shell
scripting to make your life easier. `exploit-loop.sh` in particular may be
useful in assignment 5.

Using shell functions in shell scripts requires explicitly "sourcing" the file
containing their definitions, because `.bashrc` and `.zshrc` are not used by
shell scripts.

### C programs:

Some C programs:

* `shellcode.c` compiles to `shellcode`, a program that outputs a working
  shellcode of 35 bytes (see lecture & assignment 5).
* `reverseaddr.c` compiles to `reverseaddr`. This command reverses an address
  supplied as first argument, like the `revaddr` shell function.
  * `reverseaddr` is a lot less forgiving about its input than the `revaddr`
    shell function. In particular, it *requires* the `0x` prefix and it will
    *not* output any leading NULL-bytes.
  * You should only use this where shell functions like `revaddr` are not
    available but you *can* execute programs.
* `getenvaddr.c` compiles into two executables, neither of which is really
  required for the rest of the course but may come in handy if using an
  environment variable to input data into the program:
  * `getenvaddr` gets the address of an environment variable in the context of
    an executable and shows it on `stderr`.
  * `getenvaddr-bytes` does the same, but also prints the address *as bytes* in
    little-endian order on `stdout`, so can be piped to input without needing
    to pass through `reverseaddr`.

## Compiling

Only required for the C programs:

```
make
```

## Installing

### Shell functions

The shell functions from `shell-rc` must either be copied manually into
``~/.zshrc`` or ``~/.bashrc`` (or the rc-file for whatever shell you're using),
or be "sourced" from that file. Note they will only be available on *new* shells
after this inclusion.

One way of doing the copy is *appending* as follows
(NOTE THE DOUBLE `>>`; with a single `>` you will overwrite rather than append):
```bash
cat shell-rc >> ~/.bashrc
cat shell-rc >> ~/.zshrc
```

To make ``~/.bashrc`` or ``~/.zshrc`` source the file, execute (from the
directory where ``shell-rc`` is stored):
```bash
echo . \"$(pwd)/shell-rc\" >> ~/.bashrc
echo . \"$(pwd)/shell-rc\" >> ~/.zshrc
```
This will automatically expand the working directory and so hardcode the path
to the `shell-rc` file. Note the escaped quotes `\"`; the backslashes are not
optional.

Of course, manually editing these files in a text editor is another option.


### C programs and shell scripts

For the C programs and shell scripts, installing is not strictly required. You
can always just use an absolute or relative path to the binary or script.

By default ``make install`` will install the programs to ``/usr/local``, but you
may choose to install to somewhere else by setting ``PREFIX``:

```sh
# will need root
make install

# alternatively, for example in /home/user/.local/bin (no root needed, but may
# not be in $PATH)
make install PREFIX=/home/user/.local
```
