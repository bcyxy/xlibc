all: test

test: xlibc_list.o test.o
	gcc -o test xlibc_list.o test.o

xlibc_list.o: xlibc_list.h xlibc_list.c
	gcc -c -Wall -I../mempool xlibc_list.c

test.o: xlibc_list.h test.c
	gcc -c -Wall -I../mempool test.c

clean:
	rm -f test *.o
