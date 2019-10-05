/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_lldi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waddam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 16:00:37 by waddam            #+#    #+#             */
/*   Updated: 2019/10/06 02:13:25 by waddam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../corewar.h"

void	ft_init_lldi(t_op *op)
{
	op->arg_nbrs = 3;
	op->bef_op = 50;
	op->need_arg_code = 1;
	op->t_dir = 2;

	op->code_args[0] = 84;	//  REG	REG	REG
	op->code_args[1] = 100;	//	REG	DIR	REG
	op->code_args[2] = 212;	//  IND	REG	REG
	op->code_args[3] = 228; //  IND	DIR	REG
	op->code_args[4] = 148; //	DIR	REG	REG
	op->code_args[5] = 164; //  DIR	DIR	REG
	op->code_args[6] = '\0';
}