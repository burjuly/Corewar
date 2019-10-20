/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_help.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waddam <waddam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 15:02:09 by draudrau          #+#    #+#             */
/*   Updated: 2019/10/21 00:50:03 by waddam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

void	ft_ind_with_idx_mod(t_cw *cw, t_crg *crg, t_args *args, int num_arg)
{
	if (num_arg == 1)
	{
		args->arg1 = ft_reverse_2(cw, args->pc_arg1);
		args->arg1 = args->arg1 % IDX_MOD;
		args->arg1 = (crg->pc + args->arg1) % MEM_SIZE;
		args->arg1 = ft_reverse_4(cw, args->arg1);
	}
	else if (num_arg == 2)
	{
		args->arg2 = ft_reverse_2(cw, args->pc_arg2);
		args->arg1 = args->arg1 % IDX_MOD;
		args->arg2 = (crg->pc + args->arg2) % MEM_SIZE;
		args->arg2 = ft_reverse_4(cw, args->arg2);
	}
}

void	ft_ind(t_cw *cw, t_crg *crg, t_args *args, int num_arg)
{
	if (num_arg == 1)
	{
		args->arg1 = ft_reverse_2(cw, args->pc_arg1);
		args->arg1 = (crg->pc + args->arg1) % MEM_SIZE;
		args->arg1 = ft_reverse_4(cw, args->arg1);
	}
	else if (num_arg == 2)
	{
		args->arg2 = ft_reverse_2(cw, args->pc_arg2);
		args->arg2 = (crg->pc + args->arg2) % MEM_SIZE;
		args->arg2 = ft_reverse_4(cw, args->arg2);
	}
}

int		ft_mod_ind(int arg)
{
	arg = arg % MEM_SIZE;
	if (arg < 0)
		arg = arg + MEM_SIZE;
	return (arg);
}
