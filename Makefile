CC      = g++
CFLAGS  = -g -Wall -std=c++11
TARGET  = P1
OBJS    = main.o testScanner.o scanner.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS)

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

scanner.o: testScanner.cpp testScanner.h
	$(CC) $(CFLAGS) -c scanner.cpp

testScanner.o: scanner.cpp scanner.h
	$(CC) $(CFLAGS) -c testScanner.cpp

clean:
	/bin/rm -f *.o $(TARGET)