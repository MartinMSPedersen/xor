CC = gcc
CFLAGS = -Wall -ansi -pedantic -ggdb -Werror -std=gnu11
  
xor:	xor.c Makefile
	$(CC) $(CFLAGS) xor.c -o xor 
	
xor-static:	xor.c Makefile
	$(CC) $(CFLAGS) -static xor.c -o xor-static


clean:
	/bin/rm -f xor xor-static *~
