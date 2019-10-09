/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_help.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: draudrau <draudrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 15:02:09 by draudrau          #+#    #+#             */
/*   Updated: 2019/10/09 14:30:50 by draudrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

void	ft_IND_with_IDX_MOD(t_cw *cw, t_crg *crg, t_args *args, int num_arg) // ЕСТЬ УСЕЧЕНИЕ % IDX_MOD
{
	if (num_arg == 1)
	{
		args->arg1 = ft_reverse_2(cw, args->pc_arg1);
		//args->arg1 = ft_MOD_IND(args->arg1);
		args->arg1 = args->arg1 % IDX_MOD;
		args->arg1 = (PC + args->arg1) % MEM_SIZE;
		args->arg1 = ft_reverse_4(cw, args->arg1);
	}
	else if (num_arg == 2)
	{
		args->arg2 = ft_reverse_2(cw, args->pc_arg2);
		args->arg2 = ft_MOD_IND(args->arg2);
		args->arg1 = args->arg1 % IDX_MOD;
		args->arg2 = (PC + args->arg2) % MEM_SIZE;
		args->arg2 = ft_reverse_4(cw, args->arg2);
	}
	
}

// void	ft_IND_with_IDX_MOD_2(t_cw *cw, t_crg *crg, t_args *args) // ЕСТЬ УСЕЧЕНИЕ % IDX_MOD
// {
// 	args->arg2 = ft_reverse_2(cw, args->pc_arg2);
// 	args->arg2 = ft_MOD_IND(args->arg2);
// 	args->arg1 = args->arg1 % IDX_MOD;
// 	args->arg2 = (PC + args->arg2) % MEM_SIZE;
// 	args->arg2 = ft_reverse_4(cw, args->arg2);
// }

void	ft_IND(t_cw *cw, t_crg *crg, t_args *args, int num_arg) // БЕЗ УСЕЧЕНИЯ % IDX_MOD
{
	if (num_arg == 1)
	{
		args->arg1 = ft_reverse_2(cw, args->pc_arg1);
		//args->arg1 = ft_MOD_IND(args->arg1);
		//args->arg1 = args->arg1 % IDX_MOD;
		args->arg1 = (PC + args->arg1) % MEM_SIZE;
		args->arg1 = ft_reverse_4(cw, args->arg1);
	}
	else if (num_arg == 2)
	{
		args->arg2 = ft_reverse_2(cw, args->pc_arg2);
		//args->arg2 = ft_MOD_IND(args->arg2);
		//args->arg1 = args->arg1 % IDX_MOD;
		args->arg2 = (PC + args->arg2) % MEM_SIZE;
		args->arg2 = ft_reverse_4(cw, args->arg2);
	}
}

// void	ft_IND_2(t_cw *cw, t_crg *crg, t_args *args) // БЕЗ УСЕЧЕНИЯ % IDX_MOD
// {
// 	args->arg2 = ft_reverse_2(cw, args->pc_arg2);
// 	args->arg2 = ft_MOD_IND(args->arg2);
// 	//args->arg1 = args->arg1 % IDX_MOD;
// 	args->arg2 = (PC + args->arg2) % MEM_SIZE;
// 	args->arg2 = ft_reverse_4(cw, args->arg2);
// }

int		ft_MOD_IND(int arg)
{
	arg = arg % MEM_SIZE;
	if (arg < 0)
		arg = arg + MEM_SIZE;
	return (arg);
}

void	ft_DIR_4(t_cw *cw, t_args *args, int num_arg)
{
	if (num_arg == 1)
		args->arg1 = ft_reverse_4(cw, args->pc_arg1);
	else if (num_arg == 2)
		args->arg2 = ft_reverse_4(cw, args->pc_arg2);
	else if (num_arg == 3)
		args->arg3 = ft_reverse_4(cw, args->pc_arg3);
}

void	ft_DIR_2(t_cw *cw, t_args *args, int num_arg)
{
	if (num_arg == 1)
		args->arg1 = ft_reverse_2(cw, args->pc_arg1);
	else if (num_arg == 2)
		args->arg2 = ft_reverse_2(cw, args->pc_arg2);
	else if (num_arg == 3)
		args->arg3 = ft_reverse_2(cw, args->pc_arg3);
}

void	ft_REG(t_cw *cw, t_crg *crg, t_args *args, int num_arg)
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
	cw->map[(pc + 3) % MEM_SIZE] = (unsigned char)(value & 0xFF);
	cw->map[(pc + 2) % MEM_SIZE] = (unsigned char)((value >> 8) & 0xFF);
	cw->map[(pc + 1) % MEM_SIZE] = (unsigned char)((value >> 16) & 0xFF);
	cw->map[pc % MEM_SIZE] = (unsigned char)((value >> 24) & 0xFF);
}
