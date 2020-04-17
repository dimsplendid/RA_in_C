CC=gcc
CFLAGS=-std=c11 -g -static

test: test.sh src/test.c
	$(CC) src/test.c -o test_RA_in_C
	./test.sh

clean:
	rm -f test_RA_in_C *.o *~ tmp*

.PHONY: test clean