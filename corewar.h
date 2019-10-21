/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waddam <waddam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 18:00:42 by waddam            #+#    #+#             */
/*   Updated: 2019/10/21 23:51:57 by waddam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include "./libft/libft.h"
# include "op.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define OP_NAME		1
# define CODE_ARGS		1
# define DIR_4			4
# define DIR_2			2
# define IND			2
# define REG_NUM_SIZE	1

# define DIR_REG		144
# define IND_REG		208
# define REG_REG		80
# define REG_IND		112
# define REG_REG_REG	84
# define REG_DIR_REG	100
# define IND_REG_REG	212
# define IND_DIR_REG	228
# define DIR_REG_REG	148
# define DIR_DIR_REG	164
# define REG_IND_REG	116
# define IND_IND_REG	244
# define DIR_IND_REG	180
# define REG_REG_DIR	88
# define REG_IND_DIR	120
# define REG_DIR_DIR	104

typedef struct		s_args
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
	int				num;
	char			name[PROG_NAME_LENGTH + 1];
	int				code_size;
	char			comment[COMMENT_LENGTH + 1];
	char			code[CHAMP_MAX_SIZE + 1];
	int				flag_n;
}					t_plr;

typedef struct		s_crg
{
	int				pc;
	int				carry;
	int				reg[REG_NUMBER];
	int				cur_op;
	int				bef_op;
	int				last_live;
	int				step;
	struct s_crg	*next;
	int				code_args;
	int				args[4];
}					t_crg;

typedef struct		s_op
{
	int				code_args[28];
	char			arg_nbrs;
	char			args[3];
	int				bef_op;
	char			need_arg_code;
	char			t_dir;
}					t_op;

typedef struct		s_cw
{
	t_plr			plr[MAX_PLAYERS];
	t_crg			*crg;
	t_op			op[16];
	char			map[MEM_SIZE];
	int				plr_nbrs;
	int				cycle_to_die;
	int				round;
	int				ctd_round;
	int				checks;
	int				dump;
	int				count_live;
	int				last_plr;
	int				count_crg;
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

void				ft_parse_input(int argc, char **argv, t_cw *cw);
void				ft_write_plr(char **argv, int *i, t_cw *cw, int pos);
int					ft_byte_reverse(char *bytes_array, int count);
void				ft_print_map(t_cw *cw);
void				ft_correct_plrs(t_cw *cw);
void				ft_sort_plrs(t_plr *plr, int size);
void				ft_print_plrs(t_plr *plr, int size);
void				ft_print_crg(t_cw *cw, t_crg *crg);
void				ft_print_args(t_args *args);
void				ft_print_name_op(t_crg *crg);
void				ft_print_map(t_cw *cw);
void				ft_add_carriage(t_cw *cw, int k, int pc);
int					ft_search_next_plr(t_cw *cw, int num);
void				ft_add_plr_on_map(t_cw *cw);
void				ft_map(t_cw *cw);
int					ft_skip_null_sign(char *argv);

void				op_ld(t_cw *cw, t_crg *crg);
void				op_ldi(t_cw *cw, t_crg *crg);
void				op_st(t_cw *cw, t_crg *crg);
void				op_lldi(t_cw *cw, t_crg *crg);
void				op_add(t_cw *cw, t_crg *crg);
void				op_sub(t_cw *cw, t_crg *crg);
void				op_and(t_cw *cw, t_crg *crg);
void				op_or(t_cw *cw, t_crg *crg);
void				op_xor(t_cw *cw, t_crg *crg);
void				ft_and_reg(t_cw *cw, t_crg *crg, t_args *args);
void				ft_and_ind(t_cw *cw, t_crg *crg, t_args *args);
void				ft_and_dir(t_cw *cw, t_crg *crg, t_args *args);
void				op_live(t_cw *cw, t_crg *crg);
void				op_or(t_cw *cw, t_crg *crg);
void				op_xor(t_cw *cw, t_crg *crg);
void				op_zjmp(t_cw *cw, t_crg *crg);
void				op_sti(t_cw *cw, t_crg *crg);
void				op_fork(t_cw *cw, t_crg *crg);
void				op_lld(t_cw *cw, t_crg *crg);
void				op_lfork(t_cw *cw, t_crg *crg);
void				op_aff(t_cw *cw, t_crg *crg);

void				ft_start_game(t_cw *cw);

void				ft_do_op(t_cw *cw, t_crg *crg);

void				ft_do_cycle(t_cw *cw);

int					ft_reverse_2(t_cw *cw, int pc);
int					ft_reverse_4(t_cw *cw, int pc);

void				ft_wrong_code_args(t_cw *cw, t_crg *crg);
int					ft_ld_indft_check_reg_help(t_cw *cw, t_crg *crg);
int					ft_ld_indft_check_reg(t_cw *cw, t_crg *crg);
void				ft_parse_code_arg(t_cw *cw, t_crg *crg);
int					ft_valid_code_arg(t_cw *cw, t_crg *crg);
void				ft_check_help(t_cw *cw, t_crg *crg, int *i, int *pc);
void				ft_help_valid(t_cw *cw, t_crg *crg);

void				ft_ind_with_idx_mod(
						t_cw *cw, t_crg *crg, t_args *args, int num_arg);
void				ft_ind(t_cw *cw, t_crg *crg, t_args *args, int num_arg);
int					ft_mod_ind(int arg);
void				ft_dir_2(t_cw *cw, t_args *args, int num_arg);
void				ft_dir_4(t_cw *cw, t_args *args, int num_arg);
void				ft_reg(t_cw *cw, t_crg *crg, t_args *args, int num_arg);
void				ft_write_int_in_map(t_cw *cw, int pc, int value);

#endif
