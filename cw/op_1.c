/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waddam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 00:01:58 by waddam            #+#    #+#             */
/*   Updated: 2019/10/04 01:31:52 by waddam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

void	op_live(t_cw *cw, t_crg *crg)
{
	int		num_plr;

	num_plr = crg->num_plr;
	cw->count_live++;
	crg->last_live = cw->ctd_round;
	if (num_plr > 0 && num_plr <= cw->plr_nbrs)
	{
		cw->plr[num_plr].last_live = cw->ctd_round;
		cw->last_plr = num_plr;
	}
	crg->pc += 5;
	crg->pc %= MEM_SIZE;
}

// void	op_live(t_vm *v, t_list *process)
// {
// 	int live;

// 	LIVE++;
// 	v->nlive_bctd++;
// 	live = reverse_bytes(v, PC + 1, 4);
// 	if (DISPLAY && (v->verbose_param & FLAG_VERBOSE_OPERATIONS))
// 		ft_printf("P %4d | live %d\n", NPRO, live);
// 	is_player(v, live);
// 	if (DISPLAY && (v->verbose_param & FLAG_VERBOSE_PCMOVE))
// 		print_adv(v, process, 5);
// 	PC += 5;
// 	PC %= MEM_SIZE;
// 	LIVE_SINCE = -1;
// }