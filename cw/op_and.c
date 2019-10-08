/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_and.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: draudrau <draudrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 15:46:19 by waddam            #+#    #+#             */
/*   Updated: 2019/10/08 16:05:25 by draudrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

// DIR = 4
// ЕСТЬ УСЕЧЕНИЕ % IDX_MOD
// МЕНЯЕМ CARRY

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

void	ft_and_REG(t_cw *cw, t_crg *crg, t_args *args)
{
	args->arg1 = crg->reg[(int)cw->map[args->pc_arg1] - 1]; // считали из регистра arg1
	args->pc_arg2 = (args->pc_arg1 + REG_NUM_SIZE) % MEM_SIZE; // нашли pc_arg2
	if (args->code_args == REG_REG_REG)
	{
		args->arg2 = crg->reg[(int)cw->map[args->pc_arg2] - 1]; // записали arg2 REG
		args->pc_arg3 = (args->pc_arg2 + REG_NUM_SIZE) % MEM_SIZE; // нашли pc_arg3
		crg->step = 5;
	}
	else if (args->code_args == REG_IND_REG)
	{
		ft_IND_with_IDX_MOD_2(cw, crg, args); // записали arg2 IND
		args->pc_arg3 = (args->pc_arg2 + IND) % MEM_SIZE; // нашли pc_arg3
		crg->step = 6;
	}
	else if (args->code_args == REG_DIR_REG)
	{
		ft_DIR_4(cw, args, 2); // записали arg2 DIR
		args->pc_arg3 = (args->pc_arg2 + DIR_4) % MEM_SIZE; // нашли pc_arg3
		crg->step = 8;
	}
}

void	ft_and_IND(t_cw *cw, t_crg *crg, t_args *args)
{
	ft_IND_with_IDX_MOD_1(cw, crg, args); // записали arg1
	args->pc_arg2 = (args->pc_arg1 + IND) % MEM_SIZE; // нашли pc_arg2
	if (args->code_args == IND_REG_REG) // 2 1 1
	{
		args->arg2 = crg->reg[(int)cw->map[args->pc_arg2] - 1]; // считали из регистра arg2
		args->pc_arg3 = (args->pc_arg2 + REG_NUM_SIZE) % MEM_SIZE; // нашли pc_arg3
		crg->step = 6;
	}
	else if (args->code_args == IND_IND_REG) // 2 2 1
	{
		ft_IND_with_IDX_MOD_2(cw, crg, args); // записали  arg2
		args->pc_arg3 = (args->pc_arg2 + IND) % MEM_SIZE; // нашли pc_arg3
		crg->step = 7;
	}
	else if (args->code_args == IND_DIR_REG) // 2 4 1
	{
		ft_DIR_4(cw, args, 2); // записали  arg2
		args->pc_arg3 = (args->pc_arg2 + DIR_4) % MEM_SIZE; // нашли pc_arg3
		crg->step = 9;
	}
}

void	ft_and_DIR(t_cw *cw, t_crg *crg, t_args *args)
{
	ft_DIR_4(cw, args, 1);
	args->pc_arg2 = (args->pc_arg1 + DIR_4) % MEM_SIZE; // нашли pc_arg2
	if (args->code_args == DIR_REG_REG) // 4 1 1
	{
		args->arg2 = crg->reg[(int)cw->map[args->pc_arg2] - 1];
		args->pc_arg3 = (args->pc_arg2 + REG_NUM_SIZE) % MEM_SIZE;
		crg->step = 8;
	}
	else if (args->code_args == DIR_IND_REG) // 4 2 1
	{
		ft_IND_with_IDX_MOD_2(cw, crg, args);
		args->pc_arg3 = (args->pc_arg2 + IND) % MEM_SIZE;
		crg->step = 9;
	}
	else if (args->code_args == DIR_DIR_REG) // 4 4 1
	{
		args->arg2 = cw->map[args->pc_arg2];
		args->pc_arg3 = (args->pc_arg2 + DIR_4) % MEM_SIZE;
		crg->step = 11;
	}
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
	args.arg3 = cw->map[args.pc_arg3]; 
	crg->reg[args.arg3 - 1] = (args.arg1 & args.arg2);
	crg->reg[args.arg3 - 1] == 0 ? (crg->carry = 1) : (crg->carry = 0);
	PC = (PC + crg->step) % MEM_SIZE; // ПЕРЕШАГИВАЕМ
	crg->step = 0;
	
	ft_print_args(&args);
}