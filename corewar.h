/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: draudrau <draudrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 18:00:42 by waddam            #+#    #+#             */
/*   Updated: 2019/10/08 16:35:36 by draudrau         ###   ########.fr       */
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

# define PC				crg->pc
# define OP_NAME		1
# define CODE_ARGS		1
# define DIR_4			4
# define DIR_2			2
# define IND			2
# define REG_NUM_SIZE	1

# define DIR_REG		144
# define IND_REG		208
# define REG_REG		0b01010000
# define REG_IND		0b01110000
# define REG_REG_REG	84
# define REG_DIR_REG	100
# define IND_REG_REG	212
# define IND_DIR_REG	228
# define DIR_REG_REG	148
# define DIR_DIR_REG	164
# define REG_IND_REG	116
# define IND_IND_REG	244
# define DIR_IND_REG	180




typedef struct		t_args
{
	int				arg1;
	int				arg2;
	int				arg3;
	int				pc_arg1;
	int				pc_arg2;
	int				pc_arg3;
	int				code_args;
	int				address;
}					t_args;

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

typedef struct 		s_op
{
	int				code_args[28];	// /0
	char			arg_nbrs;		// количество аргументов
	char			args[3];		// массив аргументов
	int				bef_op;			// "стоимость" в циклах
	char			need_arg_code;	// нужен ли код типов аргументов
	char			t_dir;		// использует T_DIR = 2
}					t_op;

typedef struct		s_cw
{
	t_plr			plr[MAX_PLAYERS];	// массив структур типа "игрок"
	t_crg			*crg;				// указатель на список кареток
	t_op			op[16];				// масcив операций
	char			map[MEM_SIZE];		// карта
	int				plr_nbrs;	// количество игроков
	int				c_to_die;	// текущий cycle to die
	int				round;		// количество прошедших с начала игры циклов
	int				ctd_round;	// количество прошедших с последней проверки циклов
	int				checks;		// количество проверок
	int				dump;		// флаг dump (если > 0, тогда это номер цикла для dump)
	int				count_live;	// количество выполненных операций live за последний период, длинной в cycles_to_die
	int				last_plr;	// игрок, о котором в последний раз сказали, что он жив
}					t_cw;

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

// операции
void				ft_IND_with_IDX_MOD(t_cw *cw, t_crg *crg, t_args *args);
void				op_ld(t_cw *cw, t_crg *crg);
void				ft_ld_DIR(t_cw *cw, t_crg *crg, t_args *args);
void				ft_ld_IND(t_cw *cw, t_crg *crg, t_args *args);

void				op_ldi(t_cw *cw, t_crg *crg);
void				ft_ldi_REG(t_cw *cw, t_crg *crg, t_args *args);
void				ft_ldi_IND(t_cw *cw, t_crg *crg, t_args *args);
void				ft_ldi_DIR(t_cw *cw, t_crg *crg, t_args *args);

void				op_st(t_cw *cw, t_crg *crg);

void				ft_lldi_REG(t_cw *cw, t_crg *crg, t_args *args);
void				ft_lldi_IND(t_cw *cw, t_crg *crg, t_args *args);
void				ft_lldi_DIR(t_cw *cw, t_crg *crg, t_args *args);
void				op_lldi(t_cw *cw, t_crg *crg);

void				op_add(t_cw *cw, t_crg *crg);
void				op_sub(t_cw *cw, t_crg *crg);

void				op_and(t_cw *cw, t_crg *crg);
void				op_or(t_cw *cw, t_crg *crg);
void				op_xor(t_cw *cw, t_crg *crg);
void				ft_and_REG(t_cw *cw, t_crg *crg, t_args *args);
void				ft_and_IND(t_cw *cw, t_crg *crg, t_args *args);
void				ft_and_DIR(t_cw *cw, t_crg *crg, t_args *args);


void				op_live(t_cw *cw, t_crg *crg);
void				op_or(t_cw *cw, t_crg *crg);
void				op_xor(t_cw *cw, t_crg *crg);
void				op_zjmp(t_cw *cw, t_crg *crg);
void				op_sti(t_cw *cw, t_crg *crg);
void				op_fork(t_cw *cw, t_crg *crg);
void				op_lld(t_cw *cw, t_crg *crg);
void				op_lfork(t_cw *cw, t_crg *crg);
void				op_aff(t_cw *cw, t_crg *crg);


// game
void				ft_start_game(t_cw *cw);
void				ft_do_cycle(t_cw *cw);
void 				ft_do_op(t_cw *cw, t_crg *crg);

// reverse
int					ft_reverse_2(t_cw *cw, int pc);
int					ft_reverse_4(t_cw *cw, int pc);

// DEBUG
void				ft_print_args(t_args *args);

//Валидация аргументов
void				ft_wrong_code_args(t_crg *crg, int size_DIR, char code);
int					ft_valid_code_arg(t_cw *cw, t_crg *crg, int code_op);

// arg_IND
void				ft_IND_with_IDX_MOD_1(t_cw *cw, t_crg *crg, t_args *args);
void				ft_IND_with_IDX_MOD_2(t_cw *cw, t_crg *crg, t_args *args);
void				ft_IND_1(t_cw *cw, t_crg *crg, t_args *args);
void				ft_IND_2(t_cw *cw, t_crg *crg, t_args *args);
int					ft_MOD_IND(int arg); // обрезаем по модулю IND
void				ft_DIR_2(t_cw *cw, t_args *args, int num_arg);
void				ft_DIR_4(t_cw *cw, t_args *args, int num_arg);
void				ft_REG(t_cw *cw, t_crg *crg, t_args *args, int num_arg);
void				ft_write_int_in_map(t_cw *cw, int pc, int value);

#endif
