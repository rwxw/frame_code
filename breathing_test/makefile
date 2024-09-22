CC = gcc

CFLAGS = -Wall -g

SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)
EXEC = final

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) -o $@ $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY : clean

clean:
	del $(OBJS)
