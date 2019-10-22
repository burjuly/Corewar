/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_words.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdraugr- <cdraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 21:46:52 by cdraugr-          #+#    #+#             */
/*   Updated: 2019/10/22 17:49:42 by cdraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

size_t	get_lenght(const t_parser *parser, size_t row, size_t column)
{
	size_t	lenght;

	lenght = 0;
	while (parser->file[row] && parser->file[row][column] != '"')
	{
		while (parser->file[row][column] && parser->file[row][column] != '"')
		{
			++lenght;
			++column;
		}
		if (parser->file[row][column] != '"')
		{
			++lenght;
			++row;
			column = 0;
		}
	}
	if (!parser->file[row] || parser->file[row][column] != '"')
		syntax_error(row, column);
	return (lenght);
}

void	get_symbols(t_parser *parser, char **words)
{
	char	*tmp;

	tmp = *words;
	while (parser->file[parser->row][parser->column] != '"')
	{
		while (parser->file[parser->row][parser->column] &&
				parser->file[parser->row][parser->column] != '"')
		{
			*tmp = parser->file[parser->row][parser->column];
			++tmp;
			++parser->column;
		}
		if (parser->file[parser->row][parser->column] != '"')
		{
			*tmp = '\n';
			++tmp;
			++parser->row;
			parser->column = 0;
		}
	}
}

char	*get_words_inside(t_parser *parser)
{
	char	*words;

	while (parser->file[parser->row][parser->column] &&
			ft_is_blank(parser->file[parser->row][parser->column]))
		++parser->column;
	if (parser->file[parser->row][parser->column] != '"')
		syntax_error(parser->row, parser->column);
	++parser->column;
	words = ft_strnew(get_lenght(parser, parser->row, parser->column));
	get_symbols(parser, &words);
	return (words);
}
