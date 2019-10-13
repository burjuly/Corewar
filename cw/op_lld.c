/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_lld.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waddam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 15:58:17 by waddam            #+#    #+#             */
/*   Updated: 2019/10/13 02:49:19 by waddam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// DIR_4 = 4

#include "../corewar.h"

void	ft_init_lld(t_op *op)
{
	op->arg_nbrs = 2;
	op->bef_op = 10;
	op->need_arg_code = 1;
	op->t_dir = 4;

	op->code_args[0] = DIR_REG;
	op->code_args[1] = IND_REG;
	op->code_args[2] = '\0';
}

void	ft_lld_DIR(t_cw *cw, t_crg *crg, t_args *args) // DIR_REG 4 1  code_size = 7
{
		ft_DIR_4(cw, args, 1);
		args->pc_arg2 = (args->pc_arg1 + DIR_4) % MEM_SIZE;
		crg->step = 7;
}

void	ft_lld_IND(t_cw *cw, t_crg *crg, t_args *args) // IND_REG 2 1 code_size = 5
{
		ft_IND(cw, crg, args, 1);
		args->pc_arg2 = args->pc_arg1 + IND;
		crg->step = 5;
}

void	op_lld(t_cw *cw, t_crg *crg)
{
	t_args args;

	ft_bzero(&args, sizeof(args));
	args.code_args = crg->code_args;
	args.pc_arg1 = PC + OP_NAME + CODE_ARGS;
	if (args.code_args == DIR_REG)
		ft_lld_DIR(cw, crg, &args);
	else if (args.code_args == IND_REG)
		ft_lld_IND(cw, crg, &args);

	args.arg2 = cw->map[args.pc_arg2];
	// ft_print_args(&args);
	crg->reg[args.arg2 - 1] = args.arg1;
	args.arg1 == 1 ? (crg->carry = 1) : (crg->carry = 0);
	//crg->pc = PC + crg->step;
	//crg->step = 0;
}
