/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   name_comment.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdraugr- <cdraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 15:20:16 by cdraugr-          #+#    #+#             */
/*   Updated: 2019/10/22 17:22:05 by cdraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	new_name(t_parser *parser)
{
	parser->name = get_words_inside(parser);
	if (ft_strlen(parser->name) > PROG_NAME_LENGTH)
		ft_error("ERROR: So long name.");
}

void	new_comment(t_parser *parser)
{
	parser->comment = get_words_inside(parser);
	if (ft_strlen(parser->comment) > COMMENT_LENGTH)
		ft_error("ERROR: So long comment.");
}

void	new_name_or_comment(t_parser *parser)
{
	if (!ft_strncmp(&parser->file[parser->row][parser->column],
				NAME_CMD_STRING, ft_strlen(NAME_CMD_STRING)))
	{
		if (parser->name)
			syntax_error(parser->row, parser->column);
		parser->column += ft_strlen(NAME_CMD_STRING);
		new_name(parser);
	}
	else if (!ft_strncmp(&parser->file[parser->row][parser->column],
				COMMENT_CMD_STRING, ft_strlen(COMMENT_CMD_STRING)))
	{
		if (parser->comment)
			syntax_error(parser->row, parser->column);
		parser->column += ft_strlen(COMMENT_CMD_STRING);
		new_comment(parser);
	}
	else
		syntax_error(parser->row, parser->column);
	parser->flag = 1;
	++parser->column;
}

void	parse_name_and_comment(t_parser *parser)
{
	while (parser->file[parser->row])
	{
		while ((parser->file[parser->row][parser->column] == ' ' ||
				parser->file[parser->row][parser->column] == '\t') &&
				parser->file[parser->row][parser->column] != '\0')
			++parser->column;
		if (parser->file[parser->row][parser->column] == '\0' ||
				is_comment_char(parser->file[parser->row][parser->column]))
		{
			++parser->row;
			parser->column = 0;
			parser->flag = 0;
		}
		else if (parser->flag == 0 &&
				parser->file[parser->row][parser->column] == '.')
			new_name_or_comment(parser);
		else if (parser->name && parser->comment && !parser->flag)
			break ;
		else
			syntax_error(parser->row, parser->column);
	}
	if (!parser->name || !parser->comment)
		ft_error("ERROR: No name or comment.");
	++parser->row;
	parser->column = 0;
}
