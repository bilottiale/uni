CC = gcc
CFLAGS = -Wall
LDFLAGS = -lm

CPUBOUND_SRC = cpubound.c
CPUBOUND_OBJ = cpubound.o
CPUBOUND_BIN = cpubound
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

build:	$(CPUBOUND_BIN) $(FORK_BIN) $(GETPIDS_BIN)

clean:
	rm -rf 	$(CPUBOUND_OBJ) $(CPUBOUND_BIN) \
		$(FORK_OBJ) $(FORK_BIN) \
		$(GETPIDS_OBJ) $(GETPIDS_BIN)
