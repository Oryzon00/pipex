SRCS =	srcs/main.c \
		srcs/check_error.c \
		


OBJ = $(SRCS:.c=.o)

CC = clang

DEBUG = -fsanitize=address 

CFLAGS = -Wall -Wextra -Werror -g3 

OPTI = -O3 -flto

NAME = pipex

INC_DIR = includes

PATH_LIBFT = ./libft

%.o: %.c
		$(CC) $(CFLAGS) -I ${INC_DIR} -c $< -o $@

all: $(NAME)

$(NAME):	$(OBJ)
			make -C $(PATH_LIBFT) --silent
			$(CC)  $(CFLAGS) $(OBJ) libft/libft.a -o $(NAME)

clean:
		rm -f $(OBJ)
		make -C $(PATH_LIBFT) fclean --silent

fclean:	clean
		rm -f $(NAME)

re:		fclean $(NAME)

.PHONY:		all clean fclean re 
