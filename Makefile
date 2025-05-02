##
## EPITECH PROJECT, 2025
## corewar
## File description:
## Makefile
##

SRC	=	src/main.c \
		src/op.c \
		src/champions.c \
		src/flags.c \
		src/vm.c \
		src/instructions/live.c \
		src/instructions/instructions.c \
		src/instructions/add.c \
		src/instructions/aff.c \
		src/instructions/and.c \
		src/instructions/fork.c \
		src/instructions/ld.c \
		src/instructions/ldi.c \
		src/instructions/st.c \
		src/instructions/sti.c \
		src/instructions/zjump.c \
		src/gameloop.c \
		src/instructions/inst_list.c


OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-Wall -Wextra -pedantic
CPPFLAGS	=	-I ./include/
LDFLAGS	=	-L $(dir $(LIBMY))
LDLIBS	=	-lmy

ifeq ($(ENV), dev)
	CFLAGS	+=	-g3
endif

NAME	=	corewar
LIBMY	=	./lib/my/libmy.a

all:	$(LIBMY) $(NAME)

$(LIBMY):
	$(MAKE) -C $(dir $(LIBMY))

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS) $(LDLIBS)

clean:
	$(MAKE) -C $(dir $(LIBMY)) clean
	$(RM) $(OBJ)

fclean:	clean
	$(MAKE) -C $(dir $(LIBMY)) fclean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
