/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_ldi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waddam <waddam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 15:53:44 by waddam            #+#    #+#             */
/*   Updated: 2019/10/21 01:15:44 by waddam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

void		ft_init_ldi(t_op *op)
{
	op->arg_nbrs = 3;
	op->bef_op = 25;
	op->need_arg_code = 1;
	op->t_dir = 2;
	op->code_args[0] = REG_REG_REG;
	op->code_args[1] = REG_DIR_REG;
	op->code_args[2] = IND_REG_REG;
	op->code_args[3] = IND_DIR_REG;
	op->code_args[4] = DIR_REG_REG;
	op->code_args[5] = DIR_DIR_REG;
	op->code_args[6] = '\0';
}

static void	ft_ldi_reg(t_cw *cw, t_crg *crg, t_args *args)
{
	ft_reg(cw, crg, args, 1);
	if (args->code_args == REG_REG_REG)
	{
		args->pc_arg2 = (args->pc_arg1 + REG_NUM_SIZE) % MEM_SIZE;
		args->pc_arg3 = (args->pc_arg2 + REG_NUM_SIZE) % MEM_SIZE;
		ft_reg(cw, crg, args, 2);
	}
	else if (args->code_args == REG_DIR_REG)
	{
		args->pc_arg2 = args->pc_arg1 + REG_NUM_SIZE;
		args->pc_arg3 = args->pc_arg2 + DIR_2;
		ft_dir_2(cw, args, 2);
	}
}

static void	ft_ldi_ind(t_cw *cw, t_crg *crg, t_args *args)
{
	ft_ind_with_idx_mod(cw, crg, args, 1);
	args->pc_arg2 = (args->pc_arg1 + IND) % MEM_SIZE;
	if (args->code_args == IND_REG_REG)
	{
		args->pc_arg3 = (args->pc_arg2 + REG_NUM_SIZE) % MEM_SIZE;
		ft_reg(cw, crg, args, 2);
	}
	else if (args->code_args == IND_DIR_REG)
	{
		args->pc_arg3 = (args->pc_arg2 + DIR_2) % MEM_SIZE;
		ft_dir_2(cw, args, 2);
	}
}

static void	ft_ldi_dir(t_cw *cw, t_crg *crg, t_args *args)
{
	args->arg1 = ft_reverse_2(cw, args->pc_arg1);
	args->pc_arg2 = args->pc_arg1 + DIR_2;
	if (args->code_args == DIR_REG_REG)
	{
		args->arg2 = crg->reg[(int)cw->map[args->pc_arg2] - 1];
		args->pc_arg3 = args->pc_arg2 + REG_NUM_SIZE;
	}
	else if (args->code_args == DIR_DIR_REG)
	{
		args->arg2 = ft_reverse_2(cw, args->pc_arg2);
		args->pc_arg3 = args->pc_arg2 + DIR_2;
	}
}

void		op_ldi(t_cw *cw, t_crg *crg)
{
	t_args	args;

	ft_bzero(&args, sizeof(args));
	args.code_args = crg->code_args;
	args.pc_arg1 = (crg->pc + OP_NAME + CODE_ARGS) % MEM_SIZE;
	if (args.code_args == REG_REG_REG || args.code_args == REG_DIR_REG)
		ft_ldi_reg(cw, crg, &args);
	else if (args.code_args == IND_REG_REG || args.code_args == IND_DIR_REG)
		ft_ldi_ind(cw, crg, &args);
	else if (args.code_args == DIR_REG_REG || args.code_args == DIR_DIR_REG)
		ft_ldi_dir(cw, crg, &args);
	args.arg3 = (int)cw->map[args.pc_arg3];
	args.address = args.arg1 + args.arg2;
	crg->reg[args.arg3 - 1] =
		ft_reverse_4(cw, ((crg->pc + args.address % IDX_MOD)) % MEM_SIZE);
}
