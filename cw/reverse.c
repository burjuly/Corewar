/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: draudrau <draudrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 16:09:37 by draudrau          #+#    #+#             */
/*   Updated: 2019/10/09 13:08:55 by draudrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

int     ft_reverse_2(t_cw *cw, int pc)
{
    short     num;
    char    two_bytes[2];

    if (pc < 0)
        pc = MEM_SIZE + (pc % MEM_SIZE);
    two_bytes[1] = (cw->map[pc % MEM_SIZE]);
    two_bytes[0] = (cw->map[(pc + 1) % MEM_SIZE]);
    num = *(short*)two_bytes;
    return (num);
}

int     ft_reverse_4(t_cw *cw, int pc)
{
    int     num;
    char    four_bytes[4];

    // ldi работает из без if с отрицательным pc (pc = -2). Как??????
    if (pc < 0)
        pc = MEM_SIZE + (pc % MEM_SIZE);
    four_bytes[3] = (cw->map[pc % MEM_SIZE]) ;
    four_bytes[2] = (cw->map[(pc + 1) % MEM_SIZE]);
    four_bytes[1] = (cw->map[(pc + 2) % MEM_SIZE]);
    four_bytes[0] = (cw->map[(pc + 3) % MEM_SIZE]);
    num = *(int*)four_bytes;
    return (num);
}

