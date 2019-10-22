/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdraugr- <cdraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 15:20:45 by cdraugr-          #+#    #+#             */
/*   Updated: 2019/10/22 16:51:49 by cdraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		check_end_line(char *str)
{
	size_t	index;
	size_t	count;

	index = ft_strlen(str);
	count = 0;
	while (index > 0 && (ft_is_blank(str[index]) || str[index] == '\0'))
	{
		if (str[index] == '\n')
			++count;
		--index;
	}
	if (count == 0)
		ft_error("ERROR: No new line in the end of file.");
	if (index == 0 && ft_is_blank(str[index]))
		ft_error("ERROR: No data in file.");
}

void		read_file(t_parser *parser)
{
	char	buf[100];
	char	*tmp;
	char	*file;
	ssize_t	index;

	file = ft_strnew(0);
	while ((index = read(parser->fd, buf, 99)) > 0)
	{
		buf[index] = '\0';
		tmp = file;
		file = ft_strjoin(file, buf);
		free(tmp);
	}
	check_end_line(file);
	parser->file = ft_strsplit_n(file, '\n');
	free(file);
}
