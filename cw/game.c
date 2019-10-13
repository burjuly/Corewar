/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waddam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 17:06:16 by draudrau          #+#    #+#             */
/*   Updated: 2019/10/13 02:38:30 by waddam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

// 1	live
// 2	ld
// 3	st
// 4	add
// 5	sub
// 6	and
// 7	or
// 8	xor
// 9	zjmp
// 10	ldi
// 11	sti
// 12	fork
// 13	lld
// 14	lldi
// 15	lfork
// 16	aff

void	ft_do_op(t_cw *cw, t_crg *crg)
{
	//crg->reg[0] = 15; // ПРОПИСЫВАЕМ РЕГИСТР ВРУЧНУЮ
	//crg->reg[1] = 63;
	//crg->reg[2] = 5;

	// ft_print_map(cw);
	// printf("ДО ОПЕРАЦИИ\n");
	// ft_print_crg(crg);

	if (crg->cur_op == 1)
	{
		// printf("ЗАШЛИ В ОПЕРАЦИЮ live\n");
		op_live(cw, crg);
	}
	else if (crg->cur_op == 2)
	{
		// printf("ЗАШЛИ В ОПЕРАЦИЮ ld\n");
		op_ld(cw, crg);
	}
	else if(crg->cur_op == 3)
	{
		// printf("ЗАШЛИ В ОПЕРАЦИЮ st\n");
		op_st(cw, crg);
	}
	else if(crg->cur_op == 4)
	{
		// printf("ЗАШЛИ В ОПЕРАЦИЮ add\n");
		op_add(cw, crg);
	}
	else if(crg->cur_op == 5)
	{
		// printf("ЗАШЛИ В ОПЕРАЦИЮ sub\n");
		op_sub(cw, crg);
	}
	else if (crg->cur_op == 6)
	{
		// printf("ЗАШЛИ В ОПЕРАЦИЮ and\n");
		op_and(cw, crg);
	}
	else if(crg->cur_op == 7)
	{
		// printf("ЗАШЛИ В ОПЕРАЦИЮ or\n");
		op_or(cw, crg);
	}
	else if(crg->cur_op == 8)
	{
		// printf("ЗАШЛИ В ОПЕРАЦИЮ xor\n");
		op_xor(cw, crg);
	}
	else if(crg->cur_op == 9)
	{
		// printf("ЗАШЛИ В ОПЕРАЦИЮ zjmp\n");
		op_zjmp(cw, crg);
	}
	else if(crg->cur_op == 10)
	{
		// printf("ЗАШЛИ В ОПЕРАЦИЮ ldi\n");
		op_ldi(cw, crg);
	}
	else if(crg->cur_op == 11)
	{
		// printf("ЗАШЛИ В ОПЕРАЦИЮ sti\n");
		op_sti(cw, crg);
	}
	else if(crg->cur_op == 12)
	{
		// printf("ЗАШЛИ В ОПЕРАЦИЮ fork\n");
		op_fork(cw, crg);
	}
	else if(crg->cur_op == 13)
	{
		// printf("ЗАШЛИ В ОПЕРАЦИЮ lld\n");
		op_lld(cw, crg);
	}
	else if(crg->cur_op == 14)
	{
		// printf("ЗАШЛИ В ОПЕРАЦИЮ lldi\n");
		op_lldi(cw, crg);
	}
	else if(crg->cur_op == 15)
	{
		// printf("ЗАШЛИ В ОПЕРАЦИЮ lfork\n");
		op_lfork(cw, crg);
	}
	else if(crg->cur_op == 16)
	{
		// printf("ЗАШЛИ В ОПЕРАЦИЮ aff\n");
		op_aff(cw, crg);
	}

	// printf("ПОСЛЕ ОПЕРАЦИИ\n");
	// printf("ROUND = %d\n", cw->round);
	// ft_print_map(cw);
	// ft_print_crg(crg);
	//exit(0);
}


void	ft_do_cycle(t_cw *cw)
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
		{
			if (crg->cur_op > 0 && crg->cur_op <= 16)
			{
				if (ft_valid_code_arg(cw, crg) != -1)
					ft_do_op(cw, crg);
				else
					ft_wrong_code_args(cw, crg);
				PC = (PC + crg->step) % MEM_SIZE;
				crg->step = 0;
				crg->code_args = 0;
			}
			else
				(crg->pc)++;
		}
		crg = crg->next;
	}
}

void	ft_del_carriage(t_cw *cw, t_crg *cur, t_crg *prev)
{
	t_crg	*tmp;

	tmp = NULL;
	if (prev == NULL) // Если удаляемая каретка первая в списке
	{
		cw->crg = cur->next;
		// tmp = cur;
		// cur = cw->crg;
		// free(tmp);
		free(cur);
	}
	else
	{
		tmp = cur->next;
		free(cur);
		prev->next = tmp;
	}
}

static void	ft_check_crgs(t_cw *cw)
{
	t_crg	*cur_crg;
	t_crg	*prev_crg;

	cur_crg = cw->crg;
	prev_crg = NULL;
	// cw->checks++;
	while (cur_crg != NULL)
	{
		if (cw->round - cur_crg->last_live >= cw->cycle_to_die
			|| cw->cycle_to_die <= 0)
			ft_del_carriage(cw, cur_crg, prev_crg);
		// if (cw->count_live >= NBR_LIVE)
		// 	cw->c_to_die = cw->c_to_die - CYCLE_DELTA;
		prev_crg = cur_crg;
		cur_crg = cur_crg->next;
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
		// cw->round++;
		// printf("ROUND START GAME = %d\n", cw->round);
		// cw->ctd_round++;
		if (cw->round == cw->dump)
		{
			ft_print_map(cw);
			break ;
		}
		cw->round++;
		// printf("ROUND START GAME = %d\n", cw->round);
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
	if (cw->dump > cw->round)
	{
		ft_print_map(cw);
		return ;
	}
	if (cw->round != cw->dump)
		printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\"), has won !\n",
		cw->last_plr, cw->plr[cw->last_plr - 1].code_size,
		cw->plr[cw->last_plr - 1].name, cw->plr[cw->last_plr - 1].comment);
	//printf("all cyc %i\n", cw->round++);
}
