/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: draudrau <draudrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 15:55:36 by waddam            #+#    #+#             */
/*   Updated: 2019/10/20 19:33:06 by draudrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

void	ft_init_sti(t_op *op)
{
	op->arg_nbrs = 3;
	op->bef_op = 25;
	op->need_arg_code = 1;
	op->t_dir = 2;
	op->code_args[0] = REG_REG_REG;
	op->code_args[1] = REG_REG_DIR;
	op->code_args[2] = REG_IND_REG;
	op->code_args[3] = REG_IND_DIR;
	op->code_args[4] = REG_DIR_REG;
	op->code_args[5] = REG_DIR_DIR;
	op->code_args[6] = '\0';
}

void	ft_sti_REG(t_cw *cw, t_crg *crg, t_args *args)
{
	ft_REG(cw, crg, args, 2);
	args->pc_arg3 = (args->pc_arg2 + REG_NUM_SIZE) % MEM_SIZE;
	if (args->code_args == REG_REG_REG)
		ft_REG(cw, crg, args, 3);
	else if (args->code_args == REG_REG_DIR)
		ft_DIR_2(cw, args, 3);
}

void	ft_sti_IND(t_cw *cw, t_crg *crg, t_args *args)
{
	ft_IND_with_IDX_MOD(cw, crg, args, 2);
	args->pc_arg3 = (args->pc_arg2 + IND) % MEM_SIZE;
	if (args->code_args == REG_IND_REG)
		ft_REG(cw, crg, args, 3);
	else if (args->code_args == REG_IND_DIR)
		ft_DIR_2(cw, args, 3);
}

void	ft_sti_DIR(t_cw *cw, t_crg *crg, t_args *args)
{
	ft_DIR_2(cw, args, 2);
	args->pc_arg3 = (args->pc_arg2 + DIR_2) % MEM_SIZE;
	if (args->code_args == REG_DIR_REG)
		ft_REG(cw, crg, args, 3);
	else if (args->code_args == REG_DIR_DIR)
		ft_DIR_2(cw, args, 3);
}

void	op_sti(t_cw *cw, t_crg *crg)
{
	t_args	args;

	ft_bzero(&args, sizeof(args));
	args.code_args = crg->code_args;
	args.pc_arg1 = (PC + OP_NAME + CODE_ARGS) % MEM_SIZE;
	ft_REG(cw, crg, &args, 1);
	args.pc_arg2 = (args.pc_arg1 + REG_NUM_SIZE) % MEM_SIZE;
	if (args.code_args == REG_REG_REG || args.code_args == REG_REG_DIR)
		ft_sti_REG(cw, crg, &args);
	else if (args.code_args == REG_IND_REG || args.code_args == REG_IND_DIR)
		ft_sti_IND(cw, crg, &args);
	else if (args.code_args == REG_DIR_REG || args.code_args == REG_DIR_DIR)
		ft_sti_DIR(cw, crg, &args);
	args.address = (PC + (args.arg2 + args.arg3) % IDX_MOD) % MEM_SIZE;
	ft_write_int_in_map(cw, args.address, args.arg1);
}