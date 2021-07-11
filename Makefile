TARGET=dotspm
CC=g++
DEBUG=-g
OPT=-O0
WARN=-Wall -Wextra
PTHREAD=-pthread
CCFLAGS=$(DEBUG) $(OPT) $(WARN) $(PTHREAD) -pipe
LD=g++
LDFLAGS=$(PTHREAD) -export-dynamic
OBJS= main.o
all: $(OBJS)
	$(LD) -o $(TARGET) $(OBJS) $(LDFLAGS)
 
main.o: src/main.cc
	$(CC) -c $(CCFLAGS) src/main.cc -o main.o
 
clean:
	rm -rf *.o && rm -rf dotspm
