/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdraugr- <cdraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 15:53:16 by cdraugr-          #+#    #+#             */
/*   Updated: 2019/10/23 16:17:48 by cdraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		valid_arg(t_parser *parser, t_token *token)
{
	int32_t	arg_type;
	int32_t	mask;
	int32_t	start;

	start = parser->bytes;
	mask = g_op[parser->op].args_types[parser->arg];
	arg_type = token->type;
	if (token->type == DIRECT_LABEL)
		arg_type = T_DIR;
	else if (token->type == INDIRECT_LABEL)
		arg_type = T_IND;
	if (arg_type != (arg_type & mask))
		syntax_error(parser->row, parser->column);
	if (arg_type == T_REG)
		++parser->bytes;
	else if (arg_type == T_IND)
	{
		parser->bytes += IND_SIZE;
		token->bytes = start;
	}
	else if (arg_type == T_DIR)
	{
		parser->bytes += g_op[parser->op].t_dir_size;
		token->bytes = start;
	}
}

void		is_registry(char *string, t_parser *parser)
{
	int32_t	i;

	i = 1;
	if (!(ft_isdigit(string[0]) && (ft_isdigit(string[1]) || string[1] == ' '
			|| string[1] == '\t' || string[1] == '\0')))
		syntax_error(parser->row, parser->column);
	while (string[i] != '\0' && string[++i])
		if (string[i] != '\t' && string[i] != ' ')
			syntax_error(parser->row, parser->column + i);
	if (ft_atoi(string) == 0)
		syntax_error(parser->row, parser->column + i);
	add_token(parser, REGISTER, string);
	parser->tokens->data = ft_atoi(string);
}

void		is_indir_dir_label(char *string, t_parser *parser, t_type type)
{
	int32_t	i;
	char	*str;

	i = -1;
	while (string[++i] && string[i] != '\t' && string[i] != ' ')
		if (ft_strchr(LABEL_CHARS, string[i]) == NULL)
			syntax_error(parser->row, parser->column + ++i);
	i--;
	while (string[++i])
		if (string[i] != ' ' && string[i] != '\t')
			syntax_error(parser->row, parser->column + i);
	i = 0;
	while (string[i] && string[i] != '\t' && string[i] != ' ')
		i++;
	str = ft_strsub(string, 0, i);
	add_token(parser, type, str);
	free(str);
}

void		is_dir_or_indir(char *string, t_parser *parser, t_type type)
{
	int32_t	i;

	i = -1;
	if (string[0] == '-')
		i = 0;
	if (string[0] == LABEL_CHAR && type == DIRECT)
		is_indir_dir_label(&string[1], parser, DIRECT_LABEL);
	else
	{
		while (string[++i] && string[i] != ' ' && string[i] != '\t')
			if (ft_isdigit(string[i]) == 0)
				syntax_error(parser->row, parser->column + i);
		while (string[i] != '\0' && string[++i])
			if (string[i] != '\t' && string[i] != ' ')
				syntax_error(parser->row, parser->column + i);
		add_token(parser, type, string);
		parser->tokens->data = ft_atoi(string);
	}
}

void		check_args(char *string, t_parser *parser)
{
	int32_t	i;

	i = 0;
	while (parser->file[parser->row][i] &&
			ft_is_blank(string[i]))
		++i;
	if (string[i] == REG_CHAR)
		is_registry(&string[++i], parser);
	else if (string[i] == DIRECT_CHAR)
		is_dir_or_indir(&string[++i], parser, DIRECT);
	else if (ft_isdigit(string[i]) || (string[i] == '-' &&
			ft_isdigit(string[i + 1])))
		is_dir_or_indir(&string[i], parser, INDIRECT);
	else if (string[i] == LABEL_CHAR)
		is_indir_dir_label(&string[++i], parser, INDIRECT_LABEL);
	else
		syntax_error(parser->row, parser->column);
	valid_arg(parser, parser->tokens);
	++parser->arg;
}
