/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_and.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waddam <waddam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 15:46:19 by waddam            #+#    #+#             */
/*   Updated: 2019/10/21 01:08:24 by waddam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

void	ft_init_and(t_op *op)
{
	op->arg_nbrs = 3;
	op->bef_op = 6;
	op->need_arg_code = 1;
	op->t_dir = 4;
	op->code_args[0] = REG_REG_REG;
	op->code_args[1] = REG_IND_REG;
	op->code_args[2] = REG_DIR_REG;
	op->code_args[3] = IND_REG_REG;
	op->code_args[4] = IND_IND_REG;
	op->code_args[5] = IND_DIR_REG;
	op->code_args[6] = DIR_REG_REG;
	op->code_args[7] = DIR_IND_REG;
	op->code_args[8] = DIR_DIR_REG;
	op->code_args[9] = '\0';
}

void	ft_and_reg(t_cw *cw, t_crg *crg, t_args *args)
{
	ft_reg(cw, crg, args, 1);
	args->pc_arg2 = (args->pc_arg1 + REG_NUM_SIZE) % MEM_SIZE;
	if (args->code_args == REG_REG_REG)
	{
		ft_reg(cw, crg, args, 2);
		args->pc_arg3 = (args->pc_arg2 + REG_NUM_SIZE) % MEM_SIZE;
	}
	else if (args->code_args == REG_IND_REG)
	{
		ft_ind_with_idx_mod(cw, crg, args, 2);
		args->pc_arg3 = (args->pc_arg2 + IND) % MEM_SIZE;
	}
	else if (args->code_args == REG_DIR_REG)
	{
		ft_dir_4(cw, args, 2);
		args->pc_arg3 = (args->pc_arg2 + DIR_4) % MEM_SIZE;
	}
}

void	ft_and_ind(t_cw *cw, t_crg *crg, t_args *args)
{
	ft_ind_with_idx_mod(cw, crg, args, 1);
	args->pc_arg2 = (args->pc_arg1 + IND) % MEM_SIZE;
	if (args->code_args == IND_REG_REG)
	{
		ft_reg(cw, crg, args, 2);
		args->pc_arg3 = (args->pc_arg2 + REG_NUM_SIZE) % MEM_SIZE;
	}
	else if (args->code_args == IND_IND_REG)
	{
		ft_ind_with_idx_mod(cw, crg, args, 2);
		args->pc_arg3 = (args->pc_arg2 + IND) % MEM_SIZE;
	}
	else if (args->code_args == IND_DIR_REG)
	{
		ft_dir_4(cw, args, 2);
		args->pc_arg3 = (args->pc_arg2 + DIR_4) % MEM_SIZE;
	}
}

void	ft_and_dir(t_cw *cw, t_crg *crg, t_args *args)
{
	ft_dir_4(cw, args, 1);
	args->pc_arg2 = (args->pc_arg1 + DIR_4) % MEM_SIZE;
	if (args->code_args == DIR_REG_REG)
	{
		ft_reg(cw, crg, args, 2);
		args->pc_arg3 = (args->pc_arg2 + REG_NUM_SIZE) % MEM_SIZE;
	}
	else if (args->code_args == DIR_IND_REG)
	{
		ft_ind_with_idx_mod(cw, crg, args, 2);
		args->pc_arg3 = (args->pc_arg2 + IND) % MEM_SIZE;
	}
	else if (args->code_args == DIR_DIR_REG)
	{
		ft_dir_4(cw, args, 2);
		args->pc_arg3 = (args->pc_arg2 + DIR_4) % MEM_SIZE;
	}
}

void	op_and(t_cw *cw, t_crg *crg)
{
	t_args args;

	ft_bzero(&args, sizeof(args));
	args.code_args = crg->code_args;
	args.pc_arg1 = (crg->pc + OP_NAME + CODE_ARGS) % MEM_SIZE;
	if (args.code_args == REG_REG_REG || args.code_args == REG_IND_REG
	|| args.code_args == REG_DIR_REG)
		ft_and_reg(cw, crg, &args);
	else if (args.code_args == IND_REG_REG || args.code_args == IND_IND_REG
	|| args.code_args == IND_DIR_REG)
		ft_and_ind(cw, crg, &args);
	else if (args.code_args == DIR_REG_REG || args.code_args == DIR_IND_REG
	|| args.code_args == DIR_DIR_REG)
		ft_and_dir(cw, crg, &args);
	args.arg3 = cw->map[args.pc_arg3];
	crg->reg[args.arg3 - 1] = (args.arg1 & args.arg2);
	if (crg->reg[args.arg3 - 1] == 0)
		crg->carry = 1;
	else
		crg->carry = 0;
}
