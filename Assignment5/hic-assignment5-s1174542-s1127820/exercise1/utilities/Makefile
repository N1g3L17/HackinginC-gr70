PREFIX=/usr/local

BINARIES = getenvaddr getenvaddr-bytes reverseaddr shellcode

CFLAGS = -std=c11 -Wall -Wextra -Wformat=2 -Wpedantic -Werror -pedantic -fstrict-aliasing \
		 -Wpointer-arith -Wcast-align -pipe -O2

.PHONY: all
all: $(BINARIES)

getenvaddr: getenvaddr.c

getenvaddr-bytes: getenvaddr.c functions.o
	$(CC) $(CFLAGS) -o $@ $^ -DPRINT_BYTES

reverseaddr: reverseaddr.c functions.o

functions.o: functions.c functions.h

.PHONY: install
install: $(BINARIES)
	install -m755 --strip $(BINARIES) $(PREFIX)/bin

.PHONY: clean
clean:
	$(RM) *.o

.PHONY: distclean
distclean: clean
	$(RM) $(BINARIES)
