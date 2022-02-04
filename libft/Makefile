SRCS =	fonctions/ft_isalpha.c \
	fonctions/ft_isdigit.c \
	fonctions/ft_isalnum.c \
	fonctions/ft_isascii.c \
	fonctions/ft_isprint.c \
	fonctions/ft_strlen.c \
	fonctions/ft_memset.c \
	fonctions/ft_bzero.c \
	fonctions/ft_memcpy.c \
	fonctions/ft_memmove.c \
	fonctions/ft_strlcpy.c \
	fonctions/ft_strlcat.c \
	fonctions/ft_toupper.c \
	fonctions/ft_tolower.c \
	fonctions/ft_strchr.c \
	fonctions/ft_strrchr.c \
	fonctions/ft_strncmp.c \
	fonctions/ft_memchr.c \
	fonctions/ft_memcmp.c \
	fonctions/ft_strnstr.c \
	fonctions/ft_atoi.c \
	fonctions/ft_calloc.c \
	fonctions/ft_strdup.c \
	fonctions/ft_substr.c \
	fonctions/ft_strjoin.c \
	fonctions/ft_strtrim.c \
	fonctions/ft_split.c \
	fonctions/ft_strmapi.c \
	fonctions/ft_striteri.c \
	fonctions/ft_itoa.c \
	fonctions/ft_putchar_fd.c \
	fonctions/ft_putstr_fd.c \
	fonctions/ft_putendl_fd.c \
	fonctions/ft_putnbr_fd.c \
	gnl/get_next_line_bonus.c \
	gnl/get_next_line_utils_bonus.c \
	gnl/get_next_line.c \
	gnl/get_next_line_utils.c

OBJS = $(SRCS:.c=.o)

BONUS = fonctions/ft_lstnew.c \
		fonctions/ft_lstadd_front.c \
		fonctions/ft_lstsize.c \
		fonctions/ft_lstlast.c \
		fonctions/ft_lstadd_back.c \
		fonctions/ft_lstdelone.c\
		fonctions/ft_lstclear.c \
		fonctions/ft_lstiter.c \
		fonctions/ft_lstmap.c

BONUS_OBJS = $(BONUS:.c=.o)

CC = gcc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror -I

NAME = libft.a

%.o: %.c
	gcc -Wall -Werror -Wextra -c $< -o $@
all: $(NAME)

$(NAME):	$(OBJS)
			ar rcs $(NAME) $(OBJS)

clean:
			rm -f $(OBJS) $(BONUS_OBJS)

fclean:		clean
			rm -f $(NAME)

re: 		fclean $(NAME)

bonus:		$(OBJS) $(BONUS_OBJS)
			ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)

.PHONY:		all clean fclean re bonus
