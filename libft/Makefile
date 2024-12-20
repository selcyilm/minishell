NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -O3

OBJDIR = objs

AR = ar rcs

INC = libft.h

SRCS = ft_strlen.c ft_isdigit.c ft_isalpha.c ft_isalnum.c ft_isascii.c \
	ft_isprint.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
	ft_memchr.c ft_memcmp.c ft_toupper.c ft_tolower.c ft_strchr.c \
	ft_strrchr.c ft_strncmp.c ft_strlcpy.c ft_strlcat.c ft_strnstr.c \
	ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
	ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_putchar_fd.c \
	ft_striteri.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
	ft_strcmp.c ft_atof.c ft_atoc.c ft_isspace.c ft_islower.c ft_isupper.c \
	ft_strtod.c ft_strtol.c ft_strjoin_with.c

OBJS = $(SRCS:%.c=$(OBJDIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)

$(OBJDIR)/%.o: %.c $(INC) | $(OBJDIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$< \033[32mcompiled.\033[0m"

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	rm -fr $(OBJDIR)

fclean: clean
	rm -f $(NAME) libft.so

re : fclean all

.PHONY: all clean fclean re
