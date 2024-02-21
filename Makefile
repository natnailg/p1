CC      = g++
CFLAGS  = -g -Wall -std=c++11
TARGET  = P1
OBJS    = P1.o testScanner.o scanner.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS)

P1.o: P1.cpp
	$(CC) $(CFLAGS) -c P1.cpp

scanner.o: testScanner.cpp testScanner.h
	$(CC) $(CFLAGS) -c scanner.cpp

testScanner.o: Scanner.cpp Scanner.h
	$(CC) $(CFLAGS) -c testScanner.cpp

clean:
	/bin/rm -f *.o $(TARGET)