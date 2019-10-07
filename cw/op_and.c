/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_and.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: draudrau <draudrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 15:46:19 by waddam            #+#    #+#             */
/*   Updated: 2019/10/07 14:59:07 by draudrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

// DIR = 4

void	ft_init_and(t_op *op)
{
	op->arg_nbrs = 3;
	op->bef_op = 6;
	op->need_arg_code = 1;
	op->t_dir = 4;

	op->code_args[0] = REG_REG_REG; // 
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

void	ft_and_REG(t_cw *cw, t_crg *crg, t_args *args)
{
	args->arg1 = crg->reg[(int)cw->map[args->pc_arg1] - 1];
	args->pc_arg2 = (args->pc_arg1 + REG_NUM_SIZE) % MEM_SIZE;
	if (args->code_args == REG_REG_REG)
	{
		args->pc_arg3 = (args->pc_arg2 + REG_NUM_SIZE) % MEM_SIZE;
		args->arg2 = crg->reg[(int)cw->map[args->pc_arg2] - 1];
	}
	else if (args->code_args == REG_IND_REG)
	{
		args->pc_arg3 = (args->pc_arg2 + IND) % MEM_SIZE;
		args->arg2 = ft_reverse_2(cw, args->pc_arg2);
		args->arg2 = ft_MOD_IND(args->arg2);
		args->arg1 = (PC + args->arg1) % MEM_SIZE;
		args->arg2 = ft_reverse_4(cw, args->arg1);
	}
	else if (args->code_args == REG_DIR_REG)
	{
		args->pc_arg3 = (args->pc_arg2 + DIR_4) % MEM_SIZE;
		args->arg2 = cw->map[args->pc_arg2];
	}
	args->arg3 = crg->reg[(int)cw->map[args->pc_arg3] - 1]; 
	crg->reg[args->arg3 - 1] = (args->arg1 & args->arg2);

}

void	ft_and_IND(t_cw *cw, t_crg *crg, t_args *args)
{
	args->arg1 = ft_reverse_2(cw, args->pc_arg1);
	args->arg1 = ft_MOD_IND(args->arg1);
	args->arg1 = (PC + args->arg1) % MEM_SIZE;
	args->arg1 = ft_reverse_4(cw, args->arg1);
	
	args->pc_arg2 = (args->pc_arg1 + IND) % MEM_SIZE;
	if (args->code_args == IND_REG_REG)
	{
		args->arg2 = crg->reg[(int)cw->map[args->pc_arg2] - 1];
		args->pc_arg3 = (args->pc_arg2 + REG_NUM_SIZE) % MEM_SIZE;
	}
	else if (args->code_args == IND_IND_REG)
	{
		args->arg2 = ft_reverse_2(cw, args->pc_arg2);
		args->arg2 = ft_MOD_IND(args->arg2);
		args->arg2 = (PC + args->arg2) % MEM_SIZE;
		args->arg2 = ft_reverse_4(cw, args->arg2);
		args->pc_arg3 = (args->pc_arg2 + IND) % MEM_SIZE;
	}
	else if (args->code_args == IND_DIR_REG)
	{
		args->arg2 = cw->map[args->pc_arg2];
		args->pc_arg3 = (args->pc_arg2 + DIR_4) % MEM_SIZE;
	}
	args->arg3 = crg->reg[(int)cw->map[args->pc_arg3] - 1]; 
	crg->reg[args->arg3 - 1] = (args->arg1 & args->arg2);

}

void	ft_and_DIR(t_cw *cw, t_crg *crg, t_args *args)
{
	args->arg1 = cw->map[args->pc_arg1];
	args->pc_arg2 = (args->pc_arg1 + DIR_4) % MEM_SIZE;
	if (args->code_args == DIR_REG_REG)
	{
		args->arg2 = crg->reg[(int)cw->map[args->pc_arg2] - 1];
		args->pc_arg3 = (args->pc_arg2 + REG_NUM_SIZE) % MEM_SIZE;
	}
	else if (args->code_args == DIR_IND_REG)
	{
		args->arg2 = ft_reverse_2(cw, args->pc_arg2);
		args->arg2 = ft_MOD_IND(args->arg2);
		args->arg2 = (PC + args->arg2) % MEM_SIZE;
		args->arg2 = ft_reverse_4(cw, args->arg2);
		args->pc_arg3 = (args->pc_arg2 + IND) % MEM_SIZE;
	}
	else if (args->code_args == DIR_DIR_REG)
	{
		args->arg2 = cw->map[args->pc_arg2];
		args->pc_arg3 = (args->pc_arg2 + DIR_4) % MEM_SIZE;
	}
	args->arg3 = crg->reg[(int)cw->map[args->pc_arg3] - 1]; 
	crg->reg[args->arg3 - 1] = (args->arg1 & args->arg2);

}

void	op_and(t_cw *cw, t_crg *crg)
{
	t_args args;

	ft_bzero(&args, sizeof(args));
	if ((args.code_args = ft_valid_code_arg(cw, crg, crg->cur_op - 1)) == -1)
	{
		PC = (PC + crg->step) % MEM_SIZE;
		return ;
	}
	args.pc_arg1 = (PC + OP_NAME + CODE_ARGS) % MEM_SIZE;
	if (args.code_args == REG_REG_REG || args.code_args == REG_IND_REG || args.code_args == REG_DIR_REG)
		ft_and_REG(cw, crg, &args);
	else if (args.code_args == IND_REG_REG || args.code_args == IND_IND_REG || args.code_args == IND_DIR_REG)
		ft_and_IND(cw, crg, &args);
	else if (args.code_args == DIR_REG_REG || args.code_args == DIR_IND_REG || args.code_args == DIR_DIR_REG)
		ft_and_DIR(cw, crg, &args);
	
	
}