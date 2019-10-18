/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chrcnt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdraugr- <cdraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 16:15:50 by cdraugr-          #+#    #+#             */
/*   Updated: 2019/09/08 16:40:29 by cdraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_chrcnt(char *s, char ch)
{
	int32_t	count;

	count = 0;
	if (s)
		while (*s)
			count = *s++ == ch ? count + 1 : count;
	return (count);
}
