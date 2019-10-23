/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdraugr- <cdraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 14:52:31 by cdraugr-          #+#    #+#             */
/*   Updated: 2019/10/23 17:12:59 by cdraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	next_parse_args(t_parser *pars, int i)
{
	while (pars->file[pars->row][i] &&
			ft_is_blank(pars->file[pars->row][i]))
		++i;
	if (pars->file[pars->row][i] &&
			!is_comment_char(pars->file[pars->row][i]))
		syntax_error(pars->row, pars->column);
	++pars->row;
	pars->column = 0;
	add_token(pars, NEW_LINE, NULL);
}

void	param_count(t_parser *pars, int32_t args, int32_t *i)
{
	if (args != g_op[pars->op].args_num)
		syntax_error(pars->row, pars->column);
	--(*i);
}

void	parse_args(t_parser *par, int32_t i, int32_t args, size_t column)
{
	char	*string;

	while (par->file[par->row][column] &&
			!is_comment_char(par->file[par->row][column]))
		++column;
	while (par->file[par->row][par->column] && par->column < column)
	{
		if (args >= g_op[par->op].args_num)
			break ;
		while (par->file[par->row][i] != SEPARATOR_CHAR &&
				par->file[par->row][i] && !ft_is_blank(par->file[par->row][i])
				&& !is_comment_char(par->file[par->row][i]))
			++i;
		string = ft_strsub(par->file[par->row], par->column, i - par->column);
		check_args(string, par);
		++args;
		++i;
		while (par->file[par->row][i] && ft_is_blank(par->file[par->row][i]))
			++i;
		par->column = i;
		ft_strdel(&string);
	}
	par->column > column ? par->column = column : par->column;
	param_count(par, args, &i);
	next_parse_args(par, i);
}
