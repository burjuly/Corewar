/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdraugr- <cdraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 13:42:23 by cdraugr-          #+#    #+#             */
/*   Updated: 2019/10/23 13:41:17 by cdraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	ft_error(const char *message)
{
	ft_putstr_fd("\033[1;31m", 2);
	ft_putstr_fd(message, 2);
	ft_putendl_fd("\033[0m", 2);
	exit(1);
}

void	syntax_error(const size_t row, const size_t column)
{
	ft_putstr_fd("\033[1;31m", 2);
	ft_putstr_fd("ERROR: Invalid syntax at line #", 2);
	ft_putnbr_fd(row + 1, 2);
	ft_putstr_fd(" column #", 2);
	ft_putnbr_fd(column + 1, 2);
	ft_putendl_fd(".\033[0m", 2);
	exit(1);
}
