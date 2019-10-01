/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: draudrau <draudrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 18:00:42 by waddam            #+#    #+#             */
/*   Updated: 2019/10/01 16:15:42 by draudrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include "./libft/libft.h"
# include "op.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct		s_plr
{
	int				num;
	char			name[PROG_NAME_LENGTH + 1];
	int				code_size;
	char			comment[COMMENT_LENGTH + 1];
	char			code[CHAMP_MAX_SIZE + 1];
	int				flag_n;
}					t_plr;

// carriage - каретка
typedef struct		s_crg
{
	int				num_plr;
	int				pc;
	int				carry;
	int				reg[REG_NUMBER];
	int				cur_op;		// код операции, на которой стоит каретка
	int				bef_op;		// количество циклов, оставшиеся до исполнения операции, на которой стоит каретка
	int				num_live;	// цикл, в котором в последний раз была выполнена операция live
	int				step;		// количество байт, которые нужно будет «перешагнуть», чтобы оказаться на следующей операции
	struct s_crg	*next;
}					t_crg;

typedef struct		s_cw
{
	t_plr			plr[MAX_PLAYERS];
	t_crg			*crg;
	char			map[MEM_SIZE];
	int				plr_nbrs;	// количество игроков
	int				cclt_die;	// текущий cycle to die
	int				round;	// количество прошедших с начала игры циклов
	int				checks;		// количество проверок
	int				dump;

	int 			count_live; // количество выполненных операций live за последний период, длинной в cycles_to_die
	int				last_plr; // игрок, о котором в последний раз сказали, что он жив

}					t_cw;

void				ft_leave(char *msg);
void				ft_initialize(t_cw *cw);
void				ft_parse(int argc, char **argv, t_cw *cw);
void				ft_write_plr(char **argv, int *i, t_cw *cw, int pos);
void				ft_byte_reverse(char *bytes_array);
void				ft_game(t_cw *cw);
void				ft_print_map(t_cw *cw);
void				ft_correct_plrs(t_cw *cw);
void				ft_sort_plrs(t_plr *plr, int size);

// debug
void				ft_print_plrs(t_plr *plr, int size);

// арена
void				ft_print_map(t_cw *cw);
void				ft_add_carriage(t_cw *cw, int k, int pc);
int					ft_search_next_plr(t_cw *cw, int num);
void				ft_add_plr_on_map(t_cw *cw);
void				ft_game(t_cw *cw);

#endif