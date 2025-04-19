##
## EPITECH PROJECT, 2025
## corewar
## File description:
## Makefile
##

SRC	=	src/main.c
OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-Wall -Wextra -pedantic
CPPFLAGS	=	-I ./include/

ifeq ($(ENV), dev)
	CFLAGS	+=	-g3
endif

NAME	=	corewar

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS) $(LDLIBS)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
