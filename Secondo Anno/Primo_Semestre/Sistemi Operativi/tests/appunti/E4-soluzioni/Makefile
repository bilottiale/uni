CC = gcc
CFLAGS = -Wall

LSEEK_TXT_SRC = lseek_txt.c
LSEEK_TXT_OBJ = lseek_txt.o
LSEEK_TXT_BIN = lseek_txt

% : %.o
	@$(CC) $(CFLAGS) -o $@ $<
%.o : %.c
	@$(CC) $(CFLAGS) -c $<

build:	$(LSEEK_TXT_BIN)

clean:
	rm -rf 	$(LSEEK_TXT_OBJ) $(LSEEK_TXT_BIN)
