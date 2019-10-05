/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: draudrau <draudrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 15:21:04 by waddam            #+#    #+#             */
/*   Updated: 2019/10/05 18:24:10 by draudrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

void	ft_init_ld(t_op *op)
{
	op->arg_nbrs = 2;
	op->ccl_cost = 5;
	op->need_arg_code = 1;
	op->low_tdir = 0;

	op->code_args[0] = 144;
	op->code_args[1] = 208;
	op->code_args[2] = '\0';
}


