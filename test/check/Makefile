# Objects that must be created by compiling the corresponding source files
OBJECTS = check.o check_error.o check_list.o check_log.o \
check_msg.o check_pack.o check_print.o check_run.o check_str.o

# Libraries to link with the final executable
CLIBS = -lrt -lm -pthread

# Compile with position independent code and warnings
CFLAGS = -fPIC -O2 -Wall -Wextra -g

# External tools
CC = gcc
AR = ar
SED = sed
CHECKMK = ./checkmk

# Targets that should not be skipped
.PHONY: clean demo

# Create dynamic library, default target
lib.so: $(OBJECTS)
	$(CC) -shared -o $@ $(OBJECTS) $(CFLAGS) $(CLIBS)

# Create static library
lib.a: $(OBJECTS)
	$(AR) rcs $@ $?

# Make all headers prerequisites of all objects
$(OBJECTS): *.h

# Create C sources using checkmk
%.c: %.check
	$(CHECKMK) $^ > $@
	@$(SED) 's/#include <check.h>/#include "check.h"/' $@ > $@.tmp
	@mv $@.tmp $@

# Compile and run demonstration program
demo: demo.o lib.a
	$(CC) -o $@ $^ $(CFLAGS) $(CLIBS)
	./$@

# Clean up
clean:
	rm $(wildcard *.o) 2>/dev/null || true
	rm demo lib.so lib.a 2> /dev/null || true
