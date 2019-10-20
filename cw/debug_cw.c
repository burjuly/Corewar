/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_cw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waddam <waddam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 00:32:25 by waddam            #+#    #+#             */
/*   Updated: 2019/10/21 01:24:38 by waddam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

void	ft_print_plrs(t_plr *plr, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		ft_printf(">>Player%i<<\n", i + 1);
		ft_printf("num:       %i\n", plr[i].num);
		ft_printf("name:      %s\n", plr[i].name);
		ft_printf("code_size: %i\n", plr[i].code_size);
		ft_printf("comment:   %s\n", plr[i].comment);
		ft_printf("code:      %s\n", plr[i].code);
		ft_printf("flag_n:    %i\n", plr[i].flag_n);
		i++;
		if (i != size)
			ft_printf("\n");
	}
}

void	ft_print_args(t_args *args)
{
	ft_printf("CODE_ARGS = %d\n", args->code_args);
	ft_printf("ARG 1 = %d\n", args->arg1);
	ft_printf("ARG 2 = %d\n", args->arg2);
	ft_printf("ARG 3 = %d\n", args->arg3);
	ft_printf("crg->pc_ARG 1 = %d\n", args->pc_arg1);
	ft_printf("crg->pc_ARG 2 = %d\n", args->pc_arg2);
	ft_printf("crg->pc_ARG 3 = %d\n", args->pc_arg3);
	ft_printf("adrress = %d\n", args->address);
}

void	ft_print_crg(t_cw *cw, t_crg *crg)
{
	int		i;
	int		j;
	int		count;
	t_crg	*tmp;

	j = 1;
	count = 0;
	tmp = crg;
	while (tmp)
	{
		tmp = tmp->next;
		count++;
	}
	ft_printf("\nROUND = %d\n", cw->round);
	ft_printf("CYCLE TO DIE = %d\n", cw->cycle_to_die);
	ft_printf("КОЛ-ВО КАРЕТОК = %d\n", count);
	//printf("КОЛ-ВО КАРЕТОК = %d\n", cw->count_crg);
	while (crg != NULL)
	{
		i = -1;
		ft_printf("КАРЕТКА №%d\n", j);
		while (++i < 16)
			ft_printf("reg[%d] = %d\n", i, crg->reg[i]);
		ft_printf("pc = %d\n", crg->pc);
		ft_printf("carry = %d\n", crg->carry);
		ft_printf("cur_op = %d\n", crg->cur_op);
		//printf("bef_op = %d\n", crg->bef_op);
		crg = crg->next;
		j++;
	}
}

void	ft_print_name_op(t_crg *crg)
{
	if (crg->cur_op == 1)
		ft_printf("ЗАШЛИ В ОПЕРАЦИЮ live\n");
	else if (crg->cur_op == 2)
		ft_printf("ЗАШЛИ В ОПЕРАЦИЮ ld\n");
	else if (crg->cur_op == 3)
		ft_printf("ЗАШЛИ В ОПЕРАЦИЮ st\n");
	else if (crg->cur_op == 4)
		ft_printf("ЗАШЛИ В ОПЕРАЦИЮ add\n");
	else if (crg->cur_op == 5)
		ft_printf("ЗАШЛИ В ОПЕРАЦИЮ sub\n");
	else if (crg->cur_op == 6)
		ft_printf("ЗАШЛИ В ОПЕРАЦИЮ and\n");
	else if (crg->cur_op == 7)
		ft_printf("ЗАШЛИ В ОПЕРАЦИЮ or\n");
	else if (crg->cur_op == 8)
		ft_printf("ЗАШЛИ В ОПЕРАЦИЮ xor\n");
	else if (crg->cur_op == 9)
		ft_printf("ЗАШЛИ В ОПЕРАЦИЮ zjmp\n");
	else if (crg->cur_op == 10)
		ft_printf("ЗАШЛИ В ОПЕРАЦИЮ ldi\n");
	else if (crg->cur_op == 11)
		ft_printf("ЗАШЛИ В ОПЕРАЦИЮ sti\n");
	else if (crg->cur_op == 12)
		ft_printf("ЗАШЛИ В ОПЕРАЦИЮ fork\n");
	else if (crg->cur_op == 13)
		ft_printf("ЗАШЛИ В ОПЕРАЦИЮ lld\n");
	else if (crg->cur_op == 14)
		ft_printf("ЗАШЛИ В ОПЕРАЦИЮ lldi\n");
	else if (crg->cur_op == 15)
		ft_printf("ЗАШЛИ В ОПЕРАЦИЮ lfork\n");
	else if (crg->cur_op == 16)
		ft_printf("ЗАШЛИ В ОПЕРАЦИЮ aff\n");
}
