/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_cw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: draudrau <draudrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 00:32:25 by waddam            #+#    #+#             */
/*   Updated: 2019/10/17 20:27:02 by draudrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

void	ft_print_plrs(t_plr *plr, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		printf(">>Player%i<<\n", i + 1);
		printf("num:       %i\n", plr[i].num);
		printf("name:      %s\n", plr[i].name);
		printf("code_size: %i\n", plr[i].code_size);
		printf("comment:   %s\n", plr[i].comment);
		printf("code:      %s\n", plr[i].code);
		printf("flag_n:    %i\n", plr[i].flag_n);
		i++;
		if (i != size)
			printf("\n");
	}
}

void	ft_print_args(t_args *args)
{
	printf("CODE_ARGS = %d\n", args->code_args);
	printf("ARG 1 = %d\n", args->arg1);
	printf("ARG 2 = %d\n", args->arg2);
	printf("ARG 3 = %d\n", args->arg3);
	printf("PC_ARG 1 = %d\n", args->pc_arg1);
	printf("PC_ARG 2 = %d\n", args->pc_arg2);
	printf("PC_ARG 3 = %d\n", args->pc_arg3);
	printf("adrress = %d\n", args->address);
}

void	ft_print_crg(t_cw *cw, t_crg *crg)
{
	int		i = 0;
	int		j = 1;

	while (crg != NULL)
	{
		i = 0;
		printf("КАРЕТКА №%d\n", j);
			while (i < 16)
		{
			printf("reg[%d] = %d\n", i, crg->reg[i]);
			i++;
		}
		printf("pc = %d\n", crg->pc);
		printf("carry = %d\n", crg->carry);
		printf("cur_op = %d\n", crg->cur_op);
		printf("LAST_LIVE= %d\n", cw->round - crg->last_live);
		//printf("bef_op = %d\n", crg->bef_op);
		crg = crg->next;
		j++;
	}
	// while (i < 16)
	// {
	// 	printf("reg[%d] = %d\n", i, crg->reg[i]);
	// 	i++;
	// }
	// printf("pc = %d\n", crg->pc);
	// printf("carry = %d\n", crg->carry);
	// printf("cur_op = %d\n", crg->cur_op);
	//printf("bef_op = %d\n", crg->bef_op);
	//printf("last_live = %d\n", crg->last_live);
	//printf("step = %d\n", crg->step);
}

void	ft_print_name_op(t_crg *crg)
{
	if (crg->cur_op == 1)
		printf("ЗАШЛИ В ОПЕРАЦИЮ live\n");
	else if (crg->cur_op == 2)
		printf("ЗАШЛИ В ОПЕРАЦИЮ ld\n");
	else if(crg->cur_op == 3)
		printf("ЗАШЛИ В ОПЕРАЦИЮ st\n");
	else if(crg->cur_op == 4)
		printf("ЗАШЛИ В ОПЕРАЦИЮ add\n");
	else if(crg->cur_op == 5)
		printf("ЗАШЛИ В ОПЕРАЦИЮ sub\n");
	else if (crg->cur_op == 6)
		printf("ЗАШЛИ В ОПЕРАЦИЮ and\n");
	else if(crg->cur_op == 7)
		printf("ЗАШЛИ В ОПЕРАЦИЮ or\n");
	else if(crg->cur_op == 8)
		printf("ЗАШЛИ В ОПЕРАЦИЮ xor\n");
	else if(crg->cur_op == 9)
		printf("ЗАШЛИ В ОПЕРАЦИЮ zjmp\n");
	else if(crg->cur_op == 10)
		printf("ЗАШЛИ В ОПЕРАЦИЮ ldi\n");
	else if(crg->cur_op == 11)
		printf("ЗАШЛИ В ОПЕРАЦИЮ sti\n");
	else if(crg->cur_op == 12)
		printf("ЗАШЛИ В ОПЕРАЦИЮ fork\n");
	else if(crg->cur_op == 13)
		printf("ЗАШЛИ В ОПЕРАЦИЮ lld\n");
	else if(crg->cur_op == 14)
		printf("ЗАШЛИ В ОПЕРАЦИЮ lldi\n");
	else if(crg->cur_op == 15)
		printf("ЗАШЛИ В ОПЕРАЦИЮ lfork\n");
	else if(crg->cur_op == 16)
		printf("ЗАШЛИ В ОПЕРАЦИЮ aff\n");
}