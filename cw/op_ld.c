/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waddam <waddam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 15:21:04 by waddam            #+#    #+#             */
/*   Updated: 2019/10/21 01:17:02 by waddam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

void		ft_init_ld(t_op *op)
{
	op->arg_nbrs = 2;
	op->bef_op = 5;
	op->need_arg_code = 1;
	op->t_dir = 4;
	op->code_args[0] = DIR_REG;
	op->code_args[1] = IND_REG;
	op->code_args[2] = '\0';
}

static void	ft_ld_dir(t_cw *cw, t_args *args)
{
	ft_dir_4(cw, args, 1);
	args->pc_arg2 = (args->pc_arg1 + DIR_4) % MEM_SIZE;
}

static void	ft_ld_ind(t_cw *cw, t_crg *crg, t_args *args)
{
	ft_ind_with_idx_mod(cw, crg, args, 1);
	args->pc_arg2 = (args->pc_arg1 + IND) % MEM_SIZE;
}

void		op_ld(t_cw *cw, t_crg *crg)
{
	t_args args;

	ft_bzero(&args, sizeof(args));
	args.code_args = crg->code_args;
	args.pc_arg1 = (crg->pc + OP_NAME + CODE_ARGS) % MEM_SIZE;
	if (args.code_args == DIR_REG)
		ft_ld_dir(cw, &args);
	else if (args.code_args == IND_REG)
		ft_ld_ind(cw, crg, &args);
	args.arg2 = cw->map[args.pc_arg2];
	crg->reg[args.arg2 - 1] = args.arg1;
	if (args.arg1 == 0)
		crg->carry = 1;
	else
		crg->carry = 0;
}
