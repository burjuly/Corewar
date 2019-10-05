/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: draudrau <draudrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 15:55:36 by waddam            #+#    #+#             */
/*   Updated: 2019/10/05 18:35:30 by draudrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

void	ft_init_sti(t_op *op)
{
	op->arg_nbrs = 3;
	op->ccl_cost = 25;
	op->need_arg_code = 1;
	op->low_tdir = 1;

	op->code_args[0] = 84;	//  REG	REG	REG
	op->code_args[1] = 88;	//	REG	REG	DIR
	op->code_args[2] = 116;	//  REG	IND	REG
	op->code_args[3] = 120; //  REG	IND	DIR
	op->code_args[4] = 100; //	REG	DIR	REG
	op->code_args[5] = 104; //  REG	DIR	DIR
	op->code_args[6] = '\0';
}
