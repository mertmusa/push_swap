/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtemel <mtemel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 15:45:24 by mtemel            #+#    #+#             */
/*   Updated: 2022/10/22 03:33:17 by mtemel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*strrev(char *c)
{
	int		i;
	int		j;
	char	temp;

	j = ft_strlen(c) - 1;
	i = 0;
	temp = 0;
	while (i < j)
	{
		temp = c [i];
		c[i] = c[j];
		c[j] = temp;
		i++;
		j--;
	}
	return (c);
}
