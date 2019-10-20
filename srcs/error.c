/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdraugr- <cdraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 13:42:23 by cdraugr-          #+#    #+#             */
/*   Updated: 2019/10/20 18:18:57 by cdraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	ft_error(char *message)
{
	ft_putstr("\033[1;31m");
	ft_putstr(message);
	ft_putendl("\033[0m");
	exit(1);
}

void	syntax_error(int32_t row, int32_t column)
{
	ft_putstr("\033[1;31m");
	ft_putstr("ERROR: Invalid syntax at line #");
	ft_putnbr(row + 1);
	ft_putstr(" column #");
	ft_putnbr(column + 1);
	ft_putendl(".\033[0m");
	exit(1);
}
