/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waddam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 18:23:37 by waddam            #+#    #+#             */
/*   Updated: 2018/12/12 18:23:46 by waddam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_len(char const *s)
{
	size_t	count;
	size_t	len;

	count = 0;
	len = ft_strlen(s);
	while ((*s == ' ') || (*s == '\n') || (*s == '\t'))
	{
		s++;
		count++;
	}
	while (*s)
		s++;
	s--;
	while ((*s == ' ') || (*s == '\n') || (*s == '\t'))
	{
		s--;
		count++;
		if (count > len)
			return (0);
	}
	len = len - count;
	return (len);
}

char			*ft_strtrim(char const *s)
{
	char	*temp;
	size_t	len;
	size_t	temp_len;

	if (s == NULL)
		return (NULL);
	len = ft_len(s);
	temp_len = len;
	if (!(temp = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while ((*s == ' ') || (*s == '\n') || (*s == '\t'))
		s++;
	while (len > 0)
	{
		*temp++ = *s++;
		len--;
	}
	*temp = '\0';
	while (temp_len > 0)
	{
		temp_len--;
		temp--;
	}
	return (temp);
}
