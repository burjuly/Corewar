/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waddam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 16:06:18 by waddam            #+#    #+#             */
/*   Updated: 2019/10/13 02:49:19 by waddam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../corewar.h"

//ПРОВЕРЯЕМ КОД АРГ

void	ft_init_aff(t_op *op)
{
	op->arg_nbrs = 1;
	op->bef_op = 2;
	op->need_arg_code = 1;
	op->t_dir = 4;

	op->code_args[0] = 64; // REG
	op->code_args[1] = '\0';
}

void	op_aff(t_cw *cw, t_crg *crg)
{
	t_args	args;

	crg->reg[0] = 50;
	ft_bzero(&args, sizeof(args));
	args.pc_arg1 = (PC + OP_NAME + CODE_ARGS) % MEM_SIZE;
	ft_REG(cw, crg, &args, 1);
	// ft_print_args(&args);
	ft_putchar((char)(args.arg1 % 256));
	PC = (PC + 3) % MEM_SIZE;
}
