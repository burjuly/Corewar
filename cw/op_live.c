/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waddam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 15:01:03 by waddam            #+#    #+#             */
/*   Updated: 2019/10/05 15:20:28 by waddam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

void	ft_init_live(t_op *op)
{
	ft_init_arg1(op);
	ft_init_arg2(op);
	op->arg_nbrs = 1;
	op->ccl_cost = 10;
	op->need_arg_code = 0;
	op->low_tdir = 0;
}

void	op_live(t_cw *cw, t_crg *crg)
{
	int		num_plr;

	num_plr = crg->reg[0];
	cw->count_live++;
	crg->last_live = cw->ctd_round;
	if (num_plr > 0 && num_plr <= cw->plr_nbrs)
	{
		cw->last_plr = num_plr;
		// printf(игрок жив);
	}
	crg->pc += 5;
	crg->pc %= MEM_SIZE;
}
