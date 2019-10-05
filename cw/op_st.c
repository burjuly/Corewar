/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: draudrau <draudrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 15:34:26 by waddam            #+#    #+#             */
/*   Updated: 2019/10/05 18:24:33 by draudrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

void	ft_init_st(t_op *op)
{
	op->arg_nbrs = 2;
	op->ccl_cost = 5;
	op->need_arg_code = 1;
	op->low_tdir = 0;

	op->code_args[0] = 80; 	// REG REG
	op->code_args[1] = 112; // REG IND
	op->code_args[2] = '\0';
}
