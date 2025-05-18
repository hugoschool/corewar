##
## EPITECH PROJECT, 2024
## llist
## File description:
## Makefile for linked lists
##

SRC	:=	delete.c \
		display.c \
		duplicate.c \
		free_llist.c \
		length.c \
		push.c \
		replace.c \
		search.c

OBJ	:=	$(SRC:.c=.o)

CC	?=	gcc
CFLAGS	+= -Wall -Wextra -pedantic
CPPFLAGS	+=	-I ../../include/

ifeq ($(ENV), dev)
	CFLAGS	+=	-g3
endif

BINARY	:=	libllist.a
HEADER_FILE	:=	llist.h

all: ../../include/$(HEADER_FILE) $(BINARY)

$(BINARY): $(OBJ)
	$(AR) rc $(BINARY) $(OBJ)

../../include/$(HEADER_FILE):
	mkdir -p ../../include/
	cp $(HEADER_FILE) ../../include/$(HEADER_FILE)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) ../../include/$(HEADER_FILE)
	$(RM) $(BINARY)
	$(RM) ../$(BINARY)

re: fclean all

.PHONY:	all clean fclean re
