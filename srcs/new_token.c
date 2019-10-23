/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdraugr- <cdraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 21:58:26 by cdraugr-          #+#    #+#             */
/*   Updated: 2019/10/23 15:49:04 by cdraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		skip_to_text(t_parser *parser)
{
	while (parser->file[parser->row + 1] &&
			(!parser->file[parser->row][parser->column] ||
			is_comment_char(parser->file[parser->row][parser->column])))
	{
		++parser->row;
		parser->column = 0;
		while (parser->file[parser->row][parser->column] &&
				ft_is_blank(parser->file[parser->row][parser->column]))
			++parser->column;
	}
}

void		create_token(t_parser *parser, size_t *column, int32_t *label)
{
	char	*str;

	while (parser->file[parser->row][*column] &&
			!ft_is_blank(parser->file[parser->row][*column]))
		++(*column);
	str = ft_strsub(parser->file[parser->row], parser->column,
					*column - parser->column);
	parser->flag = label_or_comand(parser, str, column);
	if (parser->flag == 1)
		++(*label);
	if (*label > 1)
		parser->flag = 0;
	while (parser->file[parser->row][*column] &&
			ft_is_blank(parser->file[parser->row][*column]))
		++(*column);
	ft_strdel(&str);
}

void		make_new_token(t_parser *parser)
{
	size_t	column;
	int32_t	label;

	while (parser->file[parser->row][parser->column] &&
			ft_is_blank(parser->file[parser->row][parser->column]))
		++parser->column;
	if (!parser->file[parser->row][parser->column] ||
			is_comment_char(parser->file[parser->row][parser->column]))
		return ;
	parser->flag = 1;
	while (parser->flag != 0)
	{
		skip_to_text(parser);
		if (!parser->file[parser->row][parser->column] ||
				is_comment_char(parser->file[parser->row][parser->column]))
			return ;
		column = parser->column;
		label = 0;
		create_token(parser, &column, &label);
		parser->column = column;
	}
	parse_args(parser, parser->column, 0, 0);
}
