/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_xor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: draudrau <draudrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 15:51:23 by waddam            #+#    #+#             */
/*   Updated: 2019/10/08 15:41:41 by draudrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

void	ft_init_xor(t_op *op)
{
	op->arg_nbrs = 3;
	op->bef_op = 6;
	op->need_arg_code = 1;
	op->t_dir = 4;

	op->code_args[0] = 84;	//  REG	REG	REG
	op->code_args[1] = 116;	//	REG	IND	REG
	op->code_args[2] = 100;	//  REG	DIR	REG
	op->code_args[3] = 212; //  IND	REG	REG
	op->code_args[4] = 244; //	IND	IND	REG
	op->code_args[5] = 228; //  IND	DIR	REG
	op->code_args[6] = 148; //  DIR	REG	REG
	op->code_args[7] = 180; //  DIR	IND	REG
	op->code_args[8] = 164; //  DIR	DIR	REG
	op->code_args[9] = '\0';
}

void	op_xor(t_cw *cw, t_crg *crg)
{
	t_args args;

	ft_bzero(&args, sizeof(args));
	if ((args.code_args = ft_valid_code_arg(cw, crg, crg->cur_op - 1)) == -1)
	{
		PC = (PC + crg->step) % MEM_SIZE;
		return ;
	}
	args.pc_arg1 = (PC + OP_NAME + CODE_ARGS) % MEM_SIZE;
	if (args.code_args == REG_REG_REG || args.code_args == REG_IND_REG || args.code_args == REG_DIR_REG)
		ft_and_REG(cw, crg, &args);
	else if (args.code_args == IND_REG_REG || args.code_args == IND_IND_REG || args.code_args == IND_DIR_REG)
		ft_and_IND(cw, crg, &args);
	else if (args.code_args == DIR_REG_REG || args.code_args == DIR_IND_REG || args.code_args == DIR_DIR_REG)
		ft_and_DIR(cw, crg, &args);
	args.arg3 = cw->map[args.pc_arg3]; 
	crg->reg[args.arg3 - 1] = (args.arg1 ^ args.arg2);
	ft_print_args(&args);

	PC = (PC + crg->step) % MEM_SIZE; // ПЕРЕШАГИВАЕМ
	crg->step = 0;
}