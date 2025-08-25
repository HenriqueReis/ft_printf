NAME = libftprintf.a

CC = cc

FLAGS =-Wall -Werror -Wextra

SRC = ft_printf.c ft_printf_utils.c

OBJ = $(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
		ar -rcs $@ $(OBJ)

%.o:	%.c
	$(CC) $(FLAGS) -c -g $< -o $@

clean:	
	rm -f $(OBJ)

fclean:	
	rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
