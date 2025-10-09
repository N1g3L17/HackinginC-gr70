BINARIES = buffer-vuln controlflow controlflowmanipulate controlflowcrash

CFLAGS = -fno-omit-frame-pointer -g

.PHONY: all
all: $(BINARIES)

buffer-vuln: CFLAGS += -std=c99 -zexecstack -fno-stack-protector
buffer-vuln: buffer-vuln.c

controlflow: CFLAGS += -fno-stack-protector
controlflow: controlflow.c

controlflowmanipulate: CFLAGS += -fno-stack-protector
controlflowmanipulate: controlflowmanipulate.c

controlflowcrash: CFLAGS += -fno-stack-protector
controlflowcrash: controlflowcrash.c

.PHONY: distclean
distclean:
	$(RM) $(BINARIES)
