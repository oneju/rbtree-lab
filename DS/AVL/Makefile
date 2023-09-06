CC = gcc
TARGET = AVL.out
OBJS = main.o avl.o

CFLAGS = -Wall
LDFLAGS = -lc

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^

.c.o :
	$(CC) $(CFLAGS) -c -o $@ $<

clean : 
	rm -f $(OBJS) $(TARGET)