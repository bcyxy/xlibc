all: test

test: test.o match_range.o
	gcc -o test test.o match_range.o

test.o: test.c match_range.h
	gcc -c -I../common test.c

match_range.o: match_range.c match_range.h
	gcc -c -I../common match_range.c

clean:
	rm -f *.o
	rm -f test
