/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_lld.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: draudrau <draudrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 15:58:17 by waddam            #+#    #+#             */
/*   Updated: 2019/10/06 21:14:51 by draudrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// DIR_4 = 4

#include "../corewar.h"

void	ft_init_lld(t_op *op)
{
	op->arg_nbrs = 2;
	op->bef_op = 10;
	op->need_arg_code = 1;
	op->t_dir = 4;

	op->code_args[0] = DIR_REG;
	op->code_args[1] = IND_REG;
	op->code_args[2] = '\0';
}

void	ft_lld_DIR(t_cw *cw, t_crg *crg, t_args *args) // DIR_REG 4 1  code_size = 7
{
		args->arg1 = ft_reverse_4(cw, args->pc_arg1);
		args->pc_arg2 = args->pc_arg1 + DIR_4;
		args->arg2 = cw->map[args->pc_arg2];
		crg->step = 7;
}

void	ft_lld_IND(t_cw *cw, t_crg *crg, t_args *args) // IND_REG 2 1 code_size = 5
{
		args->arg1 = ft_reverse_2(cw, args->pc_arg1);
		args->arg1 = ft_MOD_IND(args->arg1);
		// НЕ ОБРЕЗАЕМ АРГ % IDX_MOD
		args->arg1 = ft_reverse_4(cw, PC + args->arg1);
		args->pc_arg2 = args->pc_arg1 + IND;
		args->arg2 = cw->map[args->pc_arg2];
		crg->step = 5;
}

void	op_lld(t_cw *cw, t_crg *crg)
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
		ft_lld_DIR(cw, crg, &args);
	else if (args.code_args == IND_REG)
		ft_lld_IND(cw, crg, &args);
	args.arg2 = cw->map[args.pc_arg2];
	crg->reg[args.arg2 - 1] = args.arg1;
	args.arg1 == 1 ? (crg->carry = 1) : (crg->carry = 0);
	// перешагиваем через step???
}
