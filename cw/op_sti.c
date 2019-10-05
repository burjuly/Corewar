/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waddam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 15:55:36 by waddam            #+#    #+#             */
/*   Updated: 2019/10/06 02:13:47 by waddam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

void	ft_init_sti(t_op *op)
{
	op->arg_nbrs = 3;
	op->bef_op = 25;
	op->need_arg_code = 1;
	op->t_dir = 2;

	op->code_args[0] = 84;	//  REG	REG	REG
	op->code_args[1] = 88;	//	REG	REG	DIR
	op->code_args[2] = 116;	//  REG	IND	REG
	op->code_args[3] = 120; //  REG	IND	DIR
	op->code_args[4] = 100; //	REG	DIR	REG
	op->code_args[5] = 104; //  REG	DIR	DIR
	op->code_args[6] = '\0';
}
