/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   name_comment.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdraugr- <cdraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 15:20:16 by cdraugr-          #+#    #+#             */
/*   Updated: 2019/10/20 22:15:38 by cdraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	new_name(char *str, t_parser *parser, int32_t position)
{
	char	*name;
	size_t	lenght;

	name = get_words_inside(str, parser, position);
	lenght = ft_strlen(name);
	if (lenght > PROG_NAME_LENGTH)
		ft_error("ERROR: So long name.");
	parser->name = name;
}

void	new_comment(char *str, t_parser *parser, int32_t position)
{
	char	*comment;
	size_t	lenght;

	comment = get_words_inside(str, parser, position);
	lenght = ft_strlen(comment);
	if (lenght > COMMENT_LENGTH)
		ft_error("ERROR: So long comment.");
	parser->comment = comment;

}

void	new_name_or_comment(char *str, t_parser *parser, int32_t position)
{
	if (!ft_strncmp(str, NAME_CMD_STRING, ft_strlen(NAME_CMD_STRING)))
	{
		if (parser->name)
			syntax_error(parser->row, position);
		new_name(str + ft_strlen(NAME_CMD_STRING), parser, position);
	}
	else if (!ft_strncmp(str, COMMENT_CMD_STRING, ft_strlen(COMMENT_CMD_STRING)))
	{
		if (parser->comment)
			syntax_error(parser->row, position);
		new_comment(str + ft_strlen(COMMENT_CMD_STRING), parser, position);
	}
	else
		syntax_error(parser->row, position);
	parser->flag = 0;
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
