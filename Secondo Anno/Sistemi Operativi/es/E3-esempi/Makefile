CC = gcc
CFLAGS = -Wall

FORK_SRC = fork.c
FORK_OBJ = fork.o
FORK_BIN = fork
GETPIDS_SRC = getpids.c
GETPIDS_OBJ = getpids.o
GETPIDS_BIN = getpids

% : %.o
	@$(CC) $(CFLAGS) -o $@ $<
%.o : %.c
	@$(CC) $(CFLAGS) -c $<

build:	$(FORK_BIN) $(GETPIDS_BIN)

clean:
	rm -rf 	$(FORK_OBJ) $(FORK_BIN) $(GETPIDS_OBJ) $(GETPIDS_BIN)
