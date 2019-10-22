/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdraugr- <cdraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 12:10:39 by cdraugr-          #+#    #+#             */
/*   Updated: 2019/10/22 16:46:32 by cdraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_count_words(char const *s, char c)
{
	size_t		words;

	words = 0;
	while (*s)
	{
		while (*s && *s == c)
			++s;
		if (*s)
		{
			++words;
			while (*s && *s != c)
				++s;
		}
	}
	return (words);
}
