/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_sub.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: draudrau <draudrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 15:44:42 by waddam            #+#    #+#             */
/*   Updated: 2019/10/10 20:16:32 by draudrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

// t_DIR = 4
// Меняет carry

void	ft_init_sub(t_op *op)
{
	op->arg_nbrs = 3;
	op->bef_op = 10;
	op->need_arg_code = 1;
	op->t_dir = 4;

	op->code_args[0] = 84; // REG REG REG
	op->code_args[1] = '\0';
}

void	op_sub(t_cw *cw, t_crg *crg)
{
	int		res;
	t_args	args;
	
	res = 0;
	ft_bzero(&args, sizeof(args));
	if ((args.code_args = ft_valid_code_arg(cw, crg, crg->cur_op - 1)) == -1)
	{
		PC = (PC + crg->step) % MEM_SIZE;
		return ;
	}
	args.pc_arg1 = (PC + OP_NAME + CODE_ARGS) % MEM_SIZE;
	args.pc_arg2 = (PC + OP_NAME + CODE_ARGS + REG_NUM_SIZE) % MEM_SIZE;
	args.pc_arg3 = (PC + OP_NAME + CODE_ARGS + 2 * REG_NUM_SIZE) % MEM_SIZE;
	args.arg1 = cw->map[args.pc_arg1];
	args.arg2 = cw->map[args.pc_arg2];
	args.arg3 = cw->map[args.pc_arg3]; 
	if (args.arg1 < 1 || args.arg1 > 16 || args.arg2 < 1 // валидация REG
	|| args.arg2 > 16 || args.arg3 < 1 || args.arg3 > 16)
	{
		// Обработать случай невалидных регистров
		return ;
	}
	args.arg1 = crg->reg[args.arg1];
	args.arg2 = crg->reg[args.arg2];
	res = args.arg1 - args.arg2;
	crg->reg[args.arg3 - 1] = res;
	ft_print_args(&args);
	(res == 0) ? (crg->carry = 1) : (crg->carry = 0);
	PC = (PC + OP_NAME + CODE_ARGS + 3 * REG_NUM_SIZE) % MEM_SIZE;
	crg->step = 0;
}
