/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: draudrau <draudrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 20:15:27 by draudrau          #+#    #+#             */
/*   Updated: 2019/10/04 21:29:26 by draudrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

int		ft_byte_reverse_all(t_cw *cw, int pc, int count)
{
    int     i;
    int     num;
    char    two_bytes[2];
    char    four_bytes[4];
    
    i = 0;
    if (count == 2)
    {
        while (i < count)
        {
            two_bytes[i] = cw->map[pc + i];
            i++;
        }
        num = ft_byte_reverse(&two_bytes, 2);
    }
    else
    {
        while (i < count)
        {
            two_bytes[i] = cw->map[pc + i];
            i++;
        }
        num = ft_byte_reverse(&two_bytes, 4);
    }
    return (num);
}

void ft_fork(t_cw *cw, t_crg *crg)
{
    int     i;
    int     pc;
    int     arg;
    t_crg   *new;


    // if (ft_valid_arg() == 0)
    //
    i = 0;
    arg = ft_byte_reverse_all(cw, crg->pc + 1, 2);
    pc = (crg->pc + (arg % IDX_MOD)) % MEM_SIZE;
    ft_add_carriage(cw, -(crg->reg[0]), pc);
    new = cw->crg;
    while (i < REG_NUMBER)
    {
        new->reg[i] = crg->reg[i];
        i++;
    }
    new->num_plr = crg->num_plr;
    new->carry = crg->carry;
    new->cur_op = crg->cur_op;
    new->bef_op = crg->bef_op;
    new->last_live = crg->last_live;
    new->step = crg->step;
    crg->pc = (crg->pc + 3) % MEM_SIZE;
}