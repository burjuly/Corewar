/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_zjmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: draudrau <draudrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 15:52:12 by waddam            #+#    #+#             */
/*   Updated: 2019/10/13 15:35:47 by draudrau         ###   ########.fr       */
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
	args.pc_arg1 = (PC + OP_NAME) % MEM_SIZE;
	ft_DIR_2(cw, &args, 1);
	// ft_print_args(&args);
	args.arg1 = args.arg1 % IDX_MOD;
	if (args.arg1 < 0)
        args.arg1 = MEM_SIZE + (args.arg1 % MEM_SIZE);
	if (crg->carry == 1)
	{
		PC = (PC + args.arg1) % MEM_SIZE;
		crg->step = 0;
	}
	else
		crg->step = 3;
	printf("CARRY JUMP = %d\n", crg->carry);
}
