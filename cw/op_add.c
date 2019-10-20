/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: draudrau <draudrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 15:43:24 by waddam            #+#    #+#             */
/*   Updated: 2019/10/20 17:35:23 by draudrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

void	ft_init_add(t_op *op)
{
	op->arg_nbrs = 3;
	op->bef_op = 10;
	op->need_arg_code = 1;
	op->t_dir = 4;
	op->code_args[0] = REG_REG_REG;
	op->code_args[1] = '\0';
}

void	op_add(t_cw *cw, t_crg *crg)
{
	t_args	args;

	ft_bzero(&args, sizeof(args));
	args.pc_arg1 = (PC + OP_NAME + CODE_ARGS) % MEM_SIZE;
	args.pc_arg2 = (PC + OP_NAME + CODE_ARGS + REG_NUM_SIZE) % MEM_SIZE;
	args.pc_arg3 = (PC + OP_NAME + CODE_ARGS + 2 * REG_NUM_SIZE) % MEM_SIZE;
	args.arg1 = cw->map[args.pc_arg1];
	args.arg2 = cw->map[args.pc_arg2];
	args.arg3 = cw->map[args.pc_arg3];
	crg->reg[args.arg3 - 1] = crg->reg[args.arg1 - 1] + crg->reg[args.arg2 - 1];
	if (crg->reg[args.arg3 - 1] == 0)
		crg->carry = 1;
	else
		crg->carry = 0;
}
