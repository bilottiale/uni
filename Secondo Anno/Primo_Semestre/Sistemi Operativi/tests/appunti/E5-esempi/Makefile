CC = gcc
CFLAGS = -Wall

SBRK_SRC = sbrk.c
SBRK_OBJ = sbrk.o
SBRK_BIN = sbrk
BRK_SRC = brk.c
BRK_OBJ = brk.o
BRK_BIN = brk
MMAP_ANON_SRC = mmap_anon.c
MMAP_ANON_OBJ = mmap_anon.o
MMAP_ANON_BIN = mmap_anon
MALLOC_SMALL_SRC = malloc_small.c
MALLOC_SMALL_OBJ = malloc_small.o
MALLOC_SMALL_BIN = malloc_small
MALLOC_AVERAGE_SRC = malloc_average.c
MALLOC_AVERAGE_OBJ = malloc_average.o
MALLOC_AVERAGE_BIN = malloc_average
MALLOC_BIG_SRC = malloc_big.c
MALLOC_BIG_OBJ = malloc_big.o
MALLOC_BIG_BIN = malloc_big

% : %.o
	@$(CC) $(CFLAGS) -o $@ $<
%.o : %.c
	@$(CC) $(CFLAGS) -c $<

build:	$(SBRK_BIN) $(BRK_BIN) $(MMAP_ANON_BIN) $(MALLOC_SMALL_BIN) \
		$(MALLOC_AVERAGE_BIN) $(MALLOC_BIG_BIN)

clean:
	rm -rf 	$(SBRK_OBJ) $(SBRK_BIN) $(BRK_OBJ) $(BRK_BIN) \
		$(MMAP_ANON_OBJ) $(MMAP_ANON_BIN) \
		$(MALLOC_SMALL_OBJ) $(MALLOC_SMALL_BIN) \
		$(MALLOC_AVERAGE_OBJ) $(MALLOC_AVERAGE_BIN) \
		$(MALLOC_BIG_OBJ) $(MALLOC_BIG_BIN)
