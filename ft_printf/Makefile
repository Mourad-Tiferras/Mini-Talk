CC = cc
CFLAG = -Wall -Wextra -Werror
NAME = libftprintf.a
CFILES = ft_printf.c ft_printf_helper1.c unsigned_int.c hexa_lower.c hexa_upper.c hexa_address.c putnbr.c
OBJ = $(CFILES:.c=.o)


all: $(NAME)

%.o: %.c ft_printf.h
	$(CC) $(CFLAG) -c $< -o $@

$(NAME): $(OBJ)
	ar -crs $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:
	rm -f $(NAME) $(OBJ)

re: fclean all