CC = gcc
CFLAGS = -Wall

SBRK_WRITE_SRC = sbrk_write.c
SBRK_WRITE_OBJ = sbrk_write.o
SBRK_WRITE_BIN = sbrk_write
SBRK_WRITE_OFFAREA_SRC = sbrk_write_offarea.c
SBRK_WRITE_OFFAREA_OBJ = sbrk_write_offarea.o
SBRK_WRITE_OFFAREA_BIN = sbrk_write_offarea
SBRK_USE_AFTER_FREE_SRC = sbrk_use_after_free.c
SBRK_USE_AFTER_FREE_OBJ = sbrk_use_after_free.o
SBRK_USE_AFTER_FREE_BIN = sbrk_use_after_free
SBRK_WRITE_USE_AFTER_FREE_SRC = sbrk_write_use_after_free.c
SBRK_WRITE_USE_AFTER_FREE_OBJ = sbrk_write_use_after_free.o
SBRK_WRITE_USE_AFTER_FREE_BIN = sbrk_write_use_after_free
MMAP_ANON_OFFAREA_SRC = mmap_anon_offarea.c
MMAP_ANON_OFFAREA_OBJ = mmap_anon_offarea.o
MMAP_ANON_OFFAREA_BIN = mmap_anon_offarea
MMAP_ANON_USE_AFTER_FREE_SRC = mmap_anon_use_after_free.c
MMAP_ANON_USE_AFTER_FREE_OBJ = mmap_anon_use_after_free.o
MMAP_ANON_USE_AFTER_FREE_BIN = mmap_anon_use_after_free
MMAP_ANON_WRITE_USE_AFTER_FREE_SRC = mmap_anon_write_use_after_free.c
MMAP_ANON_WRITE_USE_AFTER_FREE_OBJ = mmap_anon_write_use_after_free.o
MMAP_ANON_WRITE_USE_AFTER_FREE_BIN = mmap_anon_write_use_after_free
MALLOC_USE_AFTER_FREE_SRC = malloc_use_after_free.c
MALLOC_USE_AFTER_FREE_OBJ = malloc_use_after_free.o
MALLOC_USE_AFTER_FREE_BIN = malloc_use_after_free

% : %.o
	@$(CC) $(CFLAGS) -o $@ $<
%.o : %.c
	@$(CC) $(CFLAGS) -c $<

build:	$(SBRK_WRITE_BIN) $(SBRK_WRITE_OFFAREA_BIN) $(SBRK_USE_AFTER_FREE_BIN) \
	$(SBRK_WRITE_USE_AFTER_FREE_BIN) $(MMAP_ANON_OFFAREA_BIN) \
	$(MMAP_ANON_USE_AFTER_FREE_BIN) $(MMAP_ANON_WRITE_USE_AFTER_FREE_BIN) \
	$(MALLOC_USE_AFTER_FREE_BIN)

clean:
	rm -rf 	$(SBRK_WRITE_OBJ) $(SBRK_WRITE_BIN) \
		$(SBRK_WRITE_OFFAREA_OBJ) $(SBRK_WRITE_OFFAREA_BIN) \
		$(SBRK_USE_AFTER_FREE_OBJ) $(SBRK_USE_AFTER_FREE_BIN) \
		$(SBRK_WRITE_USE_AFTER_FREE_OBJ) $(SBRK_WRITE_USE_AFTER_FREE_BIN) \
		$(MMAP_ANON_OFFAREA_OBJ) $(MMAP_ANON_OFFAREA_BIN) \
		$(MMAP_ANON_USE_AFTER_FREE_OBJ) $(MMAP_ANON_USE_AFTER_FREE_BIN) \
		$(MMAP_ANON_WRITE_USE_AFTER_FREE_OBJ) $(MMAP_ANON_WRITE_USE_AFTER_FREE_BIN) \
		$(MALLOC_USE_AFTER_FREE_OBJ) $(MALLOC_USE_AFTER_FREE_BIN)
		
