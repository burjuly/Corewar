/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: draudrau <draudrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 16:06:18 by waddam            #+#    #+#             */
/*   Updated: 2019/10/05 18:43:01 by draudrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../corewar.h"

void	ft_init_aff(t_op *op)
{
	op->arg_nbrs = 1;
	op->ccl_cost = 2;
	op->need_arg_code = 1;
	op->low_tdir = 0;

	op->code_args[0] = 64; // REG
	op->code_args[1] = '\0';
}
