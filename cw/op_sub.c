/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_sub.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: draudrau <draudrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 15:44:42 by waddam            #+#    #+#             */
/*   Updated: 2019/10/05 18:25:11 by draudrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

void	ft_init_sub(t_op *op)
{
	op->arg_nbrs = 3;
	op->ccl_cost = 10;
	op->need_arg_code = 1;
	op->low_tdir = 0;

	op->code_args[0] = 84; // REG REG REG
	op->code_args[1] = '\0';
}
