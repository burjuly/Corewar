/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_zjmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waddam <waddam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 15:52:12 by waddam            #+#    #+#             */
/*   Updated: 2019/10/21 00:48:52 by waddam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

void	ft_init_zjmp(t_op *op)
{
	op->arg_nbrs = 1;
	op->bef_op = 20;
	op->need_arg_code = 0;
	op->t_dir = 2;
	op->code_args[0] = 128;
	op->code_args[1] = '\0';
}

void	op_zjmp(t_cw *cw, t_crg *crg)
{
	t_args args;

	ft_bzero(&args, sizeof(args));
	args.pc_arg1 = (crg->pc + OP_NAME) % MEM_SIZE;
	ft_dir_2(cw, &args, 1);
	args.arg1 = args.arg1 % IDX_MOD;
	if (args.arg1 < 0)
		args.arg1 = MEM_SIZE + (args.arg1 % MEM_SIZE);
	if (crg->carry == 1)
	{
		crg->pc = (crg->pc + args.arg1) % MEM_SIZE;
		crg->step = 0;
	}
	else
		crg->step = 3;
}
