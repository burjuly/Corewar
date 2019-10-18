/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdraugr- <cdraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 13:19:00 by cdraugr-          #+#    #+#             */
/*   Updated: 2019/09/22 17:46:21 by cdraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char			*ft_readline(const int32_t fd, char *buff, int32_t *ret)
{
	char			array[BUFF_SIZE + 1];
	char			*tmp;

	if ((*ret = read(fd, array, BUFF_SIZE)) == -1)
		return (0);
	array[*ret] = '\0';
	tmp = buff;
	if (!buff)
		buff = ft_strdup(array);
	else if (!(buff = ft_strjoin(buff, array)))
	{
		ft_strdel(&tmp);
		return (NULL);
	}
	ft_strdel(&tmp);
	return (buff);
}

static int32_t		ft_error(char **line, char **buff)
{
	if (!(*line = ft_strdup(*buff)))
		return (-1);
	ft_bzero(*buff, ft_strlen(*buff));
	return (1);
}

static int32_t		ft_assist(char **buff, char **str, char ***line)
{
	**str = '\0';
	*str = ft_strdup(*str + 1);
	if (!(**line = ft_strdup(*buff)))
		return (-1);
	ft_strdel(buff);
	*buff = *str;
	return (1);
}

int32_t				get_next_line(const int32_t fd, char **line)
{
	static char		*buff = 0;
	char			*str;
	int32_t			ret;

	ret = 1;
	str = 0;
	if (!line || fd < 0)
		return (-1);
	while (ret > 0)
	{
		if (buff && (str = ft_strchr(buff, '\n')) != NULL)
			return (ft_assist(&buff, &str, &line));
		if (!(buff = ft_readline(fd, buff, &ret)))
			return (-1);
	}
	ft_strdel(&str);
	if (ret == 0 && ft_strlen(buff))
		return (ft_error(&(*line), &buff));
	return (ret);
}
