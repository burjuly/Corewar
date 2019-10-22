/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdraugr- <cdraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 15:31:48 by cdraugr-          #+#    #+#             */
/*   Updated: 2019/10/22 15:36:42 by cdraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	parse(t_parser *parser)
{
	read_file(parser);
	parse_name_and_comment(parser);
	// ...
	ft_putstr("Name: ");
	ft_putendl(parser->name);
	ft_putstr("Comment: ");
	ft_putendl(parser->comment);
}