/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_ldi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: draudrau <draudrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 15:53:44 by waddam            #+#    #+#             */
/*   Updated: 2019/10/07 14:46:28 by draudrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

// OK
// T_DIR == 2

void	ft_init_ldi(t_op *op)
{
	op->arg_nbrs = 3;
	op->bef_op = 25;
	op->need_arg_code = 1;
	op->t_dir = 2;

	op->code_args[0] = REG_REG_REG; // 1 ОК
	op->code_args[1] = REG_DIR_REG;	// 2
	op->code_args[2] = IND_REG_REG; // 3
	op->code_args[3] = IND_DIR_REG; // 4
	op->code_args[4] = DIR_REG_REG; // 5
	op->code_args[5] = DIR_DIR_REG; // 6
	op->code_args[6] = '\0';
}

void	ft_ldi_REG(t_cw *cw, t_crg *crg, t_args *args)
{
	args->arg1 = crg->reg[(int)cw->map[args->pc_arg1] - 1];
	if (args->code_args == REG_REG_REG) // 1 1 1 code_size = 5
	{
		args->pc_arg2 = (args->pc_arg1 + REG_NUM_SIZE) % MEM_SIZE;
		args->pc_arg3 = (args->pc_arg2 + REG_NUM_SIZE) % MEM_SIZE;
		args->arg2 = crg->reg[(int)cw->map[args->pc_arg2] - 1];
	}
	else if (args->code_args == REG_DIR_REG) // 1 2 1 code_size = 6
	{
		args->pc_arg2 = args->pc_arg1 + REG_NUM_SIZE;
		args->pc_arg3 = args->pc_arg2 + DIR_2;
		args->arg2 = ft_reverse_2(cw, args->pc_arg2);
	}
	args->code_args == REG_REG_REG ? (crg->step = 5) : (crg->step = 6);
}

void	ft_ldi_IND(t_cw *cw, t_crg *crg, t_args *args)
{
	args->arg1 = ft_reverse_2(cw, args->pc_arg1);
	args->arg1 = ft_MOD_IND(args->arg1); // В ДРУГОЕ МЕСТО ПЕРЕСТАВИТЬ ??
	// ПРОВЕРИТЬ!!!  args->pc_arg1
	args->arg1 = (PC + args->arg1) % MEM_SIZE;
	args->arg1 = ft_reverse_4(cw, args->arg1); // считываем 4 байта по адресу arg1
	
	args->pc_arg2 = args->pc_arg1 + IND;
	if (args->code_args == IND_REG_REG) // 2 1 1   code_size = 6
	{
		args->pc_arg3 = args->pc_arg2 + REG_NUM_SIZE;
		args->arg2 = crg->reg[(int)cw->map[args->pc_arg2] - 1];
	}
	else if (args->code_args == IND_DIR_REG) // 2 2 1 code_size = 7
	{
		args->pc_arg3 = args->pc_arg2 + DIR_2;
		args->arg2 = ft_reverse_2(cw, args->pc_arg2);
	}
	args->code_args == IND_REG_REG ? (crg->step = 6) : (crg->step = 7);
}

void	ft_ldi_DIR(t_cw *cw, t_crg *crg, t_args *args)
{
	args->arg1 = ft_reverse_2(cw, args->pc_arg1);
	args->pc_arg2 = args->pc_arg1 + DIR_2;
	if (args->code_args == DIR_REG_REG) //   code_size = 6
	{
		args->arg2 = crg->reg[(int)cw->map[args->pc_arg2] - 1];
		args->pc_arg3 = args->pc_arg2 + REG_NUM_SIZE;
	}
	else if (args->code_args ==  DIR_DIR_REG) //  code_size = 7 
	{
		args->arg2 = ft_reverse_2(cw, args->pc_arg2);
		args->pc_arg3 = args->pc_arg2 + DIR_2;
	}
	args->code_args == DIR_REG_REG ? (crg->step = 6) : (crg->step = 7);
}

void	op_ldi(t_cw *cw, t_crg *crg)
{
	// ПРОВАЛИДИРОВАТЬ РЕГИСТР !!!!
	t_args	args;

	ft_bzero(&args, sizeof(args));
	if ((args.code_args = ft_valid_code_arg(cw, crg, crg->cur_op - 1)) == -1)
	{
		//args.code_args = ft_skip_step(cw, crg, 1);
		return ;
	}
	args.pc_arg1 = (PC + OP_NAME + CODE_ARGS) % MEM_SIZE;
	if (args.code_args == REG_REG_REG || args.code_args == REG_DIR_REG)
		ft_ldi_REG(cw, crg, &args);
	else if (args.code_args == IND_REG_REG || args.code_args == IND_DIR_REG)
		ft_ldi_IND(cw, crg, &args);
	else if (args.code_args == DIR_REG_REG || args.code_args == DIR_DIR_REG)
		ft_ldi_DIR(cw, crg, &args);
	args.arg3 = (int)cw->map[args.pc_arg3];
	ft_print_args(&args);
	args.address = args.arg1 + args.arg2;
	if (args.address < 0)
		args.address = args.address % MEM_SIZE + MEM_SIZE;
	crg->reg[args.arg3 - 1] = ft_reverse_4(cw, ((PC + args.address % IDX_MOD)) % MEM_SIZE);
}
