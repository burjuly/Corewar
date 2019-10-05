/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waddam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 15:01:03 by waddam            #+#    #+#             */
/*   Updated: 2019/10/06 02:18:09 by waddam           ###   ########.fr       */
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
	printf("типы аргументов live: %d\n", (int)(op->code_args[0]));
}

void	op_live(t_cw *cw, t_crg *crg)
{
	int		num_plr;

	num_plr = -(crg->reg[0]);
	cw->count_live++;
	crg->last_live = cw->ctd_round;
	// crg->last_live = cw->round; // ?
	if (num_plr > 0 && num_plr <= cw->plr_nbrs)
	{
		cw->last_plr = num_plr;
		// printf(игрок жив);
	}
	crg->pc += 5;
	crg->pc %= MEM_SIZE;
}
