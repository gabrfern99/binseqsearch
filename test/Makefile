SOURCES = $(wildcard *.check)
CFLAGS = -std=c99 -Wall -Wextra -Wshadow -Winline -pedantic -g
# CFLAGS+= -flto -O3 -march=native -mtune=native
CLIBS = -lrt -lm -pthread
CINCLUDES = -I.. -Icheck/

CC = gcc
SED = sed
CHECKMK = check/checkmk

.DEFAULT_GOAL = test

check/lib.a:
	${MAKE} -C check lib.a

../lib.a:
	${MAKE} -C ../ lib.a

${SOURCES}: Makefile

%.o: %.c Makefile
	$(CC) -c -o $*.o $*.c ${CFLAGS} ${CINCLUDES}

test.c: ${SOURCES}
	$(CHECKMK) $^ > $@
	@$(SED) -e 's/#include <check.h>/#include "check.h"/' \
	        -e 's/CK_ENV/CK_MINIMAL/' $@ > $@.tmp
	@mv $@.tmp $@

test: test.o check/lib.a ../lib.a
	$(CC) -o $@ $^ ${CFLAGS} ${CLIBS}
	./$@

clean:
	${MAKE} -C check clean 2>/dev/null || true
	rm $(wildcard *.o) 2>/dev/null || true
	rm $(wildcard *.tmp) 2>/dev/null || true
	rm test test.c 2> /dev/null || true

.PHONY: clean test ../lib.a check/lib.a
