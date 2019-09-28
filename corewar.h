/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waddam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 18:00:42 by waddam            #+#    #+#             */
/*   Updated: 2019/09/29 00:22:53 by waddam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include "./libft/libft.h"
# include "op.h"
# include <stdio.h>

typedef struct		s_plr
{
	int				num;
	char			name[PROG_NAME_LENGTH + 1];
	size_t			code_size;
	char			comment[COMMENT_LENGTH + 1];
	char			code[CHAMP_MAX_SIZE];
}					t_plr;

// carriage - каретка
typedef struct		s_crg
{
	short			pc;
	short			carry;
	// short			plr;		// номер игрока, который породил каретку ???
	short			reg[REG_NUMBER];
	short			cur_op;		// код операции, на которой стоит каретка
	short			bef_op;		// количество циклов, оставшиеся до исполнения операции, на которой стоит каретка
	int				num_live;	// цикл, в котором в последний раз была выполнена операция live
	short			step;		// количество байт, которые нужно будет «перешагнуть», чтобы оказаться на следующей операции
}					t_crg;

typedef struct		s_cw
{
	t_plr			plr[MAX_PLAYERS];
	t_crg			crg;
	int				map[MEM_SIZE];
	short			plr_nbrs;	// количество игроков
	short			cclt_die;	// текущий cycle to die
	int				cur_ccl;	// ноимер текущего цикла
	short			checks;		// количество проверок
	short			flag_n;
	short			flag_dump;
}					t_cw;

void		ft_leave(char *msg);
void		ft_initialize(t_cw *cw);
void		ft_parse(int argc, char **argv, t_cw *cw);

#endif