/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waddam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 15:34:26 by waddam            #+#    #+#             */
/*   Updated: 2019/10/06 12:48:50 by waddam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

void	ft_init_st(t_op *op)
{
	op->arg_nbrs = 2;
	op->bef_op = 5;
	op->need_arg_code = 1;
	op->t_dir = 4;

	op->code_args[0] = REG_REG;
	op->code_args[1] = REG_IND;
	op->code_args[2] = '\0';
}

void	op_st(t_cw *cw, t_crg *crg)
{
	int		code_arg;
	int		pc_arg1;
	int		pc_arg2;
	int		arg1;
	int		arg2;

	pc_arg1 = 0;
	pc_arg2 = 0;
	code_arg = ft_valid_code_arg(cw, crg, 2); // считали код аргумента, ниже провалидируем
	// if ()
	// {

	// }
	pc_arg1 = PC + OP_NAME + CODE_ARGS;
	pc_arg2 = pc_arg1 + REG_NUM_SIZE;
	if (code_arg == REG_REG)
	{
		arg1 = (int)cw->map[pc_arg1]; // номер регистра
		arg2 = (int)cw->map[pc_arg1]; // номер регистра
		crg->reg[arg2 - 1] = crg->reg[arg1 - 1];
	}
	else if ()
	{

	}
}
