/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waddam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 13:41:19 by waddam            #+#    #+#             */
/*   Updated: 2018/12/16 18:49:59 by waddam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_delimiter(char a, char c)
{
	return (a == c ? 1 : 0);
}

static size_t	ft_words(char *s, char c)
{
	int		flag;
	size_t	words;

	flag = 0;
	words = 0;
	while (*s)
	{
		if (ft_delimiter(*s, c) == 1)
		{
			flag = 0;
			s++;
		}
		else
		{
			if (flag == 0)
				words++;
			flag = 1;
			s++;
		}
	}
	return (words);
}

static size_t	ft_characters(char *s, char c)
{
	size_t	len;

	len = 0;
	while ((ft_delimiter(*s, c) == 0) && *s)
	{
		len++;
		s++;
	}
	return (len);
}

static int		ft_allocate(size_t j, char **array, size_t len)
{
	if (!(array[j] = (char *)malloc(sizeof(char) * (len + 1))))
	{
		while (j > 0)
		{
			free(array[j - 1]);
			array[j - 1] = NULL;
			j--;
		}
		free(array);
		array = NULL;
		return (0);
	}
	else
		return (1);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**array;
	char	*temp;
	size_t	i;
	size_t	j;

	if (s == NULL)
		return (NULL);
	temp = (char *)s;
	i = 0;
	j = 0;
	if (!(array = (char **)malloc(sizeof(char *) * (ft_words(temp, c) + 1))))
		return (NULL);
	while (j < ft_words(temp, c))
	{
		while (ft_delimiter(temp[i], c) == 1)
			i++;
		if (!(ft_allocate(j, array, ft_characters(&temp[i], c))))
			return (NULL);
		ft_strncpy(array[j], &temp[i], ft_characters(&temp[i], c));
		array[j][ft_characters(&temp[i], c)] = '\0';
		i += ft_characters(&temp[i], c);
		j++;
	}
	array[j] = NULL;
	return (array);
}
