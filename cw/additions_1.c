/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additions_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waddam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 19:59:05 by waddam            #+#    #+#             */
/*   Updated: 2019/09/29 20:37:48 by waddam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

static void	ft_swap_char(char *a, char *b)
{
	char	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void		ft_byte_reverse(char *bytes_array)
{
	ft_swap_char(&bytes_array[0], &bytes_array[3]);
	ft_swap_char(&bytes_array[1], &bytes_array[2]);
}