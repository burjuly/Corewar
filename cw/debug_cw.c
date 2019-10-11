/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_cw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: draudrau <draudrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 00:32:25 by waddam            #+#    #+#             */
/*   Updated: 2019/10/11 15:25:41 by draudrau         ###   ########.fr       */
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

void	ft_print_crg(t_crg *crg)
{
	int		i = 0;

	while (i < 16)
	{
		printf("reg[%d] = %d\n", i, crg->reg[i]);
		i++;
	}
		printf("pc = %d\n", crg->pc);
		printf("carry = %d\n", crg->carry);
		printf("cur_op = %d\n", crg->cur_op);
		printf("bef_op = %d\n", crg->bef_op);
		printf("last_live = %d\n", crg->last_live);
		printf("step = %d\n", crg->step);
}
