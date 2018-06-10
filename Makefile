CC = gcc
CFLAGS = -Wall -ansi -pedantic -ggdb -Werror -std=gnu11
  
xor:	xor.o Makefile
	$(CC) $(CFLAGS) xor.o -o xor 

xor.o:	xor.c xor.h 
	$(CC) $(CFLAGS) -c xor.c

clean:
	/bin/rm -f xor.o xor *~




