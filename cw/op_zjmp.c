/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_zjmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: draudrau <draudrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 15:52:12 by waddam            #+#    #+#             */
/*   Updated: 2019/10/05 18:29:29 by draudrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

void	ft_init_zjmp(t_op *op)
{
	op->arg_nbrs = 1;
	op->ccl_cost = 20;
	op->need_arg_code = 0;
	op->low_tdir = 1;

	op->code_args[0] = 128;	//  DIR
	op->code_args[1] = '\0';
}
