/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: draudrau <draudrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 17:06:16 by draudrau          #+#    #+#             */
/*   Updated: 2019/10/03 20:22:15 by draudrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

void    ft_do_cycle(t_cw *cw, t_crg *lst)
{
    while (lst != NULL)
    {
        if (lst->bef_op == 0 && lst->cur_op == -1)
        {
            //Каретка передвигалась на пред шаге
            // Считываем байт на котором стоит каретка
            // Это код реальной операции ? - запоминаем код
            // Устанавливаем lst->bef_op
            // ! Не считывае код типа аргументов и сами аргументы
        }
        if (lst->bef_op == 0)
        {
            // 1. Код операции [0x01; 0x10]? Валидность кода типа аргументов
            // Номера регистра, если он есть
            // Все норм -> выполняем операцию и передвигаем каретку
            
            // 2. Код операции ошибочен ? -> передвигаем каретку на след байт

            // 3. Код операции норм, но код типа аргументов или номер регистра ошибочны ->
            // - пропускаем данную операцию вместе с кодом типов аргументов и самими аргументами
        }
        else if (lst->bef_op > 0)
        {
            lst->bef_op--;
        }
        lst = lst->next;
    }
}

void    ft_del_carriage(t_cw *cw, t_crg *cur, t_crg *prev)
{
    t_crg *tmp;

    tmp = NULL;
    if (prev == NULL) // Если удаляемая каретка первая в списке
    {
        cw->crg = cur->next;
        tmp = cur;
        cur = cw->crg;
        free(tmp);
    }
    else
    {
        tmp = cur->next;
        free(cur);
        prev->next = tmp;
    }
}

void    ft_check(t_cw *cw)
{
    t_crg *curren_car;
    t_crg *prev_car;

    curren_car = cw->crg;
    prev_car = NULL;
    cw->checks++;
    while (curren_car != NULL)
    {
        if (curren_car->last_live > cw->c_to_die)
        {
            ft_del_carriage(cw, curren_car, prev_car);  // Доделать!
        }
        if (cw->count_live >= NBR_LIVE)
            cw->c_to_die = cw->c_to_die - CYCLE_DELTA;
        
        prev_car = curren_car;
        curren_car = curren_car->next;
    }
}

void    ft_start_game(t_cw *cw)
{
    t_crg *lst;

    while (cw->crg != NULL)
    {
        if (cw->c_to_die > 0)
        {
            lst = cw->crg;
            while (cw->round < cw->c_to_die)
            {
                ft_do_cycle(cw, lst);
                cw->round++;  
            }
        }
        else // конец игры ?
        {
            ft_do_cycle(cw, lst);
            cw->round++;
        }
        ft_check(cw);
    }
}