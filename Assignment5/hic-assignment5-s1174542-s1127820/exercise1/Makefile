BINARIES = buffer-vuln controlflow

CFLAGS = -fno-omit-frame-pointer -g

.PHONY: all
all: $(BINARIES)

buffer-vuln: CFLAGS += -std=c99 -zexecstack -fno-stack-protector
buffer-vuln: buffer-vuln.c

controlflow: CFLAGS += -fno-stack-protector
controlflow: controlflow.c

.PHONY: distclean
distclean:
	$(RM) $(BINARIES)
