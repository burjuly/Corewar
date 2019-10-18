/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_blank.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdraugr- <cdraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 11:50:35 by cdraugr-          #+#    #+#             */
/*   Updated: 2019/08/29 15:42:18 by cdraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_blank(char ch)
{
	if (ch == ' ' || ch == '\t' || ch == '\n')
		return (1);
	return (0);
}
