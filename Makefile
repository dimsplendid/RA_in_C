CC=gcc
CFLAGS=-std=c11 -g -static
SRCS=$(wildcard src/*.c)
# NODIR=$(notdir $(SRCS))
OBJS=$(SRCS:.c=.o)

all: RA_in_C

test: test.sh src/test.c
	$(CC) $(CFLAGS) src/test.c -o test_RA_in_C
	./test.sh

RA_in_C: $(OBJS) 
	$(CC) $(CFLAGS) $(LDFLAGS) -o RA_in_C $(OBJS)

$(OBJS): src/ra_in_c.h

clean:
	rm -f test_RA_in_C *.o *~ tmp*

.PHONY: test clean