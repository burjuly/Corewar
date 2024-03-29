/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waddam <waddam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 15:01:03 by waddam            #+#    #+#             */
/*   Updated: 2019/10/21 00:48:41 by waddam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

void	ft_init_live(t_op *op)
{
	op->arg_nbrs = 1;
	op->bef_op = 10;
	op->need_arg_code = 0;
	op->t_dir = 4;
	op->code_args[0] = 128;
	op->code_args[1] = '\0';
}

void	op_live(t_cw *cw, t_crg *crg)
{
	int		num_plr;
	t_args	args;

	ft_bzero(&args, sizeof(args));
	args.pc_arg1 = (crg->pc + OP_NAME) % MEM_SIZE;
	ft_dir_4(cw, &args, 1);
	num_plr = args.arg1;
	cw->count_live++;
	crg->last_live = cw->round;
	if ((-num_plr) > 0 && (-num_plr) <= cw->plr_nbrs)
		cw->last_plr = -num_plr;
	crg->step = 5;
}
