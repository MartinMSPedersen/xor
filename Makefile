CC = gcc
CFLAGS = -Wall -ansi -pedantic -ggdb -Werror -std=gnu11
  
xor:	xor.c Makefile
	$(CC) $(CFLAGS) xor.c -o xor 

clean:
	/bin/rm -f xor *~
