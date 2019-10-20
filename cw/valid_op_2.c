/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_op_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: draudrau <draudrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 20:43:41 by draudrau          #+#    #+#             */
/*   Updated: 2019/10/20 20:50:03 by draudrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

int		ft_check_REG(t_cw *cw, t_crg *crg)
{
	if (ft_check_REG_help(cw, crg) == 1)
		return (1);
	return (-1);
}

void	ft_help_valid(t_cw *cw, t_crg *crg)
{
	int count_args;

	count_args = cw->op[crg->cur_op - 1].arg_nbrs;
	if (count_args == 1)
		crg->code_args = crg->code_args & 192;
	else if (count_args == 2)
		crg->code_args = crg->code_args & 240;
	else if (count_args == 3)
		crg->code_args = crg->code_args & 252;
}

void	ft_check_help(t_cw *cw, t_crg *crg, int *i, int *pc)
{
	if (crg->args[*i] == 2)
	{
		*pc = (*pc + (int)(cw->op[crg->cur_op - 1].t_dir)) % MEM_SIZE;
		crg->step = crg->step + (int)(cw->op[crg->cur_op - 1].t_dir);
	}
	else if (crg->args[*i] == 3)
	{
		*pc = *pc + IND;
		crg->step = crg->step + IND;
	}
}
