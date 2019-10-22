# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdraugr- <cdraugr-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/25 15:55:10 by cdraugr-          #+#    #+#              #
#    Updated: 2019/10/22 16:50:59 by cdraugr-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libft.a

CC := gcc

INC := ./inc/

SRC := ft_atoi.c \
	ft_bzero.c \
	ft_chrcnt.c \
	ft_copy_arr.c \
	ft_count_words.c \
	ft_int_size.c \
	ft_is_blank.c \
	ft_is_db.c \
	ft_isalnum.c \
	ft_isalpha.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_islower.c \
	ft_isprint.c \
	ft_isupper.c \
	ft_itoa.c \
	ft_lstadd.c \
	ft_lstdel.c \
	ft_lstdelone.c \
	ft_lstfold.c \
	ft_lstfree.c \
	ft_lstiter.c \
	ft_lstlen.c \
	ft_lstmap.c \
	ft_lstnew.c \
	ft_lstsplit.c \
	ft_memalloc.c \
	ft_memccpy.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_memcpy.c \
	ft_memdel.c \
	ft_memmove.c \
	ft_memset.c \
	ft_putchar.c \
	ft_putchar_fd.c \
	ft_putendl.c \
	ft_putendl_fd.c \
	ft_putnbr.c \
	ft_putnbr_fd.c \
	ft_putstr.c \
	ft_putstr_fd.c \
	ft_strarrdel.c \
	ft_strcat.c \
	ft_strchr.c \
	ft_strclr.c \
	ft_strcmp.c \
	ft_strcount.c \
	ft_strcpy.c \
	ft_strdel.c \
	ft_strdup.c \
	ft_strequ.c \
	ft_striter.c \
	ft_striteri.c \
	ft_strjoin.c \
	ft_strlcat.c \
	ft_strlen.c \
	ft_strmap.c \
	ft_strmapi.c \
	ft_strncat.c \
	ft_strncmp.c \
	ft_strncpy.c \
	ft_strnequ.c \
	ft_strnew.c \
	ft_strnstr.c \
	ft_strrchr.c \
	ft_strrev.c \
	ft_strsplit.c \
	ft_strsplit_n.c \
	ft_strstr.c \
	ft_strsub.c \
	ft_strtrim.c \
	ft_swap.c \
	ft_swap_str.c \
	ft_tolower.c \
	ft_toupper.c \
	get_next_line.c

OBJ := $(SRC:.c=.o)

FLAGS := -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ) $(HDR)
	@ar rc $@ $(OBJ)
	@ranlib $@

%.o : %.c
	$(CC) $(FLAGS) -I$(INC) -c $?

clean:
	@/bin/rm -f $(OBJ)


fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
