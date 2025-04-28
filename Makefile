##
## EPITECH PROJECT, 2025
## corewar
## File description:
## Makefile
##

SRC	=	src/main.c \
		src/op.c \
		src/flags.c \
		src/vm.c
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
