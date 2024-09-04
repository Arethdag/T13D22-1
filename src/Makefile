CC= gcc
FLAGS= -Wall -Werror -Wextra

all: cipher clean

cipher: cipher.o
	$(CC) $(FLAGS) cipher.o -o ../build/cipher

cipher.o: cipher.c
	$(CC) $(FLAGS) -c cipher.c

clean: 
	rm -rf *.o