/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_help_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waddam <waddam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 19:47:03 by draudrau          #+#    #+#             */
/*   Updated: 2019/10/21 00:49:07 by waddam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

void	ft_dir_4(t_cw *cw, t_args *args, int num_arg)
{
	if (num_arg == 1)
		args->arg1 = ft_reverse_4(cw, args->pc_arg1);
	else if (num_arg == 2)
		args->arg2 = ft_reverse_4(cw, args->pc_arg2);
	else if (num_arg == 3)
		args->arg3 = ft_reverse_4(cw, args->pc_arg3);
}

void	ft_dir_2(t_cw *cw, t_args *args, int num_arg)
{
	if (num_arg == 1)
		args->arg1 = ft_reverse_2(cw, args->pc_arg1);
	else if (num_arg == 2)
		args->arg2 = ft_reverse_2(cw, args->pc_arg2);
	else if (num_arg == 3)
		args->arg3 = ft_reverse_2(cw, args->pc_arg3);
}

void	ft_reg(t_cw *cw, t_crg *crg, t_args *args, int num_arg)
{
	if (num_arg == 1)
		args->arg1 = crg->reg[(int)cw->map[args->pc_arg1] - 1];
	else if (num_arg == 2)
		args->arg2 = crg->reg[(int)cw->map[args->pc_arg2] - 1];
	else if (num_arg == 3)
		args->arg3 = crg->reg[(int)cw->map[args->pc_arg3] - 1];
}

void	ft_write_int_in_map(t_cw *cw, int pc, int value)
{
	if (pc < 0)
		pc = MEM_SIZE + (pc % MEM_SIZE);
	cw->map[(pc + 3) % MEM_SIZE] = (unsigned char)(value & 0xFF);
	cw->map[(pc + 2) % MEM_SIZE] = (unsigned char)((value >> 8) & 0xFF);
	cw->map[(pc + 1) % MEM_SIZE] = (unsigned char)((value >> 16) & 0xFF);
	cw->map[pc % MEM_SIZE] = (unsigned char)((value >> 24) & 0xFF);
}
