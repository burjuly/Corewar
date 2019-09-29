/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: draudrau <draudrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 20:21:44 by draudrau          #+#    #+#             */
/*   Updated: 2019/09/29 21:35:41 by draudrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

void    ft_print_map(t_cw *cw)
{
    int i;

    i = 0;
    while (i < 4096)
    {
        if (i % 64 == 0)
            printf("\n");
        printf("%x", cw->map[i]);
        // if (i % 2 != 0)
        //     printf(" ");
        i++;
    }

}

void    ft_game(t_cw *cw)
{
    int i;
    int k;
    int delta;

    i = 0;
    k = 1;
    cw->plr_nbrs = 2;
    cw->plr[0].num = 1;
    cw->plr[1].num = 2;
    delta = MEM_SIZE / cw->plr_nbrs;
    ft_memset(cw->map, 0, MEM_SIZE);
    while (1)
    {
        // int j = 0;
        // while (j < cw->plr[0].code_size)
        // {  
        //     printf("%x", (int)cw->plr[0].code[j]);
        //     j++;
        // }
        //printf("%s \n", cw->plr[0].code);
        if (k <= cw->plr_nbrs)
            ft_memcpy(cw->map, cw->plr[k].code, cw->plr[k].code_size);
        else
            break ;
        i = i + delta;
        k++;
    }
    ft_print_map(cw);
}