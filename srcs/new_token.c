/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdraugr- <cdraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 21:58:26 by cdraugr-          #+#    #+#             */
/*   Updated: 2019/10/22 22:43:05 by cdraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	make_new_token(t_parser *parser)
{
	while (parser->file[parser->row][parser->column] &&
			ft_is_blank(parser->file[parser->row][parser->column]))
		++parser->column;
	if (!parser->file[parser->row][parser->column] ||
			is_comment_char(parser->file[parser->row][parser->column]))
		return ;
	// token parsing here ...
	++parser->row;
}
