##
## EPITECH PROJECT, 2025
## corewar
## File description:
## Makefile
##

INITSRC_DIR	=	../src
INITSRC	=	$(INITSRC_DIR)/op.c \
			$(INITSRC_DIR)/champions.c \
			$(INITSRC_DIR)/flags.c \
			$(INITSRC_DIR)/instructions/live.c \
			$(INITSRC_DIR)/instructions/instructions.c \
			$(INITSRC_DIR)/instructions/add.c \
			$(INITSRC_DIR)/instructions/aff.c \
			$(INITSRC_DIR)/instructions/and.c \
			$(INITSRC_DIR)/instructions/fork.c \
			$(INITSRC_DIR)/instructions/ld.c \
			$(INITSRC_DIR)/instructions/ldi.c \
			$(INITSRC_DIR)/instructions/st.c \
			$(INITSRC_DIR)/instructions/sti.c \
			$(INITSRC_DIR)/instructions/zjump.c \
			$(INITSRC_DIR)/instructions/inst_list.c \
			$(INITSRC_DIR)/print_map.c \
			$(INITSRC_DIR)/utils.c

SRC	=	$(INITSRC) \
		src/main.c \
		src/gameloop.c \
		src/display.c \
		src/vm_ray.c \
		src/colors.c \
		src/inst_ray.c \
		src/sti_ray.c \
		src/st_ray.c

OBJ	=	$(SRC:.c=.o)

LIBMY	:=	../lib/my/libmy.a
LIBLLIST	:=	../lib/llist/libllist.a

CC	?=	gcc
CFLAGS	=	-Wall -Wextra
CPPFLAGS	=	-I ./include/ -I ./$(RAYLIB)/include -I ../include/
LDFLAGS	=	-L ./$(RAYLIB)/lib -L $(dir $(LIBMY)) -L $(dir $(LIBLLIST))
LDLIBS	=	-l:libraylib.a -lm -lmy -lllist

ifeq ($(ENV), dev)
	CFLAGS	+=	-g3
endif

RAYLIB	=	raylib-5.5_linux_amd64
RAYLIB_TAR	=	$(RAYLIB).tar.gz
RAYLIB_LINK	=	https://github.com/raysan5/raylib/releases/download/5.5/$(RAYLIB_TAR)

BINARY	=	corewar

all:	$(RAYLIB) $(LIBMY) $(LIBLLIST) $(BINARY)

$(LIBMY):
	$(MAKE) -C $(dir $(LIBMY))

$(LIBLLIST):
	$(MAKE) -C $(dir $(LIBLLIST))

$(BINARY):	$(INITOBJ) $(OBJ)
	$(CC) -o $(BINARY) $(INITOBJ) $(OBJ) $(LDFLAGS) $(LDLIBS)

$(RAYLIB):
	curl -Lo $(RAYLIB_TAR) $(RAYLIB_LINK)
	tar -xvf $(RAYLIB_TAR)
	$(RM) $(RAYLIB_TAR)

clean:
	$(MAKE) -C $(dir $(LIBLLIST)) clean
	$(RM) $(OBJ)

fclean:	clean
	$(MAKE) -C $(dir $(LIBLLIST)) fclean
	$(RM) $(BINARY)

re:	fclean all

.PHONY:	all clean fclean re
