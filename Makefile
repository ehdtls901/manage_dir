CC = g++
OBJS = main.o tree_linkedlist.o
TARGET = Test

.SUFFIXES : .c .o

all : $(TARGET)

$(TARGET): $(OBJS)
			$(CC) -o $@ $(OBJS)

clean:
	rm -f $(OBJS) $(TARGET)
