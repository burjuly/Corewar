/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: draudrau <draudrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 20:21:44 by draudrau          #+#    #+#             */
/*   Updated: 2019/10/05 16:29:58 by draudrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

void    ft_print_map(t_cw *cw)
{
    int i;

    i = 0;
    while (i < 4096)
    {
        if (i % 64 == 0 && i != 0)
            printf("\n");
        printf("%.2hhx ", cw->map[i]);
        i++;
    }

}

// k - номер игрока со знаком "+"
void    ft_add_carriage(t_cw *cw, int k, int pc)
{
    t_crg   *start;
    t_crg   *new;

    start = cw->crg;
    if (start == NULL) // Если создаем 1-ю каретку
    {
        if (!(start = (t_crg *)malloc(sizeof(t_crg))))
            ft_leave("Придумать что-нибудь на случай, если не выделилась память");
        ft_bzero(start, sizeof(t_crg));
        //start->num_plr = -k; // кладем номер plr со знаком '-'
        start->pc = pc;
        start->reg[0] = -k;
        start->next = NULL;
        cw->crg = start;
    }
    else
    {
        if (!(new = (t_crg *)malloc(sizeof(t_crg))))
            ft_leave("Придумать что-нибудь на случай, если не выделилась память");
        ft_bzero(new, sizeof(t_crg));
        //new->num_plr = -k; // кладем номер plr со знаком '-'
        new->pc = pc;
        new->reg[0] = -k;
        new->next = start;
        cw->crg = new;
    }
}

int    ft_search_next_plr(t_cw *cw, int num)
{
    int i;

    i = 0;
    while (i < cw->plr_nbrs)
    {
        if (cw->plr[i].num == num)
            return (i);
        i++;
    }
    return (0);
}

void    ft_add_plr_on_map(t_cw *cw)
{
    int     i;
    int     j;
    int     k;
    int     delta;

    i = 0;
    k = 1;
    delta = MEM_SIZE / cw->plr_nbrs; // отступ между чемпионами
    ft_memset(cw->map, 0, MEM_SIZE);
    printf("Introducing contestants...\n");
    while (i < 4096 && k <= cw->plr_nbrs)
    {
        j = ft_search_next_plr(cw, k); // Ищем кого будем добавлять на арену следующим
        if (j < cw->plr_nbrs)
            ft_memcpy(&(cw->map[i]), cw->plr[j].code, cw->plr[j].code_size);
        else
            break ;
        ft_add_carriage(cw, k, i); // Добавляем новую каретку
        i = i + delta; // Позиция, где начнется код следующего чемпиона
        k++;
    }
    cw->last_plr = j; // игрок, о котором в последний раз сказали, что он жив
}

void    ft_map(t_cw *cw)
{
    ft_add_plr_on_map(cw);

    /**********************************************/
    // Проверка что записалоcь в регистры каретки
    t_crg *lst = cw->crg;
    int num = 0;
    while (lst != NULL)
    {
        int i = 0;
        while (i < 16)
        {
            printf("каретка №%d reg = %d [%d]\n", num, i, lst->reg[i]);
            i++;
        }
        num++;
        lst = lst->next;
    }
    /************************************************/
    //ft_print_map(cw);
}