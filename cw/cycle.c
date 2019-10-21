/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: draudrau <draudrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 20:57:59 by draudrau          #+#    #+#             */
/*   Updated: 2019/10/21 21:02:24 by draudrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

static void	ft_do_cycle_help(t_cw *cw, t_crg *crg)
{
	if (crg->cur_op > 0 && crg->cur_op <= 16)
	{
		if (ft_valid_code_arg(cw, crg) != -1)
			ft_do_op(cw, crg);
		else
			ft_wrong_code_args(cw, crg);
		crg->pc = (crg->pc + crg->step) % MEM_SIZE;
		crg->step = 0;
		crg->code_args = 0;
	}
	else
		crg->pc = (crg->pc + 1) % MEM_SIZE;
}

void		ft_do_cycle(t_cw *cw)
{
	t_crg	*crg;

	crg = cw->crg;
	while (crg != NULL)
	{
		if (crg->bef_op == 0)
		{
			crg->cur_op = cw->map[crg->pc];
			if (crg->cur_op > 0 && crg->cur_op <= 16)
				crg->bef_op = cw->op[crg->cur_op - 1].bef_op;
		}
		if (crg->bef_op > 0)
			(crg->bef_op)--;
		if (crg->bef_op == 0)
			ft_do_cycle_help(cw, crg);
		crg = crg->next;
	}
}
