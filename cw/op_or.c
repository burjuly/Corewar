/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_or.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waddam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 15:49:46 by waddam            #+#    #+#             */
/*   Updated: 2019/10/13 02:49:19 by waddam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

void	ft_init_or(t_op *op)
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

void	op_or(t_cw *cw, t_crg *crg)
{
	t_args args;

	ft_bzero(&args, sizeof(args));
	args.code_args = crg->code_args;
	args.pc_arg1 = (PC + OP_NAME + CODE_ARGS) % MEM_SIZE;
	if (args.code_args == REG_REG_REG || args.code_args == REG_IND_REG || args.code_args == REG_DIR_REG)
		ft_and_REG(cw, crg, &args);
	else if (args.code_args == IND_REG_REG || args.code_args == IND_IND_REG || args.code_args == IND_DIR_REG)
		ft_and_IND(cw, crg, &args);
	else if (args.code_args == DIR_REG_REG || args.code_args == DIR_IND_REG || args.code_args == DIR_DIR_REG)
		ft_and_DIR(cw, crg, &args);
	args.arg3 = cw->map[args.pc_arg3];
	crg->reg[args.arg3 - 1] = (args.arg1 | args.arg2);
	// ft_print_args(&args);

	//PC = (PC + crg->step) % MEM_SIZE; // ПЕРЕШАГИВАЕМ
	//crg->step = 0;
}
