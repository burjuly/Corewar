# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: draudrau <draudrau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/01 20:34:59 by waddam            #+#    #+#              #
#    Updated: 2019/10/05 16:50:44 by draudrau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CW = corewar
SRC_CW = additions_1.c\
		corewar.c\
		debug_cw.c\
		init_map.c\
		parse.c\
		players.c\
		op_add.c \
		op_aff.c \
		op_and.c \
		op_fork.c \
		op_ld.c \
		op_ldi.c \
		op_lfork.c \
		op_live.c \
		op_lld.c \
		op_lldi.c \
		op_or.c \
		op_st.c \
		op_sti.c \
		op_sub.c \
		op_xor.c \
		op_zjmp.c \
		
SRC_CW_PATH = ./
SRC_CW_COMPL = $(addprefix $(SRC_CW_PATH), $(SRC_CW))
OBJ_CW = $(SRC_CW:%.c=%.o)
LIB_PATH = ../libft
INCLUDE = ../

all: $(CW)

# $(CW): $(OBJ_CW)
# 	make -C $(LIB_PATH)
# 	gcc -Wall -Wextra -Werror -g $(OBJ_CW) -o $(CW) -L$(LIB_PATH) -lft

# $(OBJ): %.o: %.c
# 	gcc -Wall -Wextra -Werror -g -c $< -o $@ -I ../

$(CW): $(SRC_CW_COMPL)
	make -C $(LIB_PATH)
	gcc -Wall -Wextra -Werror -g $(SRC_CW_COMPL) -o $(CW) -L$(LIB_PATH) -lft

clean:
	make clean -C $(LIB_PATH)
	/bin/rm -f $(OBJ_CW)

fclean: clean
	make fclean -C $(LIB_PATH)
	/bin/rm -f $(CW)

re: fclean all

.PHONY: all, clean, flcean, re
