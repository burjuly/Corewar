/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waddam <waddam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 17:06:16 by draudrau          #+#    #+#             */
/*   Updated: 2019/10/22 01:33:58 by waddam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

static void	ft_del_carriage(t_cw *cw, t_crg **cur, t_crg **prev, int *flag)
{
	t_crg	*tmp;

	tmp = NULL;
	if ((*prev) == NULL)
	{
		cw->crg = (*cur)->next;
		free(*cur);
		*cur = cw->crg;
		*flag = 1;
	}
	else
	{
		tmp = (*cur)->next;
		free(*cur);
		*cur = NULL;
		(*prev)->next = tmp;
	}
	cw->count_crg--;
}

static void	ft_check_crgs(t_cw *cw)
{
	t_crg	*cur_crg;
	t_crg	*prev_crg;
	int		flag;

	cur_crg = cw->crg;
	prev_crg = NULL;
	while (cur_crg != NULL)
	{
		flag = 0;
		if (cw->round - cur_crg->last_live >=
			cw->cycle_to_die || cw->cycle_to_die <= 0)
			ft_del_carriage(cw, &cur_crg, &prev_crg, &flag);
		else
			prev_crg = cur_crg;
		if (cur_crg != NULL && flag == 0)
			cur_crg = cur_crg->next;
		else if (cur_crg == NULL)
			cur_crg = prev_crg;
	}
	if (cw->count_live >= NBR_LIVE || cw->checks == MAX_CHECKS)
	{
		cw->cycle_to_die = cw->cycle_to_die - CYCLE_DELTA;
		cw->checks = 0;
	}
}

void		ft_start_game(t_cw *cw)
{
	while (cw->crg != NULL)
	{
		if (cw->round == cw->dump)
		{
			ft_print_map(cw);
			exit(0);
		}
		cw->round++;
		cw->ctd_round++;
		ft_do_cycle(cw);
		if (cw->cycle_to_die == cw->ctd_round || cw->cycle_to_die <= 0)
		{
			cw->checks++;
			ft_check_crgs(cw);
			cw->count_live = 0;
			cw->ctd_round = 0;
		}
	}
	ft_printf("Contestant %d, \"%s\", has won !\n",
		cw->last_plr, cw->plr[cw->last_plr - 1].name);
}
