/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdraugr- <cdraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 15:31:48 by cdraugr-          #+#    #+#             */
/*   Updated: 2019/10/23 13:14:20 by cdraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	parse_code(t_parser *parser)
{
	while (parser->file[parser->row])
	{
		while (parser->file[parser->row] &&
			(!parser->file[parser->row][parser->column] ||
			is_comment_char(parser->file[parser->row][parser->column])))
		{
			++parser->row;
			parser->column = 0;
		}
		if (parser->file[parser->row])
			make_new_token(parser);
	}
}

void	parse(t_parser *parser)
{
	read_file(parser);
	parse_name_and_comment(parser);
	parse_code(parser);
}
