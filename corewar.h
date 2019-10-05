/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waddam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 18:00:42 by waddam            #+#    #+#             */
/*   Updated: 2019/10/05 15:32:49 by waddam           ###   ########.fr       */
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
	int				num;						// номер игрока
	char			name[PROG_NAME_LENGTH + 1];	// имя
	int				code_size;					// размер его исполняемого кода
	char			comment[COMMENT_LENGTH + 1];	// комментарий
	char			code[CHAMP_MAX_SIZE + 1];	// сам код
	int				flag_n;						// наличие поданного с игроком флага -n
}					t_plr;

// carriage - каретка
typedef struct		s_crg
{
	int				pc;			// положение на карте (координата, индекс)
	int				carry;		// флаг carry
	int				reg[REG_NUMBER];	// регистры
	int				cur_op;		// код операции, на которой стоит каретка
	int				bef_op;		// количество циклов, оставшиеся до исполнения операции, на которой стоит каретка
	int				last_live;	// цикл, в котором в последний раз была выполнена операция live
	int				step;		// количество байт, которые нужно будет «перешагнуть», чтобы оказаться на следующей операции
	struct s_crg	*next;
}					t_crg;

typedef struct		s_cw
{
	t_plr			plr[MAX_PLAYERS];	// массив структур типа "игрок"
	t_crg			*crg;				// указатель на список кареток
	t_op			op[16];				// масиив операций
	char			map[MEM_SIZE];		// карта
	int				plr_nbrs;	// количество игроков
	int				c_to_die;	// текущий cycle to die
	int				round;		// количество прошедших с начала игры циклов
	int				ctd_round;	// количество прошедших с последней проверки циклов
	int				checks;		// количество проверок
	int				dump;		// флаг dump (его наличие)
	int				count_live;	// количество выполненных операций live за последний период, длинной в cycles_to_die
	int				last_plr;	// игрок, о котором в последний раз сказали, что он жив
}					t_cw;

typedef struct 		s_op
{
	char			arg[28]; // /0
	// char			*name;			// название операции
	char			arg_nbrs;		// количество аргументов
	char			args[3];		// массив аргументов
	// char			num;			// номер операции
	int				ccl_cost;		// "стоимость" в циклах
	// char			*comment;		// комментарий
	char			need_arg_code;	// нужен ли код типов аргументов
	char			low_tdir;		// использует T_DIR = 2
}					t_op;

void				ft_leave(char *msg);
void				ft_initialize(t_cw *cw);
void				ft_init_live(t_op *op);
void				ft_init_ld(t_op *op);
void				ft_init_st(t_op *op);
void				ft_init_add(t_op *op);
void				ft_init_sub(t_op *op);
void				ft_init_and(t_op *op);
void				ft_init_or(t_op *op);
void				ft_init_xor(t_op *op);
void				ft_init_zjmp(t_op *op);
void				ft_init_ldi(t_op *op);
void				ft_init_sti(t_op *op);
void				ft_init_fork(t_op *op);
void				ft_init_lld(t_op *op);
void				ft_init_lldi(t_op *op);
void				ft_init_lfork(t_op *op);
void				ft_init_aff(t_op *op);
void				ft_parse(int argc, char **argv, t_cw *cw);
void				ft_write_plr(char **argv, int *i, t_cw *cw, int pos);
int					ft_byte_reverse(char *bytes_array, int count);
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
void				ft_map(t_cw *cw);

//fork
int		ft_byte_reverse_all(t_cw *cw, int pc, int count);
void	ft_fork(t_cw *cw, t_crg *crg);



#endif
