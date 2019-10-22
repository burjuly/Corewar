# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile1                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdraugr- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/17 20:55:12 by cdraugr-          #+#    #+#              #
#    Updated: 2019/09/17 21:34:53 by cdraugr-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Project executable
NAME := asm

# Paths
SRCDIR := ./srcs/
OBJDIR := ./obj/
INCDIR := ./includes/

# Srcs, objs
SRCNAMES :=	asm.c assemble.c \
			error.c filename_stuff.c \
			to_bytecode.c file.c \
			init.c terminate.c parse.c \
			name_comment.c get_words.c \
			utils.c new_token.c

SRC := $(addprefix $(SRCDIR), $(SRCNAMES))
OBJ := $(addprefix $(OBJDIR), $(SRCNAMES:.c=.o))

# Libft
LIBDIR := ./libft/
LIBINCDIR := $(LIBDIR)/inc/
LIB := $(LIBDIR)/libft.a

# Compilation commands and flags
CC := gcc
CFLAGS := -Wall -Wextra -Werror

.PHONY: all fclean clean

all: $(NAME)

$(NAME): $(OBJDIR) $(LIB) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIB) -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(OBJDIR)%.o: $(SRCDIR)%.c
	$(CC) $(CFLAGS) -I$(INCDIR) -I$(LIBINCDIR) -c $< -o $@

$(LIB):
	make -C $(LIBDIR)

clean:
	rm -rf $(OBJDIR)
	make -C $(LIBDIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBDIR) fclean

re: fclean all
