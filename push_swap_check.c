/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtemel <mtemel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 15:47:50 by mtemel            #+#    #+#             */
/*   Updated: 2022/11/24 15:49:49 by mtemel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* is arguments number/digit */
int	is_arg_number(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (str[0] == '-')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

/* is in integer range */
int	is_arg_int_range(char *str)
{
	if ((ft_strlen(str) > 1 && ft_atoi(str) == 0)
		|| (ft_atoi(str) == -1 && ft_strlen(str) != 2))
		return (0);
	return (1);
}

/* check if there is a abnormal stuation with argumnets */
void	check_my_arg(char **argv)
{
	int	i;
	int	j;

	i = -1;
	while (argv[++i])
	{
		if (!is_arg_number(argv[i]))
			print_error("Arguments contain non digit characters!");
		if (!is_arg_int_range(argv[i]))
			print_error("Some arguments aren't in the integer range!");
		j = -1;
		while (++j < i)
		{
			if (ft_atoi(argv[j]) == ft_atoi(argv[i]))
				print_error("There are duplicates!");
		}
	}
}

/* this function checks if list sorted then exit */
void	checksorted(t_list **a)
{
	t_list	*temp;
	int		i;

	i = 0;
	temp = *a;
	while (temp->next != NULL)
	{
		if (temp->sequence > i)
			return ;
		i++;
		temp = temp->next;
	}
	exit(EXIT_SUCCESS);
}
