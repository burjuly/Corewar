/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: draudrau <draudrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 15:21:04 by waddam            #+#    #+#             */
/*   Updated: 2019/10/06 21:16:20 by draudrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

void	ft_init_ld(t_op *op)
{
	op->arg_nbrs = 2;
	op->bef_op = 5;
	op->need_arg_code = 1;
	op->t_dir = 4;

	op->code_args[0] = DIR_REG;
	op->code_args[1] = IND_REG;
	op->code_args[2] = '\0';
}

int		ft_MOD_IND(int arg)
{
	arg = arg % MEM_SIZE;
	if (arg < 0)
		arg = arg + MEM_SIZE;
	return (arg);
}

int		ft_valid_code_arg(t_cw *cw, t_crg *crg, int code_op)
{
	int i;
	int pc;

	i = 0;
	pc = crg->pc + 1;
	while (cw->op[code_op].code_args[i])
	{
		if (cw->map[pc] == (char)cw->op[code_op].code_args[i])
			return (cw->op[code_op].code_args[i]);
		i++;
	}
	return (-1);
}

void	ft_ld_DIR(t_cw *cw, t_crg *crg, t_args *args) // DIR_REG 4 1  code_size = 7
{
		args->arg1 = ft_reverse_4(cw, args->pc_arg1);
		args->pc_arg2 = args->pc_arg1 + DIR_4;
		args->arg2 = cw->map[args->pc_arg2];
		crg->step = 7;
}

void	ft_ld_IND(t_cw *cw, t_crg *crg, t_args *args) // IND_REG 2 1 code_size = 5
{
		args->arg1 = ft_reverse_2(cw, args->pc_arg1);
		args->arg1 = ft_MOD_IND(args->arg1);
		args->arg1 = args->arg1 % IDX_MOD;
		args->pc_arg1 = ft_reverse_4(cw, (PC + args->arg1) % MEM_SIZE);
		args->pc_arg2 = args->pc_arg1 + IND;
		args->arg2 = cw->map[args->pc_arg2];
		crg->step = 5;
}

void	op_ld(t_cw *cw, t_crg *crg)
{
	// ПРОВАЛИДИРОВАТЬ РЕГИСТР !!!!
	t_args args;

	ft_bzero(&args, sizeof(args));
	if ((args.code_args = ft_valid_code_arg(cw, crg, crg->cur_op - 1)) == -1)
	{
		//code_arg = ft_skip_step(cw, crg, 1);
		return ;
	}
	args.pc_arg1 = PC + OP_NAME + CODE_ARGS;
	if (args.code_args == DIR_REG) 
		ft_ld_DIR(cw, crg, &args);
	else if (args.code_args == IND_REG)
		ft_ld_IND(cw, crg, &args);
	args.arg2 = cw->map[args.pc_arg2];
	crg->reg[args.arg2 - 1] = args.arg1;
	args.arg1 == 1 ? (crg->carry = 1) : (crg->carry = 0);
	// перешагиваем через step???
}

