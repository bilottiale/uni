CC = gcc
CFLAGS = -Wall

LSEEK_TXT_SRC = lseek_txt.c
LSEEK_TXT_OBJ = lseek_txt.o
LSEEK_TXT_BIN = lseek_txt
FILE_HOLE_SRC = file_hole.c
FILE_HOLE_OBJ = file_hole.o
FILE_HOLE_BIN = file_hole
LINK_HARD_TXT_SRC = link_hard_txt.c
LINK_HARD_TXT_OBJ = link_hard_txt.o
LINK_HARD_TXT_BIN = link_hard_txt
LINK_SYM_TXT_SRC = link_sym_txt.c
LINK_SYM_TXT_OBJ = link_sym_txt.o
LINK_SYM_TXT_BIN = link_sym_txt
UNLINK_TXT_SRC = unlink_txt.c
UNLINK_TXT_OBJ = unlink_txt.o
UNLINK_TXT_BIN = unlink_txt
OPEN_WRITE_SLEEP_SRC = open_write_sleep.c
OPEN_WRITE_SLEEP_OBJ = open_write_sleep.o
OPEN_WRITE_SLEEP_BIN = open_write_sleep
OPEN_UNLINK_SRC = open_unlink.c
OPEN_UNLINK_OBJ = open_unlink.o
OPEN_UNLINK_BIN = open_unlink

% : %.o
	@$(CC) $(CFLAGS) -o $@ $<
%.o : %.c
	@$(CC) $(CFLAGS) -c $<

build:	$(LSEEK_TXT_BIN) $(FILE_HOLE_BIN) \
		$(LINK_HARD_TXT_BIN) $(LINK_SYM_TXT_BIN) \
		$(UNLINK_TXT_BIN) $(OPEN_WRITE_SLEEP_BIN) \
		$(OPEN_UNLINK_BIN)

clean:
	rm -rf 	$(LSEEK_TXT_OBJ) $(LSEEK_TXT_BIN) \
		$(FILE_HOLE_OBJ) $(FILE_HOLE_BIN) \
		$(LINK_HARD_TXT_OBJ) $(LINK_HARD_TXT_BIN) \
		$(LINK_SYM_TXT_OBJ) $(LINK_SYM_TXT_BIN) \
		$(LINK_SYM_TXT_OBJ) $(LINK_SYM_TXT_BIN) \
		$(UNLINK_TXT_OBJ) $(UNLINK_TXT_BIN) \
		hard-link-a-file-esistente.txt \
		sym-link-a-file-esistente.txt \
		$(OPEN_WRITE_SLEEP_OBJ) $(OPEN_WRITE_SLEEP_BIN) \
		$(OPEN_UNLINK_OBJ) $(OPEN_UNLINK_BIN)
