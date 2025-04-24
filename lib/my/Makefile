##
## EPITECH PROJECT, 2024
## libmy
## File description:
## Makefile for libmy
##

SRC	=	free_my_str_array.c \
		mini_printf.c \
		my_array_length.c \
		my_calloc.c \
		my_char_alpha.c \
		my_char_isnum.c \
		my_compute_power_rec.c \
		my_compute_square_root.c \
		my_find_prime_sup.c \
		my_getnbr.c \
		my_intlen.c \
		my_is_in_string.c \
		my_is_prime.c \
		my_memset.c \
		my_putchar.c \
		my_put_nbr.c \
		my_putstr.c \
		my_revstr.c \
		my_show_word_array.c \
		my_sort_int_array.c \
		my_sort_word_array.c \
		my_strcapitalize.c \
		my_strcasecmp.c \
		my_strcat.c \
		my_strchr.c \
		my_strcmp.c \
		my_strcpy.c \
		my_strdup.c \
		my_str_isalpha.c \
		my_str_islower.c \
		my_str_isnum.c \
		my_str_isupper.c \
		my_strlen.c \
		my_strlowcase.c \
		my_strncat.c \
		my_strncmp.c \
		my_strncpy.c \
		my_strndup.c \
		my_strstr.c \
		my_str_to_custom_array.c \
		my_str_to_word_array.c \
		my_strupcase.c \
		my_swap.c

OBJ	=	$(SRC:.c=.o)

BINARY	=	libmy.a
HEADER_FILE	=	my.h

CC	=	gcc
CFLAGS	+= -Wall -Wextra -pedantic
CPPFLAGS	+=	-I ../../include/

ifeq ($(ENV), dev)
	CFLAGS	+=	-g3
endif

all: ../../include/$(HEADER_FILE) $(BINARY)

$(BINARY): $(OBJ)
	ar rc $(BINARY) $(OBJ)

../../include/$(HEADER_FILE):
	mkdir -p ../../include/
	cp $(HEADER_FILE) ../../include/$(HEADER_FILE)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f ../../include/$(HEADER_FILE)
	rm -f $(BINARY)
	rm -f ../$(BINARY)

re: fclean all

.PHONY:	all clean fclean re
