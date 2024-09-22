CC = gcc

SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)
EXEC = final

$(EXEC): $(OBJS)
	$(CC) -o $@ $(OBJS)

%.o: %.c
	$(CC) -c $< -o $@

clean:
	del $(OBJS)

