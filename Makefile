# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile1                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abartole <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/17 20:55:12 by abartole          #+#    #+#              #
#    Updated: 2019/09/17 21:34:53 by abartole         ###   ########.fr        #
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
			init.c terminate.c

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
