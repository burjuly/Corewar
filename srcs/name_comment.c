/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   name_comment.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdraugr- <cdraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 15:20:16 by cdraugr-          #+#    #+#             */
/*   Updated: 2019/10/20 18:17:03 by cdraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	new_name_or_comment(char *str, t_parser *parser, int32_t position)
{
	(void)str;
	(void)parser;
	(void)position;
}

void	parse_name_and_comment(t_parser *parser)
{
	while(parser->file[parser->row])
	{
		while ((parser->file[parser->row][parser->column] == ' ' ||
			parser->file[parser->row][parser->column] == '\t') &&
			parser->file[parser->row][parser->column] != '\0')
			++parser->column;
		if (parser->file[parser->row][parser->column] == '\0' ||
			parser->file[parser->row][parser->column] == COMMENT_CHAR ||
			parser->file[parser->row][parser->column] == ALT_COMMENT_CHAR)
		{
			++parser->row;
			parser->column = 0;
			parser->flag = 0;
		}
		else if (parser->flag == 0 && parser->file[parser->row][parser->column] == '.')
		{
			new_name_or_comment(&parser->file[parser->row][parser->column],
								parser, parser->column);
			parser->flag = 1;
		}
		else if (parser->name && parser->comment && !parser->flag)
			break ;
		else
			syntax_error(parser->row, parser->column);
	}
	if (!parser->name || !parser->comment)
		ft_error("ERROR: No name or comment.");
}
