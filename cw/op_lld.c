/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_lld.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: draudrau <draudrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 15:58:17 by waddam            #+#    #+#             */
/*   Updated: 2019/10/05 22:35:09 by draudrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../corewar.h"

void	ft_init_lld(t_op *op)
{
	op->arg_nbrs = 2;
	op->ccl_cost = 10;
	op->need_arg_code = 1;
	op->low_tdir = 0;

	op->code_args[0] = 144; //  DIR	REG
	op->code_args[1] = 208; //	IND	REG
	op->code_args[2] = '\0';
}
