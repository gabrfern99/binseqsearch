CC = gcc
MAKE = make
OBJECTS = ${TARGET}.o list.o readFile.o person.o csv.o linearSearch.o	\
binarySearch.o
CFLAGS = -std=c99 -Wall -Wextra -Wshadow -Winline -pedantic -g
CFLAGS+= -flto -O3 -march=native -mtune=native

TARGET = search

.DEFAULT_GOAL = ${TARGET}

-include $(wildcard *.d)
%.o: %.c Makefile
	$(CC) -c ${CFLAGS} $*.c -o $*.o
	@$(CC) -MM ${CFLAGS} $*.c > $*.d

${TARGET}: ${OBJECTS} Makefile
	${CC} ${OBJECTS} ${CFLAGS} -o ${TARGET}

run: ${TARGET}
	./${TARGET}

test:
	${MAKE} -C test test

disassemble: ${TARGET}
	objdump -Sh ${TARGET}

lib.a: ${OBJECTS}
	ar rcs $@ $?

clean:
	rm $(wildcard *.o) 2>/dev/null || true
	rm $(wildcard *.d) 2>/dev/null || true
	rm ${TARGET} lib.a 2> /dev/null || true
	${MAKE} -C test clean 2>/dev/null || true

.PHONY: clean run disassemble test
