/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: draudrau <draudrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 15:21:04 by waddam            #+#    #+#             */
/*   Updated: 2019/10/07 13:28:28 by draudrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

// OK
// МЕНЯЕМ CARRY
// ПЕРЕШАГИВАЕМ
void	ft_init_ld(t_op *op)
{
	op->arg_nbrs = 2;
	op->bef_op = 5;
	op->need_arg_code = 1;
	op->t_dir = 4;

	op->code_args[0] = DIR_REG;
	op->code_args[1] = IND_REG;
	op->code_args[2] = '\0';
}

void	ft_ld_DIR(t_cw *cw, t_crg *crg, t_args *args) // DIR_REG 4 1  code_size = 7
{
		args->arg1 = ft_reverse_4(cw, args->pc_arg1);
		args->pc_arg2 = (args->pc_arg1 + DIR_4) % MEM_SIZE;
		args->arg2 = cw->map[args->pc_arg2];
		crg->step = 7;
}

void	ft_ld_IND(t_cw *cw, t_crg *crg, t_args *args) // IND_REG 2 1 code_size = 5
{
		args->arg1 = ft_reverse_2(cw, args->pc_arg1);
		args->arg1 = ft_MOD_IND(args->arg1);
		args->arg1 = args->arg1 % IDX_MOD; // ЕСТЬ УСЕЧЕНИЕ
		args->pc_arg1 = (PC + args->arg1) % MEM_SIZE;
		args->pc_arg1 = ft_reverse_4(cw, args->pc_arg1);
		args->pc_arg2 = (args->pc_arg1 + IND) % MEM_SIZE;
		args->arg2 = cw->map[args->pc_arg2];
		crg->step = 5;
}

void	op_ld(t_cw *cw, t_crg *crg)
{
	// ПРОВАЛИДИРОВАТЬ РЕГИСТР !!!!
	t_args args;

	ft_bzero(&args, sizeof(args));
	if ((args.code_args = ft_valid_code_arg(cw, crg, crg->cur_op - 1)) == -1)
	{
		PC = (PC + crg->step) % MEM_SIZE;
		return ;
	}
	args.pc_arg1 = (PC + OP_NAME + CODE_ARGS) % MEM_SIZE;
	if (args.code_args == DIR_REG) 
		ft_ld_DIR(cw, crg, &args);
	else if (args.code_args == IND_REG)
		ft_ld_IND(cw, crg, &args);
	args.arg2 = cw->map[args.pc_arg2];
	crg->reg[args.arg2 - 1] = args.arg1;
	args.arg1 == 0 ? (crg->carry = 1) : (crg->carry = 0);
	
	PC = (PC + crg->step) % MEM_SIZE; // ПЕРЕШАГИВАЕМ
	crg->step = 0;
}

