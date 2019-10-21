/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: draudrau <draudrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 20:44:04 by draudrau          #+#    #+#             */
/*   Updated: 2019/10/21 21:23:15 by draudrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

static void	ft_help_do_op_1(t_cw *cw, t_crg *crg)
{
	if (crg->cur_op == 1)
		op_live(cw, crg);
	else if (crg->cur_op == 2)
		op_ld(cw, crg);
	else if (crg->cur_op == 3)
		op_st(cw, crg);
	else if (crg->cur_op == 4)
		op_add(cw, crg);
	else if (crg->cur_op == 5)
		op_sub(cw, crg);
	else if (crg->cur_op == 6)
		op_and(cw, crg);
	else if (crg->cur_op == 7)
		op_or(cw, crg);
	else if (crg->cur_op == 8)
		op_xor(cw, crg);
}

static void	ft_help_do_op_2(t_cw *cw, t_crg *crg)
{
	if (crg->cur_op == 9)
		op_zjmp(cw, crg);
	else if (crg->cur_op == 10)
		op_ldi(cw, crg);
	else if (crg->cur_op == 11)
		op_sti(cw, crg);
	else if (crg->cur_op == 12)
		op_fork(cw, crg);
	else if (crg->cur_op == 13)
		op_lld(cw, crg);
	else if (crg->cur_op == 14)
		op_lldi(cw, crg);
	else if (crg->cur_op == 15)
		op_lfork(cw, crg);
	else if (crg->cur_op == 16)
		op_aff(cw, crg);
}

void		ft_do_op(t_cw *cw, t_crg *crg)
{
	if (crg->cur_op >= 1 && crg->cur_op <= 8)
		ft_help_do_op_1(cw, crg);
	else if (crg->cur_op >= 9 && crg->cur_op <= 16)
		ft_help_do_op_2(cw, crg);
}
