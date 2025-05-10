##
## EPITECH PROJECT, 2025
## corewar
## File description:
## Makefile
##

# Uncomment this when needed to import the current corewar files to import
# into the bonus
# INITSRC_DIR	=	../src
# INITSRC	=	$(INITSRC_DIR)/op.c
# INITOBJ	=	$(INITSRC:.c=.o)

SRC	=	src/main.c
OBJ	=	$(SRC:.c=.o)

CC	?=	gcc
CFLAGS	=	-Wall -Wextra
CPPFLAGS	=	-I ./include/ -I ./$(RAYLIB)/include
LDFLAGS	=	-L ./$(RAYLIB)/lib
LDLIBS	=	-l:libraylib.a -lm

RAYLIB	=	raylib-5.5_linux_amd64
RAYLIB_TAR	=	$(RAYLIB).tar.gz
RAYLIB_LINK	=	https://github.com/raysan5/raylib/releases/download/5.5/$(RAYLIB_TAR)

BINARY	=	corewar

all:	$(RAYLIB) $(BINARY)

$(BINARY):	$(OBJ)
	$(CC) -o $(BINARY) $(OBJ) $(LDFLAGS) $(LDLIBS)

$(RAYLIB):
	curl -Lo $(RAYLIB_TAR) $(RAYLIB_LINK)
	tar -xvf $(RAYLIB_TAR)
	$(RM) $(RAYLIB_TAR)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(BINARY)

re:	fclean all

.PHONY:	all clean fclean re
