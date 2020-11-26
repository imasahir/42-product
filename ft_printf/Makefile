NAME = libftprintf.a

INCLUDE = ft_printf.h

LIBFT = libft/libft.a

SRC = ft_printf.c\
		ft_vprintf.c\
		ft_vprintf_util.c\
		apply_ptf.c\
		put_type_cs.c\
		put_type_id.c\
		put_type_p.c\
		put_type_u.c\
		put_type_x.c


CC = gcc

CFLAGS = -Wall -Wextra -Werror

OBJ = $(SRC:.c=.o)

all:$(NAME)

$(NAME):$(OBJ)
		$(MAKE) -C ./libft
		cp $(LIBFT) $(NAME)
		$(CC) -c $(INCLUDE) $(SRC)
		ar -rcs $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY:all clean fclean re
