/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: draudrau <draudrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 17:06:16 by draudrau          #+#    #+#             */
/*   Updated: 2019/10/16 14:42:12 by draudrau         ###   ########.fr       */
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
	if (crg->cur_op == 1)
		op_live(cw, crg);
	else if (crg->cur_op == 2)
		op_ld(cw, crg);
	else if(crg->cur_op == 3)
		op_st(cw, crg);
	else if(crg->cur_op == 4)
		op_add(cw, crg);
	else if(crg->cur_op == 5)
		op_sub(cw, crg);
	else if (crg->cur_op == 6)
		op_and(cw, crg);
	else if(crg->cur_op == 7)
		op_or(cw, crg);
	else if(crg->cur_op == 8)
		op_xor(cw, crg);
	else if(crg->cur_op == 9)
		op_zjmp(cw, crg);
	else if(crg->cur_op == 10)
		op_ldi(cw, crg);
	else if(crg->cur_op == 11)
		op_sti(cw, crg);
	else if(crg->cur_op == 12)
		op_fork(cw, crg);
	else if(crg->cur_op == 13)
		op_lld(cw, crg);
	else if(crg->cur_op == 14)
		op_lldi(cw, crg);
	else if(crg->cur_op == 15)
		op_lfork(cw, crg);
	else if(crg->cur_op == 16)
		op_aff(cw, crg);
}


void	ft_do_cycle(t_cw *cw)
{
	t_crg	*crg;
	int		i;
	i = 0;

	crg = cw->crg;
	// if (cw->round >= 24330 && cw->round <= 24331)
	// {
	// 	printf("\nROUND = %d\n", cw->round);
	// 	printf("CYCLE TO DIE = %d\n", cw->cycle_to_die);
	// 	printf("КОЛ-ВО КАРЕТОК = %d\n", cw->count_crg);
	// 	ft_print_crg(cw, cw->crg);
	// }
	while (crg != NULL)
	{
		i++;
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
				// if (cw->round >= 24330 && cw->round <= 24331)
				// {
				// 	printf("\nROUND = %d\n", cw->round);
				// 	printf("CYCLE TO DIE = %d\n", cw->cycle_to_die);
				// 	printf("КОЛ-ВО КАРЕТОК = %d\n", cw->count_crg);
				// 	ft_print_crg(cw, cw->crg);
				// }
				crg->step = 0;
				crg->code_args = 0;
			}
			else
				(crg->pc)++;
		}
		crg = crg->next;
	}
	// if (cw->round >= 20000 && cw->round <= 25000)
	// {
	// 	printf("\nROUND = %d\n", cw->round);
	// 	printf("CYCLE TO DIE = %d\n", cw->cycle_to_die);
	// 	printf("КОЛ-ВО КАРЕТОК = %d\n", cw->count_crg);
	// 	ft_print_crg(cw, cw->crg);
	// }
}

void	ft_del_carriage(t_cw *cw, t_crg **cur, t_crg **prev, int *flag)
{
	t_crg	*tmp;

	tmp = NULL;
	if ((*prev) == NULL) // Если удаляемая каретка первая в списке
	{
		cw->crg = (*cur)->next;
		// tmp = cur;
		// free(tmp);
		free(*cur);
		*cur = cw->crg;
		*flag = 1;
	}
	else
	{
		tmp = (*cur)->next;
		free(*cur);
		(*prev)->next = tmp;
	}
	cw->count_crg--;
}

static void	ft_check_crgs(t_cw *cw)
{
	t_crg	*cur_crg;
	t_crg	*prev_crg;
	int		i = 0;
	int		flag;

	cur_crg = cw->crg;
	prev_crg = NULL;
	cw->checks++;
	while (cur_crg != NULL)
	{
		flag = 0;
		if (cw->round - cur_crg->last_live > cw->cycle_to_die || cw->cycle_to_die <= 0)
		{
			i++;
			ft_del_carriage(cw, &cur_crg, &prev_crg, &flag);
		}
		else
			prev_crg = cur_crg;
		if (cur_crg != NULL && flag == 0)
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
	int debug = 0;
	//ft_print_map(cw);
	while (cw->crg != NULL)
	{
		cw->round++;
		cw->ctd_round++;
		//printf("LAST_PLR = %d\n", cw->last_plr);
		if (cw->round == cw->dump)
		{
			ft_print_map(cw);
			exit(0);
			break ;
		}
		if (cw->round == 24329)
			debug = 1;
		if (cw->cycle_to_die == cw->ctd_round || cw->cycle_to_die <= 0)
		{
			ft_check_crgs(cw);
			cw->count_live = 0;
			cw->ctd_round = 0;
		}
		ft_do_cycle(cw);
	}
	if (cw->dump > cw->round)
	{
		ft_print_map(cw);
		exit(0);
	}
	printf("ROUND = %d\n", cw->round);
	if (cw->round != cw->dump)
		printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\"), has won !\n",
		cw->last_plr, cw->plr[cw->last_plr - 1].code_size,
		cw->plr[cw->last_plr - 1].name, cw->plr[cw->last_plr - 1].comment);
	//printf("all cyc %i\n", cw->round++);
}
