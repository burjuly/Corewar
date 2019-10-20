/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waddam <waddam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 15:55:36 by waddam            #+#    #+#             */
/*   Updated: 2019/10/21 01:13:54 by waddam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

void		ft_init_sti(t_op *op)
{
	op->arg_nbrs = 3;
	op->bef_op = 25;
	op->need_arg_code = 1;
	op->t_dir = 2;
	op->code_args[0] = REG_REG_REG;
	op->code_args[1] = REG_REG_DIR;
	op->code_args[2] = REG_IND_REG;
	op->code_args[3] = REG_IND_DIR;
	op->code_args[4] = REG_DIR_REG;
	op->code_args[5] = REG_DIR_DIR;
	op->code_args[6] = '\0';
}

static void	ft_check_reg(t_cw *cw, t_crg *crg, t_args *args)
{
	ft_reg(cw, crg, args, 2);
	args->pc_arg3 = (args->pc_arg2 + REG_NUM_SIZE) % MEM_SIZE;
	if (args->code_args == REG_REG_REG)
		ft_reg(cw, crg, args, 3);
	else if (args->code_args == REG_REG_DIR)
		ft_dir_2(cw, args, 3);
}

static void	ft_sti_ind(t_cw *cw, t_crg *crg, t_args *args)
{
	ft_ind_with_idx_mod(cw, crg, args, 2);
	args->pc_arg3 = (args->pc_arg2 + IND) % MEM_SIZE;
	if (args->code_args == REG_IND_REG)
		ft_reg(cw, crg, args, 3);
	else if (args->code_args == REG_IND_DIR)
		ft_dir_2(cw, args, 3);
}

static void	ft_sti_dir(t_cw *cw, t_crg *crg, t_args *args)
{
	ft_dir_2(cw, args, 2);
	args->pc_arg3 = (args->pc_arg2 + DIR_2) % MEM_SIZE;
	if (args->code_args == REG_DIR_REG)
		ft_reg(cw, crg, args, 3);
	else if (args->code_args == REG_DIR_DIR)
		ft_dir_2(cw, args, 3);
}

void		op_sti(t_cw *cw, t_crg *crg)
{
	t_args	args;

	ft_bzero(&args, sizeof(args));
	args.code_args = crg->code_args;
	args.pc_arg1 = (crg->pc + OP_NAME + CODE_ARGS) % MEM_SIZE;
	ft_reg(cw, crg, &args, 1);
	args.pc_arg2 = (args.pc_arg1 + REG_NUM_SIZE) % MEM_SIZE;
	if (args.code_args == REG_REG_REG || args.code_args == REG_REG_DIR)
		ft_check_reg(cw, crg, &args);
	else if (args.code_args == REG_IND_REG || args.code_args == REG_IND_DIR)
		ft_sti_ind(cw, crg, &args);
	else if (args.code_args == REG_DIR_REG || args.code_args == REG_DIR_DIR)
		ft_sti_dir(cw, crg, &args);
	args.address = (crg->pc + (args.arg2 + args.arg3) % IDX_MOD) % MEM_SIZE;
	ft_write_int_in_map(cw, args.address, args.arg1);
}
