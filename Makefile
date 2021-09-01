CC=gcc
CFLAGS=-Wall -Werror -pedantic
PATHh=./src/headers/
PATHrec=./src/rec/

main: main.o libtp3.a 
	$(CC) $(CFLAGS) -o main main.o -L./src/lib -ltp3

main.o: main.c $(PATHh)function.h
	$(CC) $(CFLAGS) -c main.c 

punto1.o: $(PATHrec)punto1.c $(PATHh)function.h
	$(CC) $(CFLAGS) -c $(PATHrec)punto1.c 

punto2.o: $(PATHrec)punto2.c $(PATHh)function.h
	$(CC) $(CFLAGS) -c $(PATHrec)punto2.c 

libtp3.a: punto1.o punto2.o 
	ar cr ./src/lib/libtp3.a punto1.o punto2.o 

clean:
	rm -f *.o main




