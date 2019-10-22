/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 13:37:55 by cdraugr-          #+#    #+#             */
/*   Updated: 2019/07/30 13:37:57 by cdraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_swap_str(char **str1, char **str2)
{
	char		*tmp;

	tmp = *str1;
	*str1 = *str2;
	*str2 = tmp;
}