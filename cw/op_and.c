/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_and.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waddam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 15:46:19 by waddam            #+#    #+#             */
/*   Updated: 2019/10/06 02:12:09 by waddam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

void	ft_init_and(t_op *op)
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
