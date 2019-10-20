/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_words.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdraugr- <cdraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 21:46:52 by cdraugr-          #+#    #+#             */
/*   Updated: 2019/10/20 22:19:15 by cdraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char	*get_words_inside(char *str, t_parser *parser, int32_t position)
{
	char	*words;

	words = ft_strnew(0);
	while (*str && ft_is_blank(*str))
		++str;
	if (*str != '"')
		syntax_error(parser->row, position);
	// ...
	return (words);
}
