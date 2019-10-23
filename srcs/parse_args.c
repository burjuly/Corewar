/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdraugr- <cdraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 14:52:31 by cdraugr-          #+#    #+#             */
/*   Updated: 2019/10/23 16:18:36 by cdraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	next_parse_args(t_parser *parser, int i)
{
	while (parser->file[parser->row][i] &&
			ft_is_blank(parser->file[parser->row][i]))
		++i;
	if (parser->file[parser->row][i] &&
			!is_comment_char(parser->file[parser->row][i]))
		syntax_error(parser->row, parser->column);
	++parser->row;
	parser->column = 0;
	add_token(parser, NEW_LINE, NULL);
}

void	param_count(t_parser *parser, int32_t args, int32_t *i)
{
	if (args != g_op[parser->op].args_num)
		syntax_error(parser->row, parser->column);
	--(*i);
}

void	parse_args(t_parser *parser, int32_t i, int32_t args, size_t column)
{
	char	*string;

	while (parser->file[parser->row][column] &&
			!is_comment_char(parser->file[parser->row][column]))
		++column;
	while (parser->file[parser->row][parser->column] && parser->column < column)
	{
		if (args >= g_op[parser->op].args_num)
			break ;
		while (parser->file[parser->row][i] &&
				parser->file[parser->row][i] != SEPARATOR_CHAR &&
				!ft_is_blank(parser->file[parser->row][i]) &&
				!is_comment_char(parser->file[parser->row][i]))
			++i;
		string = ft_strsub(parser->file[parser->row], parser->column, i - parser->column);
		check_args(string, parser);
		++args;
		++i;
		while (parser->file[parser->row][i] && ft_is_blank(parser->file[parser->row][i]))
			++i;
		parser->column = i;
		ft_strdel(&string);
	}
	parser->column > column ? parser->column = column : parser->column;
	param_count(parser, args, &i);
	next_parse_args(parser, i);
}
