CC=gcc
CFLAGS=-Wall -Werror -pedantic
PATHh=./src/headers/
PATHrec=./src/rec/
PATHout=./src/out/

main: main.o libtp3.a
	$(CC) $(CFLAGS) -o main $(PATHout)main.o -L./src/lib -ltp3

main.o: main.c $(PATHh)function.h
	$(CC) $(CFLAGS) -c main.c
	mv ./main.o $(PATHout)

punto1.o: $(PATHrec)punto1.c $(PATHh)function.h 
	$(CC) $(CFLAGS) -c $(PATHrec)punto1.c
	mv ./punto1.o $(PATHout)

punto2.o: $(PATHrec)punto2.c $(PATHh)function.h
	$(CC) $(CFLAGS) -c $(PATHrec)punto2.c
	mv ./punto2.o $(PATHout)

cJSON.o: $(PATHrec)cJSON.c
	$(CC) $(CFLAGS) -c $(PATHrec)cJSON.c
	mv ./cJSON.o $(PATHout)

libtp3.a: punto1.o punto2.o cJSON.o
	ar cr ./src/lib/libtp3.a $(PATHout)punto1.o $(PATHout)punto2.o $(PATHout)cJSON.o

clean:
	rm -f $(PATHout)*.o main




