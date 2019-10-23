/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdraugr- <cdraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 16:10:58 by cdraugr-          #+#    #+#             */
/*   Updated: 2019/10/23 17:08:42 by cdraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int32_t		is_comment_char(const int c)
{
	return (c == COMMENT_CHAR || c == ALT_COMMENT_CHAR);
}

int32_t		is_label(t_parser *parser, char *str)
{
	int32_t	index;
	int32_t	lenght;

	index = -1;
	lenght = ft_strlen(str) - 1;
	if (str[lenght] == LABEL_CHAR)
	{
		while (++index < lenght)
			if (!ft_strrchr(LABEL_CHARS, str[index]))
				syntax_error(parser->row, parser->column + index);
		return (1);
	}
	return (0);
}

char		*check_oper(char *given_str, size_t *column)
{
	char	*str;
	int32_t	index;
	int		flag;

	flag = 0;
	index = -1;
	while (given_str[++index])
	{
		if (given_str[index] == DIRECT_CHAR)
		{
			flag = 1;
			break ;
		}
	}
	if (flag)
	{
		str = ft_strnew(index);
		ft_strncpy(str, given_str, index);
		*column -= (ft_strlen(given_str) - ft_strlen(str));
	}
	else
		str = ft_strdup(given_str);
	return (str);
}

int32_t		is_operation(t_parser *parser, char *given_str, size_t column)
{
	int32_t	op;
	char	*str;

	str = check_oper(given_str, &column);
	op = 0;
	if (!str)
		syntax_error(parser->row, parser->column);
	while (g_op[op].name != NULL)
	{
		if (ft_strcmp(g_op[op].name, str) == 0)
		{
			add_token(parser, OPERATOR, str);
			parser->tokens->data = op;
			parser->op = op;
			parser->arg = 0;
			parser->tokens->bytes = parser->bytes;
			parser->bytes += 1 + (g_op[parser->op].args_types_code ? 1 : 0);
			ft_strdel(&str);
			return (column);
		}
		++op;
	}
	ft_strdel(&str);
	syntax_error(parser->row, parser->column);
	return (0);
}

int32_t		label_or_comand(t_parser *parser, char *str, size_t *column)
{
	if (is_label(parser, str))
	{
		add_label_token(parser, str);
		return (1);
	}
	else
	{
		*column = is_operation(parser, str, *column);
		return (0);
	}
}
